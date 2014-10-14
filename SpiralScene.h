#ifndef SPIRAL_SCENE_H
#define SPIRAL_SCENE_H

#include "Scene.h"

class SpiralScene : public Scene
{
public:
	SpiralScene();

protected:
	void setupObjects();
	void setupLights();
};

#endif // SPIRAL_SCENE_H
