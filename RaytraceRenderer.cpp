#include "RaytraceRenderer.h"

#include "Raytracer.h"

RaytraceRenderer::RaytraceRenderer()
{

}

RaytraceRenderer::~RaytraceRenderer()
{

}

QImage RaytraceRenderer::render()
{
	Raytracer raytracer(width, height, projectionAngle);

	for (list<RayObjectPointer>::iterator it = objects.begin(); it != objects.end(); it++) {
		raytracer.addObject(*it);
	}

	for (list<LightPointer>::iterator it = lights.begin(); it != lights.end(); it++) {
		raytracer.addLight(*it);
	}

	return raytracer.render();
}
