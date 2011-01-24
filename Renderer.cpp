#include "Renderer.h"

Renderer::Renderer(): projectionAngle(Angle::degrees(25))
{
	width = 640;
	height = 480;

	aspectRatio = (float)width/height;
}

void Renderer::addObject(WeakRayObjectPointer object)
{
	objects.push_back(object);
}

void Renderer::addLight(LightPointer light)
{
	lights.push_back(light);
}
