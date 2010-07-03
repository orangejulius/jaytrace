#ifndef RAYOBJECT_H
#define RAYOBJECT_H

#include <QSharedPointer>

class Ray;
class IntersectionInfo;

class RayObject
{
public:
	virtual ~RayObject();

	virtual IntersectionInfo* intersect(const Ray& ray) = 0;
};

typedef QSharedPointer<RayObject> RayObjectPointer;

#endif // RAYOBJECT_H
