#include "Plane.h"

#include "IntersectionInfo.h"
#include "Ray.h"
#include "Raytracer.h"

#include <QDebug>

Plane::Plane(NodePointer parent): Node(parent), v0(Vector3d::Zero()), n(Vector3d::UnitZ())
{

}

Plane::Plane(Vector3d v0, Vector3d n, NodePointer parent): Node(parent), v0(v0), n(n)
{

}

Plane::~Plane()
{
	qDebug() << "Deleting Plane " << this;
}

IntersectionInfo* Plane::intersect(const Ray& ray)
{
	Ray genericRay = ray.getTransformedRay(getInverseMatrix());

	double numerator = n.dot(v0 - genericRay.getOrigin());
	double denominator = n.dot(genericRay.getDirection());

	if (denominator < 0.000000001 && denominator > -0.0000000001) {
		return 0;
	}

	double tHit = numerator / denominator;

	if (tHit < 0.0000000001) {
		return 0;
	}

	IntersectionInfo* info = new IntersectionInfo();
	info->normal = getMatrixState().linear() * n;
	info->time = tHit;
	info->object = this;

	return info;
}
