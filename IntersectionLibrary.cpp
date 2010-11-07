#include "IntersectionLibrary.h"

#include "IntersectionInfo.h"

void IntersectionLibrary::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

IntersectionInfo* IntersectionLibrary::intersect(const Ray& ray)
{
	IntersectionInfo* best = 0;
	for (list<RayObjectPointer>::iterator i = objects.begin(); i != objects.end(); i++) {
		IntersectionInfo* info = (*i)->intersect(ray);
		if (info) {
			if (best == 0 || info->time < best->time) {
				best = info;
			}
		}
	}

	return best;
}
