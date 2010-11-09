#ifndef RAYTRACERENDERER_H
#define RAYTRACERENDERER_H

#include <QImage>

#include "IntersectionLibrary.h"
#include "Renderer.h"

class RaytraceRenderer: public Renderer
{
public:
	RaytraceRenderer();
	~RaytraceRenderer();

	QImage render();

private:
	Color rayColor(Ray ray);
	bool shadowFeeler(Ray ray);
	IntersectionLibrary intersectionLibrary;
	QImage image;
};

#endif // RAYTRACERENDERER_H
