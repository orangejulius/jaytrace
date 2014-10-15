#ifndef FOUR_SPHERE_SCENE_H
#define FOUR_SPHERE_SCENE_H

#include "Scene.h"

class FourSphereScene : public Scene
{
public:
	FourSphereScene();

protected:
	void setupCamera();
	void setupObjects();
	void setupLights();
};

#endif // FOUR_SPHERE_SCENE_H
