#include "Plane.h"

#include "IntersectionInfo.h"
#include "jaytrace.h"
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

IntersectionInfoPointer Plane::intersect(const Ray& ray)
{
	Ray genericRay = ray.getTransformedRay(getInverseTransform());

	double numerator = n.dot(v0 - genericRay.getOrigin());
	double denominator = n.dot(genericRay.getDirection());

	if (denominator < EPSILON && denominator > -EPSILON) {
		return NoHit();
	}

	double tHit = numerator / denominator;

	if (tHit < EPSILON) {
		return NoHit();
	}

	IntersectionInfoPointer info(new IntersectionInfo());
	info->normal = getTransform().linear() * n;
	info->time = tHit;
	info->object = this;

	return info;
}
