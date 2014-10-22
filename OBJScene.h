#ifndef OBJ_SCENE_H
#define OBJ_SCENE_H

#include "Scene.h"

class OBJScene : public Scene
{
public:
	OBJScene();

protected:
	void setupCamera();
	void setupObjects();
	void setupLights();
};

#endif // OBJ_SCENE_H
