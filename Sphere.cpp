#include "Sphere.h"

#include "Ray.h"

#include <QDebug>
#include <Eigen/LU>

Sphere::Sphere(NodePointer parent): Node(parent)
{

}

Sphere::~Sphere()
{
	qDebug()<<"Deleting Sphere "<<this;
}

bool Sphere::intersect(Ray ray)
{
	Transform3d transform = this->getMatrixState();

	if (transform.matrix().determinant() == 0) {
		qDebug()<<"Matrix not invertible!";
		return false;
	}

	Ray genericRay = ray.getTransformedRay(transform.matrix());

	double A = genericRay.getDirection().squaredNorm();
	double B = genericRay.getOrigin().dot(genericRay.getDirection());
	double C = genericRay.getOrigin().squaredNorm() - 1;

	double discriminant = B*B - A*C;

	if (discriminant < 0) {
		return false;
	}

	double dRoot = sqrt(discriminant);
	double t1 = (-B - dRoot)/A;
	double t2 = (-B + dRoot)/A;

	if (t1 > 0.00001) {
		return true;
	}

	if (t2 > 0.00001) {
		return true;
	}

	return false;
}
