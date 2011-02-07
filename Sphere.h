#ifndef SPHERE_H
#define SPHERE_H

#include "Node.h"
#include "SceneObject.h"

class Ray;

class Sphere: public Node, public SceneObject
{
public:
	Sphere(NodePointer parent = NodePointer(0));
	virtual ~Sphere();

	IntersectionInfo* intersect(const Ray& ray);
private:

};

#endif // SPHERE_H
