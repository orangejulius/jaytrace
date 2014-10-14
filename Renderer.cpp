#include "Renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height, Angle projectionAngle):width(width), height(height), projectionAngle(projectionAngle)
{
	aspectRatio = (float)width / height;
}

void Renderer::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

void Renderer::addLight(LightPointer light)
{
	lights.push_back(light);
}
