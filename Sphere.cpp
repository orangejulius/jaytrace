#include "Sphere.h"

#include "IntersectionInfo.h"
#include "Ray.h"

#include <QDebug>
#include <Eigen/LU>

Sphere::Sphere(NodePointer parent): Node(parent)
{

}

Sphere::~Sphere()
{
	qDebug() << "Deleting Sphere " << this;
}

IntersectionInfoPointer Sphere::intersect(const Ray& ray)
{
	Affine3d transform = getTransform();

	if (transform.matrix().determinant() == 0) {
		qDebug() << "Matrix not invertible!";
		return NoHit();
	}

	Ray genericRay = ray.getTransformedRay(getInverseTransform());

	double A = genericRay.getDirection().squaredNorm();
	double B = genericRay.getOrigin().dot(genericRay.getDirection());
	double C = genericRay.getOrigin().squaredNorm() - 1;

	double discriminant = B * B - A * C;

	if (discriminant < 0) {
		return NoHit();
	}

	double dRoot = sqrt(discriminant);
	double solution = 0;

	//t2 is always greater than t1 so if t2 is not greater than 0,
	//t1 cannot be
	double t2 = (-B + dRoot) / A;
	if (t2 > 0.0000000001 ) {
		solution = t2;
	} else {
		return NoHit();
	}

	double t1 = (-B - dRoot) / A;
	if (t1 > 0.000000001) {
		solution = t1;
	} else {
		return NoHit();
	}

	IntersectionInfoPointer result(new IntersectionInfo());
	result->time = solution;

	Vector3d genericNormal = genericRay.getPosition(result->time);
	result->normal = (getTransform().linear().inverse().transpose() * genericNormal).normalized();
	result->object = this;

	return result;
}
