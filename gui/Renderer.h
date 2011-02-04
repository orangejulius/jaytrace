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
	Renderer();

	void addObject(RayObjectPointer object);
	void addLight(LightPointer light);

	virtual void render() = 0;
protected:
	Angle projectionAngle;
	float aspectRatio;

	unsigned int width;
	unsigned int height;

	list<RayObjectPointer> objects;
	list<LightPointer> lights;
};

#endif // RENDERER_H
