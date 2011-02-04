#include "IntersectionLibrary.h"

#include "IntersectionInfo.h"

void IntersectionLibrary::addObject(RayObjectPointer object)
{
	objects.push_back(object);
}

void IntersectionLibrary::addObjects(list< RayObjectPointer > p_objects)
{
	objects.splice(objects.end(), p_objects);
}

void IntersectionLibrary::clear()
{
	objects.clear();
}

IntersectionInfo* IntersectionLibrary::intersect(const Ray& ray)
{
	IntersectionInfo* best = 0;
	for (list<RayObjectPointer>::iterator i = objects.begin(); i != objects.end(); i++) {
		IntersectionInfo* info = (*i)->intersect(ray);
		if (info) {
			if (best == 0 || info->time < best->time) {
				best = info;
			} else {
				delete info;
			}
		}
	}

	return best;
}
