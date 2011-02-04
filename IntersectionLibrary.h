#ifndef INTERSECTIONLIBRARY_H
#define INTERSECTIONLIBRARY_H

#include <list>
#include "IntersectionInfo.h"
#include "RayObject.h"

using std::list;

class IntersectionLibrary
{
public:
	void addObject(RayObjectPointer object);
	void addObjects(list<RayObjectPointer> p_objects);
	void clear();
	IntersectionInfo* intersect(const Ray& ray);
private:
	list<RayObjectPointer> objects;
};

#endif // INTERSECTIONLIBRARY_H
