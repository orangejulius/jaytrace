#ifndef INTERSECTIONLIBRARY_H
#define INTERSECTIONLIBRARY_H

#include <list>
#include "IntersectionInfo.h"
#include "SceneObject.h"

using std::list;

class IntersectionLibrary
{
public:
	void addObject(SceneObjectPointer object);
	void addObjects(list<SceneObjectPointer> p_objects);
	void clear();
	IntersectionInfo* intersect(const Ray& ray);
private:
	list<SceneObjectPointer> objects;
};

#endif // INTERSECTIONLIBRARY_H
