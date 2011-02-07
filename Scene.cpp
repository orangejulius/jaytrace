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

void Scene::addObject(SceneObjectPointer object)
{
	objects.push_back(object);

}

void Scene::addLight(LightPointer light)
{
	lights.push_back(light);
}

list<SceneObjectPointer> Scene::getObjects() const
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
		SceneObjectPointer sphere(new Sphere(sphereScalingNode));
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

Scene Scene::get4SphereScene()
{
	Scene scene;
	LightPointer l1(new Light(Vector3d(-3,12,-15),0));
	Color white(1,1,1);
	l1->setAmbient(white);
	l1->setDiffuse(white);
	l1->setSpecular(white);

	LightPointer l2(new Light(Vector3d(10,10,-17),0));
	Color purple(.62,.12,.94);
	l2->setDiffuse(purple);
	l2->setSpecular(purple);

	NodePointer t1(new TranslationNode(0,3,-20));
	MaterialNodePointer m1(new MaterialNode(t1));
	Color m1Color(.5,.2,.2);
	m1->setAmbient(m1Color*.25);
	m1->setDiffuse(m1Color);
	m1->setSpecular(white);
	m1->setShininess(10);
	SceneObjectPointer s1(new Sphere(m1));

	NodePointer t2(new TranslationNode(0,0,-20));
	NodePointer sc1(new ScalingNode(2,2,2,t2));
	MaterialNodePointer m2(new MaterialNode(sc1));
	Color m2Color(.7,.7,.7);
	m2->setAmbient(m2Color*.1);
	m2->setDiffuse(white* .6);
	m2->setSpecular(white*.9);
	m2->setShininess(20);
	SceneObjectPointer s2(new Sphere(m2));

	NodePointer t3(new TranslationNode(3,0,-20));
	MaterialNodePointer m3(new MaterialNode(t3));
	Color m3Color(.3,.5,.3);
	m3->setAmbient(m3Color*.25);
	m3->setDiffuse(m3Color);
	m3->setSpecular(white);
	m3->setShininess(30);
	SceneObjectPointer s3(new Sphere(m3));

	NodePointer t4(new TranslationNode(-3,0,-20));
	MaterialNodePointer m4(new MaterialNode(t4));
	Color m4Color(.3,.3,.7);
	m4->setAmbient(m4Color*.25);
	m4->setDiffuse(m4Color);
	m4->setSpecular(white);
	m4->setShininess(30);
	SceneObjectPointer s4(new Sphere(m4));

	NodePointer t5(new TranslationNode(0,-3,-20));
	MaterialNodePointer m5(new MaterialNode(t5));
	Color m5Color(.5,.2,.5);
	m5->setAmbient(m5Color*.25);
	m5->setDiffuse(m5Color);
	m5->setSpecular(white);
	m5->setShininess(30);
	SceneObjectPointer s5(new Sphere(m5));

	scene.addObject(s1);
	scene.addObject(s2);
	scene.addObject(s3);
	scene.addObject(s4);
	scene.addObject(s5);
	scene.addLight(l1);
	scene.addLight(l2);

	return scene;
}
