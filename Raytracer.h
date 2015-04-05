#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QImage>

#include "Angle.h"
#include "IntersectionLibrary.h"
#include "Light.h"

class Color;

class Raytracer
{
public:
	Raytracer(unsigned int width, unsigned int height, unsigned int aaSamples, Angle projectionAngle);

	void addObject(RayObjectPointer object);
	void addLight(LightPointer light);

	QImage render();

private:
	Color rayColor(Ray ray);
	bool shadowFeeler(Ray ray);

	IntersectionLibrary intersectionLibrary;

	unsigned int width;
	unsigned int height;
	unsigned int aaSamples;
	double aspectRatio;
	Angle projectionAngle;

	list<LightPointer> lights;
};

#endif // RAYTRACERENDERER_H
