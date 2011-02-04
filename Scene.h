#ifndef SCENE_H
#define SCENE_H

#include <list>

#include "Camera.h"
#include "Light.h"
#include "RayObject.h"

using std::list;

/**
 * class Scene
 * Stores everything required to represent a graphical scene
 */
class Scene
{
public:
	Camera getCamera() const;
	list<RayObjectPointer> getObjects() const;
	list<LightPointer> getLights() const;

protected:
	// choosing not to override this method simply uses a "standard" camera:
	// eye at the origin, up in the Y direction, looking in -Z direction
	virtual void setupCamera();

	// scene classes must define these methods. dark or empty scenes are no fun!
	virtual void setupObjects() = 0;
	virtual void setupLights() = 0;

	void addObject(RayObjectPointer object);
	void addLight(LightPointer light);

	Camera camera;
	list<RayObjectPointer> objects;
	list<LightPointer> lights;
};

#endif // SCENE_H
