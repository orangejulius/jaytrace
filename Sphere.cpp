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

IntersectionInfo* Sphere::intersect(const Ray& ray)
{
	Transform3d transform = this->getMatrixState();

	if (transform.matrix().determinant() == 0) {
		qDebug() << "Matrix not invertible!";
		return 0;
	}

	Ray genericRay = ray.getTransformedRay(getInverseMatrix());

	double A = genericRay.getDirection().squaredNorm();
	double B = genericRay.getOrigin().dot(genericRay.getDirection());
	double C = genericRay.getOrigin().squaredNorm() - 1;

	double discriminant = B * B - A * C;

	if (discriminant < 0) {
		return 0;
	}

	double dRoot = sqrt(discriminant);
	double solution = 0;

	//t2 is always greater than t1 so if t2 is not greater than 0,
	//t1 cannot be
	double t2 = (-B + dRoot) / A;
	if (t2 > 0 ) {
		solution = t2;
	} else {
		return 0;
	}

	double t1 = (-B - dRoot) / A;
	if (t1 > 0) {
		solution = t1;
	} else {
		return 0;
	}

	IntersectionInfo* result = new IntersectionInfo;
	result->time = solution;

	//calculate the normal vector as a difference between the center of the circle
	//and the intersection point
	Vector3d intersectionPoint = ray.getPosition(result->time);
	Vector3d circleCenter = transform.translation();
	result->normal = intersectionPoint - circleCenter;
	result->normal.normalize();
	result->object = this;

	return result;
}
