#include "IntersectionLibrary.h"

#include "IntersectionInfo.h"

void IntersectionLibrary::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

IntersectionInfo* IntersectionLibrary::intersect(const Ray& ray)
{
	for (list<RayObjectPointer>::iterator i = objects.begin(); i != objects.end(); i++) {
		IntersectionInfo* info = (*i)->intersect(ray);
		if (info) {
			return info;
		}
	}
	return 0;
}
