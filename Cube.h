#ifndef CUBE_H
#define CUBE_H

#include "Node.h"
#include "RayObject.h"

class Ray;

class Cube: public Node, public RayObject
{
public:
	Cube(NodePointer parent = NodePointer(0));
	virtual ~Cube();

	IntersectionInfo* intersect(const Ray& ray);
private:

};

#endif // CUBE_H
