#include "RaytraceRenderer.h"
#include "MaterialNode.h"
#include "TranslationNode.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "Sphere.h"

#include <cmath>
#include <QDate>

int main()
{
	RaytraceRenderer raytraceRenderer;

	int numSpheres = 100;
	double sphereScaling = .6;
	Angle angleBetweenSpheres = Angle::degrees(25);
	double depthBetweenSpheresBase = 1.2;
	double depthBetweenSpheresMultiple = 1.10;
	int firstSphereDepth = 10;
	double radius = 2;

	MaterialNodePointer material(new MaterialNode);
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
		raytraceRenderer.addObject(sphere);
		double depthBetweenSpheres = depthBetweenSpheresBase * pow(depthBetweenSpheresMultiple, i);
		lastDepthTranslation = NodePointer(new TranslationNode(0,0, -depthBetweenSpheres, lastDepthTranslation));
	}

	LightPointer l1(new Light(Vector3d(-3,12,-15),0));
	l1->setAmbient(white*.2);
	l1->setDiffuse(white);
	l1->setSpecular(white);
	raytraceRenderer.addLight(l1);

	LightPointer l2(new Light(Vector3d(-10,10,-15),0));
	Color l2Color(.3,.8,.3);
	l2->setDiffuse(l2Color*.8);
	l2->setSpecular(l2Color);
	raytraceRenderer.addLight(l2);

	LightPointer l3(new Light(Vector3d(10,10,-50),0));
	Color l3Color(.3,.3,.8);
	l3->setDiffuse(l3Color*.9);
	l3->setSpecular(l3Color);
	raytraceRenderer.addLight(l3);

	LightPointer l4(new Light(Vector3d(0,0,-100),0));
	Color l4Color(.8,.3,.3);
	l4->setDiffuse(l4Color*.9);
	l4->setSpecular(l4Color);
	raytraceRenderer.addLight(l4);

	QImage output = raytraceRenderer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
