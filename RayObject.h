#ifndef RAYOBJECT_H
#define RAYOBJECT_H

#include <QExplicitlySharedDataPointer>

class Ray;
class IntersectionInfo;

class RayObject: public QSharedData
{
public:
	virtual ~RayObject();

	virtual IntersectionInfo* intersect(const Ray& ray) = 0;
};

typedef QExplicitlySharedDataPointer<RayObject> RayObjectPointer;

#endif // RAYOBJECT_H
