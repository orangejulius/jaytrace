#ifndef RENDERER_H
#define RENDERER_H

#include <list>

#include "Angle.h"
#include "Light.h"
#include "RayObject.h"

using std::list;

class Renderer
{
public:
	Renderer(unsigned int width = 640, unsigned int height = 480, Angle projectionAngle = Angle::degrees(25));

	void addObject(RayObjectPointer object);
	void addLight(LightPointer light);
protected:
	unsigned int width;
	unsigned int height;

	Angle projectionAngle;
	float aspectRatio;

	list<RayObjectPointer> objects;
	list<LightPointer> lights;
};

#endif // RENDERER_H
