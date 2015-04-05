#include "Renderer.h"

Renderer::Renderer(ScenePointer scene, unsigned int width, unsigned int height, unsigned int aaSamples, Angle projectionAngle):scene(scene), width(width), height(height), aaSamples(aaSamples), projectionAngle(projectionAngle)
{
	aspectRatio = (float)width / height;
}
