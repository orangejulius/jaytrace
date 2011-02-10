#include "Raytracer.h"

#include "Material.h"
#include "Poisson.h"
#include "Ray.h"

Raytracer::Raytracer(unsigned int width, unsigned int height, Angle projectionAngle): width(width), height(height), projectionAngle(projectionAngle)
{
	aspectRatio = (double)width/height;
}

void Raytracer::setScene(ScenePointer newScene)
{
	scene = newScene;
	intersectionLibrary.clear();
	intersectionLibrary.addObjects(scene->getObjects());
}

void Raytracer::resize(unsigned int newWidth, unsigned int newHeight)
{
	width = newWidth;
	height = newHeight;
	aspectRatio = (double)width/height;
}

void Raytracer::setConfig(ConfigPointer newConfig)
{
	config = newConfig;
}

QImage Raytracer::render()
{
	float yMin = -tan(projectionAngle.getRadians()/2);
	float yHeight = -2 * yMin;

	float xMin = aspectRatio * yMin;
	float xWidth = -2 * xMin;

	QImage image(width, height, QImage::Format_RGB32);

	image.fill(0xff000000);

	for (unsigned int row = 0; row < height; row++) {
		for (unsigned int col = 0; col < width; col++) {
			Color pixelColor(0,0,0);
			unsigned int aaSamples = 4;
			Poisson poisson(aaSamples);
			for (unsigned int aa = 0; aa < aaSamples; aa++) {
				Vector2d offset(.5,.5);
				if (aa > 0) {
					offset = poisson.generate();
				}

				float x = xMin + (col + offset.x()) / width * xWidth;
				float y = yMin + ((height - row) + offset.y()) / height * yHeight;
				float z = -1;

				Vector3d origin(0, 0, 0);
				Vector3d direction(x, y, z);
				direction.normalize();

				Ray pixelRay(origin, direction);
				pixelColor = pixelColor + rayColor(pixelRay);
			}

			pixelColor = pixelColor * (1./aaSamples);
			image.setPixel(col, row, pixelColor.getARGB());
		}
	}
	return image;
}

Color Raytracer::rayColor(Ray ray)
{
	IntersectionInfo* info = intersectionLibrary.intersect(ray);
	Color totalColor(0, 0, 0);
	if (!info) {
		return totalColor;
	}
	Material objectMaterial = info->object->getMaterial();

	list<LightPointer> lights = scene->getLights();
	list<LightPointer>::iterator light;
	for (light = lights.begin(); light != lights.end(); light++) {
		//first compute ambient lighting
		totalColor += (*light)->getAmbient() * objectMaterial.getAmbient();

		//calculate the direction to the light
		Vector3d lightVector = (*light)->getLightVector(ray.getPosition(info->time));

		//don't add any light if this point is in a shadow
		Ray lightRay(ray.getPosition(info->time), lightVector);
		if (!shadowFeeler(lightRay)) {
			continue;
		}

		double LdotN = lightVector.dot(info->normal);

		if (LdotN > 0) {
			totalColor += (*light)->getDiffuse() * objectMaterial.getDiffuse() * LdotN;

			Vector3d halfVector = lightVector - ray.getDirection();
			halfVector.normalize();

			double HdotN = halfVector.dot(info->normal);
			double sif = pow(HdotN, objectMaterial.getShininess());

			if (sif > 0) {
				totalColor += (*light)->getSpecular() * objectMaterial.getSpecular() * sif;
			}
		}
	}

	//reflection from other objects
	Vector3d rayDirection = ray.getDirection();
	Vector3d reflectionVector = rayDirection - 2*(rayDirection.dot(info->normal)) * info->normal;
	Ray reflectionRay(ray.getPosition(info->time), reflectionVector);
	Color reflectionColor = rayColor(reflectionRay);
	totalColor += reflectionColor * objectMaterial.getSpecular();

	delete info;

	return totalColor;
}

bool Raytracer::shadowFeeler(Ray ray)
{
	IntersectionInfo* info = intersectionLibrary.intersect(ray);

	if (info == 0) {
		return true;
	} else {
		delete info;
		return false;
	}
}
