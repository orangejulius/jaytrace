#ifndef SCENE_H
#define SCENE_H

#include <list>

#include "Camera.h"
#include "Light.h"
#include "SceneObject.h"

using std::list;

/**
 * class Scene
 * Stores everything required to represent a graphical scene
 */
class Scene
{
public:
	Camera getCamera() const;
	void setCamera(Camera c);

	void addObject(SceneObjectPointer object);
	void addLight(LightPointer light);

	list<SceneObjectPointer> getObjects() const;
	list<LightPointer> getLights() const;

	/// returns a demo scene with a spiral made of spheres
	static Scene getSpiralScene();

	/// returns a demo scene with 4 spheres and two lights
	static Scene get4SphereScene();

protected:
	Camera camera;
	list<SceneObjectPointer> objects;
	list<LightPointer> lights;
};

typedef QSharedPointer<Scene> ScenePointer;

#endif // SCENE_H
