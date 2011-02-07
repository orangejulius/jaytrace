#include "SceneObject.h"

#include <QDebug>

SceneObject::~SceneObject()
{
	qDebug()<<"Deleting RayObject "<<this;
}
