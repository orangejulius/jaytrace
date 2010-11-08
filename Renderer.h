#ifndef RENDERER_H
#define RENDERER_H

#include <list>

#include "RayObject.h"

using std::list;

class Renderer
{
public:
	Renderer();

	void addObject(RayObjectPointer object);
protected:
	float projectionAngle;
	float aspectRatio;

	unsigned int width;
	unsigned int height;

	list<RayObjectPointer> objects;
};

#endif // RENDERER_H
