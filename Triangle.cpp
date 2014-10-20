#include "Triangle.h"

#include "IntersectionInfo.h"
#include "Ray.h"

#include <QDebug>

Triangle::Triangle(Vector3d v0, Vector3d v1, Vector3d v2, NodePointer parent): Node(parent), v0(v0), v1(v1), v2(v2)
{
	u = v1 - v0;

	v = v2 - v0;

	n = u.cross(v).normalized();

	plane = Plane(v0, n);
}

Triangle::~Triangle()
{
	qDebug() << "Deleting Triangle " << this;
}

IntersectionInfo* Triangle::intersect(const Ray& ray)
{
	// check for degenerate triangle (a line segment)
	if (n.isApprox(Vector3d::Zero())) {
		return 0;
	}

	Ray genericRay = ray.getTransformedRay(getInverseTransform());

	// first check for intersection with the plane of the triangle
	IntersectionInfo* planeIntersection = plane.intersect(genericRay);
	if (planeIntersection == 0) {
		return 0;
	}
	// get the point at which the ray intersects the plane
	Vector3d p1 = genericRay.getPosition(planeIntersection->time);

	if(pointInTriangle(p1)) {
		IntersectionInfo* info = new IntersectionInfo;
		info->time = planeIntersection->time;
		info->normal = getTransformedNormal();
		info->object = this;
		return info;
	}

	return 0;
}

bool Triangle::pointInTriangle(Vector3d p1)
{
	// vector from plane intersection to first triangle vertex
	Vector3d w = p1 - v0;

	double udotv = u.dot(v);
	double udotu = u.dot(u);
	double vdotv = v.dot(v);
	double wdotv = w.dot(v);
	double wdotu = w.dot(u);

	double denominator = udotv * udotv - udotu * vdotv;

	double sNumerator = udotv * wdotv - vdotv * wdotu;
	double s = sNumerator / denominator;
	if (s < 0.0 || s > 1.0) {
		return false;
	}

	double tNumerator = udotv * wdotu - udotu * wdotv;
	double t = tNumerator / denominator;
	if (t < 0.0 || (s + t) > 1.0) {
		return false;
	}

	return true;
}

Vector3d Triangle::getTransformedNormal()
{
	return (getTransform().linear() * n).normalized();
}
