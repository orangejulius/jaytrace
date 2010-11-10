#include "RaytraceRenderer.h"

#include <Eigen/Core>
#include <QtDebug>

#include "Material.h"
#include "Poisson.h"
#include "Ray.h"

using Eigen::Vector3d;

const float PI = 3.1415926535897932384626;

RaytraceRenderer::RaytraceRenderer()
{

}

RaytraceRenderer::~RaytraceRenderer()
{

}

QImage RaytraceRenderer::render()
{
	for (list<RayObjectPointer>::iterator it = objects.begin(); it != objects.end(); it++) {
		intersectionLibrary.addObject(*it);
	}

	float yMin = -tan(projectionAngle * PI / 360);
	float yHeight = -2 * yMin;

	float xMin = aspectRatio * yMin;
	float xWidth = -2 * xMin;

	image = QImage(width, height, QImage::Format_RGB32);

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

Color RaytraceRenderer::rayColor(Ray ray)
{
	IntersectionInfo* info = intersectionLibrary.intersect(ray);
	Color totalColor(0, 0, 0);
	if (!info) {
		return totalColor;
	}

	list<LightPointer>::iterator light;
	for (light = lights.begin(); light != lights.end(); light++) {
		Material objectMaterial = info->object->getMaterial();

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
	return totalColor;
}

bool RaytraceRenderer::shadowFeeler(Ray ray)
{
	IntersectionInfo* info = intersectionLibrary.intersect(ray);

	return info == 0;
}
