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
	Ray(Vector4d origin, Vector4d direction);

	Vector3d getOrigin() const {
		return origin.head<3>();
	}

	Vector3d getDirection() const {
		return direction.head<3>();
	}

	Ray getTransformedRay(Matrix4d inverseTransformationMatrix) const;
	Vector3d getPosition(double time) const;

	bool operator==(const Ray& r) const;

protected:
	Vector4d origin;
	Vector4d direction;
};

#endif // RAY_H
