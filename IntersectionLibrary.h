#ifndef INTERSECTIONLIBRARY_H
#define INTERSECTIONLIBRARY_H

#include <list>
#include "IntersectionInfo.h"
#include "RayObject.h"

using std::list;

class IntersectionLibrary
{
public:
	void addObject(WeakRayObjectPointer object);
	IntersectionInfo* intersect(const Ray& ray);
private:
	list<WeakRayObjectPointer> objects;
};

#endif // INTERSECTIONLIBRARY_H
