#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QSharedPointer>

class Ray;
class IntersectionInfo;

class SceneObject
{
public:
	virtual ~SceneObject();

	virtual IntersectionInfo* intersect(const Ray& ray) = 0;
};

typedef QSharedPointer<SceneObject> SceneObjectPointer;

#endif // SCENEOBJECT_H
