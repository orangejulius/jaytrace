#include "Scene.h"

#include "Angle.h"
#include "MaterialNode.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "Sphere.h"
#include "TranslationNode.h"

Camera Scene::getCamera() const
{
	return camera;
}

void Scene::setCamera(Camera c)
{
	camera = c;
}

void Scene::addObject(RayObjectPointer object)
{
	objects.push_back(object);

}

void Scene::addLight(LightPointer light)
{
	lights.push_back(light);
}

list<RayObjectPointer> Scene::getObjects() const
{
	return objects;
}

list<LightPointer> Scene::getLights() const
{
	return lights;
}

Scene Scene::getSpiralScene()
{
	Scene scene;
	int numSpheres = 100;
	double sphereScaling = .6;
	Angle angleBetweenSpheres = Angle::degrees(25);
	double depthBetweenSpheresBase = 1.2;
	double depthBetweenSpheresMultiple = 1.10;
	int firstSphereDepth = 10;
	double radius = 2;

	Vector3d eye(Vector3d(0, 0, 0));
	Vector3d look(Vector3d(0, 0, -100));
	Vector3d up(Vector3d(0, 1, 0));
	Camera camera(eye, look, up);
	scene.setCamera(camera);

	NodePointer rootNode(new TransformNode(camera.getTransform()));
	MaterialNodePointer material(new MaterialNode(rootNode));
	Color white(1,1,1);
	material->setAmbient(white*.1);
	material->setDiffuse(white*.5);
	material->setSpecular(white);
	material->setShininess(20);

	NodePointer firstDepthTranslation(new TranslationNode(0,0,-firstSphereDepth, material));

	NodePointer lastDepthTranslation = firstDepthTranslation;
	for (int i = 0; i < numSpheres; i++) {
		Angle rotationAngle = angleBetweenSpheres * i;
		NodePointer rotation(new RotationNode(rotationAngle, Vector3d::UnitZ(), lastDepthTranslation));
		NodePointer radiusTranslation(new TranslationNode(radius, 0, 0, rotation));
		NodePointer sphereScalingNode(new ScalingNode(sphereScaling, sphereScaling, sphereScaling, radiusTranslation));
		RayObjectPointer sphere(new Sphere(sphereScalingNode));
		scene.addObject(sphere);
		double depthBetweenSpheres = depthBetweenSpheresBase * pow(depthBetweenSpheresMultiple, i);
		lastDepthTranslation = NodePointer(new TranslationNode(0,0, -depthBetweenSpheres, lastDepthTranslation));
	}

	LightPointer l1(new Light(Vector3d(-3,12,-15),0));
	l1->setAmbient(white*.2);
	l1->setDiffuse(white);
	l1->setSpecular(white);
	scene.addLight(l1);

	LightPointer l2(new Light(Vector3d(-10,10,-15),0));
	Color l2Color(.3,.8,.3);
	l2->setDiffuse(l2Color*.8);
	l2->setSpecular(l2Color);
	scene.addLight(l2);

	LightPointer l3(new Light(Vector3d(10,10,-50),0));
	Color l3Color(.3,.3,.8);
	l3->setDiffuse(l3Color*.9);
	l3->setSpecular(l3Color);
	scene.addLight(l3);

	LightPointer l4(new Light(Vector3d(0,0,-100),0));
	Color l4Color(.8,.3,.3);
	l4->setDiffuse(l4Color*.9);
	l4->setSpecular(l4Color);
	scene.addLight(l4);

	return scene;
}
