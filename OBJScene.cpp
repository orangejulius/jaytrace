#include "OBJScene.h"

#include "MaterialNode.h"
#include "TranslationNode.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "OBJModel.h"

OBJScene::OBJScene()
{
	setupCamera();
	setupObjects();
	setupLights();
}

void OBJScene::setupCamera()
{
	Vector3d eye(30, 50, 100);
	Vector3d look(0, 0, 0);
	Vector3d up(0, 1, 0);
	camera = Camera(eye, look, up);
}

void OBJScene::setupObjects()
{
	NodePointer rootNode(new TransformNode(getCamera().getTransform()));

	MaterialNodePointer material(new MaterialNode(rootNode));
	Color white(1, 1, 1);
	material->setAmbient(Color(0.5, 0, 0));
	material->setDiffuse(white * .5);
	material->setSpecular(Color(0.5, 0, 1.0));
	material->setShininess(20);

	OBJModel obj = OBJModel::import("objects/magnolia.obj", material);
	vector<RayObjectPointer> objects = obj.getObjects();
	for(size_t i = 0; i < objects.size(); i++) {
		addObject(objects[i]);
	}
}

void OBJScene::setupLights()
{
	Color white(1, 1, 1);

	LightPointer l1(new Light(Vector3d(-3, 12, -15), 0));
	l1->setAmbient(white * .2);
	l1->setDiffuse(white);
	l1->setSpecular(white);
	addLight(l1);
}
