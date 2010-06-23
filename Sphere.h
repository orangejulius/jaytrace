#ifndef SPHERE_H
#define SPHERE_H

#include "Node.h"

class Ray;

class Sphere: public Node
{
public:
	Sphere(NodePointer parent = NodePointer(0));
	~Sphere();

	bool intersect(Ray ray);
};

#endif // SPHERE_H
