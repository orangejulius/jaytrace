#ifndef RENDERER_H
#define RENDERER_H

#include <list>

#include "Angle.h"
#include "Scene.h"

using std::list;

class Renderer
{
public:
	Renderer(ScenePointer scene, unsigned int width = 640, unsigned int height = 480, Angle projectionAngle = Angle::degrees(25));

protected:
	ScenePointer scene;

	unsigned int width;
	unsigned int height;

	Angle projectionAngle;
	float aspectRatio;
};

#endif // RENDERER_H
