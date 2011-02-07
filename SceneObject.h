#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <QSharedPointer>

class Ray;
class IntersectionInfo;
class SceneObjectVisitor;

class SceneObject
{
public:
	virtual ~SceneObject();

	virtual IntersectionInfo* intersect(const Ray& ray) = 0;

	virtual void accept(SceneObjectVisitor& visitor) = 0;
};

typedef QSharedPointer<SceneObject> SceneObjectPointer;

#endif // SCENEOBJECT_H
