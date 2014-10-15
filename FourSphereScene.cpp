#include "FourSphereScene.h"

#include "MaterialNode.h"
#include "TranslationNode.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "Sphere.h"



FourSphereScene::FourSphereScene()
{
	setupCamera();
	setupObjects();
	setupLights();
}

void FourSphereScene::setupCamera()
{

}

void FourSphereScene::setupObjects()
{
	Color white(1, 1, 1);

	NodePointer t1(new TranslationNode(0, 3, -20));
	MaterialNodePointer m1(new MaterialNode(t1));
	Color m1Color(.5, .2, .2);
	m1->setAmbient(m1Color * .25);
	m1->setDiffuse(m1Color);
	m1->setSpecular(white);
	m1->setShininess(10);
	RayObjectPointer s1(new Sphere(m1));

	NodePointer t2(new TranslationNode(0, 0, -20));
	NodePointer sc1(new ScalingNode(2, 2, 2, t2));
	MaterialNodePointer m2(new MaterialNode(sc1));
	Color m2Color(.7, .7, .7);
	m2->setAmbient(m2Color * .1);
	m2->setDiffuse(white * .6);
	m2->setSpecular(white * .9);
	m2->setShininess(20);
	RayObjectPointer s2(new Sphere(m2));

	NodePointer t3(new TranslationNode(3, 0, -20));
	MaterialNodePointer m3(new MaterialNode(t3));
	Color m3Color(.3, .5, .3);
	m3->setAmbient(m3Color * .25);
	m3->setDiffuse(m3Color);
	m3->setSpecular(white);
	m3->setShininess(30);
	RayObjectPointer s3(new Sphere(m3));

	NodePointer t4(new TranslationNode(-3, 0, -20));
	MaterialNodePointer m4(new MaterialNode(t4));
	Color m4Color(.3, .3, .7);
	m4->setAmbient(m4Color * .25);
	m4->setDiffuse(m4Color);
	m4->setSpecular(white);
	m4->setShininess(30);
	RayObjectPointer s4(new Sphere(m4));

	NodePointer t5(new TranslationNode(0, -3, -20));
	MaterialNodePointer m5(new MaterialNode(t5));
	Color m5Color(.5, .2, .5);
	m5->setAmbient(m5Color * .25);
	m5->setDiffuse(m5Color);
	m5->setSpecular(white);
	m5->setShininess(30);
	RayObjectPointer s5(new Sphere(m5));

	addObject(s1);
	addObject(s2);
	addObject(s3);
	addObject(s4);
	addObject(s5);
}

void FourSphereScene::setupLights()
{
	LightPointer l1(new Light(Vector3d(-3, 12, -15), 0));
	Color white(1, 1, 1);
	l1->setAmbient(white);
	l1->setDiffuse(white);
	l1->setSpecular(white);
	addLight(l1);

	LightPointer l2(new Light(Vector3d(10, 10, -17), 0));
	Color purple(.62, .12, .94);
	l2->setDiffuse(purple);
	l2->setSpecular(purple);
	addLight(l2);
}
