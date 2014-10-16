#ifndef CUBE_SCENE_H
#define CUBE_SCENE_H

#include "Scene.h"

class CubeScene : public Scene
{
public:
	CubeScene();

protected:
	void setupCamera();
	void setupObjects();
	void setupLights();
};

#endif // CUBE_SCENE_H
