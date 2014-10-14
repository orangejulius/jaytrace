#include "RaytraceRenderer.h"

#include <Eigen/Core>
#include <QtDebug>

#include "Raytracer.h"

using Eigen::Vector3d;

RaytraceRenderer::RaytraceRenderer(unsigned int width, unsigned int height, Angle projectionAngle): Renderer(width, height, projectionAngle)
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
