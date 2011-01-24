#ifndef RAYTRACERENDERER_H
#define RAYTRACERENDERER_H

#include <QImage>

#include "IntersectionLibrary.h"
#include "Renderer.h"

class RaytraceRenderer: public Renderer
{
public:
	RaytraceRenderer(unsigned int width = 640, unsigned int height = 480, Angle projectionAngle = Angle::degrees(25));
	~RaytraceRenderer();

	QImage render();

private:
	Color rayColor(Ray ray);
	bool shadowFeeler(Ray ray);
	IntersectionLibrary intersectionLibrary;
	QImage image;
};

#endif // RAYTRACERENDERER_H
