#include "Renderer.h"

Renderer::Renderer(ScenePointer scene, unsigned int width, unsigned int height, Angle projectionAngle):scene(scene), width(width), height(height), projectionAngle(projectionAngle)
{
	aspectRatio = (float)width / height;
}
