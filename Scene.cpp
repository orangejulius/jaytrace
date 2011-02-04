#include "Scene.h"

Camera Scene::getCamera() const
{
	return camera;
}

void Scene::setCamera(Camera c)
{
	camera = c;
}

void Scene::addObject(RayObjectPointer object)
{
	objects.push_back(object);

}

void Scene::addLight(LightPointer light)
{
	lights.push_back(light);
}

list<RayObjectPointer> Scene::getObjects() const
{
	return objects;
}

list<LightPointer> Scene::getLights() const
{
	return lights;
}
