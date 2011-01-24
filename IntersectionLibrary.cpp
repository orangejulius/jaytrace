#include "IntersectionLibrary.h"

#include "IntersectionInfo.h"

void IntersectionLibrary::addObject(WeakRayObjectPointer object)
{
	objects.push_back(object);
}

IntersectionInfo* IntersectionLibrary::intersect(const Ray& ray)
{
	IntersectionInfo* best = 0;
	for (list<WeakRayObjectPointer>::iterator i = objects.begin(); i != objects.end(); i++) {
		RayObjectPointer object = i->toStrongRef();
		if (object) {
			IntersectionInfo* info = object->intersect(ray);
			if (info) {
				if (best == 0 || info->time < best->time) {
					best = info;
				} else {
					delete info;
				}
			}
		}
	}

	return best;
}
