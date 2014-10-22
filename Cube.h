#ifndef CUBE_H
#define CUBE_H

#include "Node.h"
#include "RayObject.h"

using Eigen::Vector3d;

class Ray;

class Cube: public Node, public RayObject
{
public:
	Cube(NodePointer parent = NodePointer(0));
	virtual ~Cube();

	IntersectionInfoPointer intersect(const Ray& ray);

protected:
	Vector3d getFaceNormal(int axis, int magnitude);
};

#endif // CUBE_H
