#ifndef RAY_H
#define RAY_H

#include <Eigen/Core>

using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::Matrix4d;

class Ray
{
public:
	Ray();
	Ray(Vector3d origin, Vector3d direction);

	Vector3d getOrigin() {
		return origin;
	}
	Vector3d getDirection() {
		return direction;
	}

	Ray getTransformedRay(Matrix4d inverseTransformationMatrix) const;
	Vector3d getPosition(double time) const;

	bool operator==(const Ray &r) const;

protected:
	Vector3d origin;
	Vector3d direction;
};

#endif // RAY_H
