#include "RaytraceRenderer.h"

#include <Eigen/Core>
#include <QtDebug>

#include "Raytracer.h"

using Eigen::Vector3d;

RaytraceRenderer::RaytraceRenderer(ScenePointer scene, unsigned int width, unsigned int height, unsigned int aaSamples, Angle projectionAngle): Renderer(scene, width, height, aaSamples, projectionAngle)
{

}

RaytraceRenderer::~RaytraceRenderer()
{

}

QImage RaytraceRenderer::render()
{
	Raytracer raytracer(width, height, aaSamples, projectionAngle);

	list<RayObjectPointer> objects = scene->getObjects();
	list<LightPointer> lights = scene->getLights();

	for (list<RayObjectPointer>::iterator it = objects.begin(); it != objects.end(); it++) {
		raytracer.addObject(*it);
	}

	for (list<LightPointer>::iterator it = lights.begin(); it != lights.end(); it++) {
		raytracer.addLight(*it);
	}

	return raytracer.render();
}
