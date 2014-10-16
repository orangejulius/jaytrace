#ifndef PLANE_H
#define PLANE_H

#include "Node.h"
#include "RayObject.h"

using Eigen::Vector3d;

class Ray;

class Plane: public Node, public RayObject
{
public:
	Plane(NodePointer parent = NodePointer(0));
	Plane(Vector3d v0, Vector3d n, NodePointer parent = NodePointer(0));
	virtual ~Plane();

	IntersectionInfo* intersect(const Ray& ray);

protected:
	Vector3d v0, n;
};

#endif // PLANE_H
