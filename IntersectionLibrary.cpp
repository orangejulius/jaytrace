#include "IntersectionLibrary.h"

#include "IntersectionInfo.h"

void IntersectionLibrary::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

IntersectionInfoPointer IntersectionLibrary::intersect(const Ray& ray)
{
	IntersectionInfoPointer best;
	for (list<RayObjectPointer>::iterator i = objects.begin(); i != objects.end(); i++) {
		IntersectionInfoPointer info = (*i)->intersect(ray);
		if (info) {
			if (!best || info->time < best->time) {
				best = info;
			}
		}
	}

	return best;
}
