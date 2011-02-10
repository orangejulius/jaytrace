#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QImage>

#include "Angle.h"
#include "Config.h"
#include "IntersectionLibrary.h"
#include "Scene.h"

class Color;

class Raytracer
{
public:
	Raytracer(unsigned int width = 640, unsigned int height = 480, Angle projectionAngle = Angle::degrees(25));

	void setScene(ScenePointer newScene);

	void resize(unsigned int width, unsigned int height);
	void setConfig(ConfigPointer newConfig);

	QImage render();

private:
	Color rayColor(Ray ray);
	bool shadowFeeler(Ray ray);

	IntersectionLibrary intersectionLibrary;

	unsigned int width;
	unsigned int height;
	double aspectRatio;
	Angle projectionAngle;

	ConfigPointer config;
	ScenePointer scene;
};

#endif // RAYTRACERENDERER_H
