#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Node.h"
#include "Plane.h"
#include "RayObject.h"

using Eigen::Vector3d;
using Eigen::Vector4d;

class Ray;

class Triangle: public Node, public RayObject
{
public:
	Triangle(Vector3d v0, Vector3d v1, Vector3d v2, NodePointer parent = NodePointer(0));
	virtual ~Triangle();

	IntersectionInfo* intersect(const Ray& ray);

	Vector3d getV0() const {
		return v0;
	};
	Vector3d getV1() const {
		return v1;
	};
	Vector3d getV2() const {
		return v2;
	};
	Vector3d getU() const {
		return u;
	};
	Vector3d getV() const {
		return v;
	};
	Vector3d getN() const {
		return n;
	};

protected:
	bool pointInTriangle(Vector3d p1);
	Vector3d getTransformedNormal();

	// triangle points
	Vector3d v0, v1, v2;

	// triangle edge vectors
	Vector3d u, v;

	// normal vector
	Vector3d n;

	// plane for this triangle
	Plane plane;
};

#endif // TRIANGLE_H
