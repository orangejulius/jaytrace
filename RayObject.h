#ifndef RAYOBJECT_H
#define RAYOBJECT_H

#include "IntersectionInfo.h"

class Ray;

class RayObject
{
public:
	virtual ~RayObject();

	virtual IntersectionInfoPointer intersect(const Ray& ray) = 0;
};

typedef QSharedPointer<RayObject> RayObjectPointer;

#endif // RAYOBJECT_H
