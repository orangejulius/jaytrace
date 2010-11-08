#include "Renderer.h"

Renderer::Renderer()
{
	width = 640;
	height = 480;

	projectionAngle = 25;
	aspectRatio = (float)width/height;
}

void Renderer::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

void Renderer::addLight(LightPointer light)
{
	lights.push_back(light);
}
