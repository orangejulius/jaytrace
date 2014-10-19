#ifndef RAY_H
#define RAY_H

#include <Eigen/Core>
#include <Eigen/Geometry>

using Eigen::Vector3d;
using Eigen::Affine3d;

class Ray
{
public:
	Ray();
	Ray(Vector3d origin, Vector3d direction);

	Vector3d getOrigin() const {
		return origin;
	}

	Vector3d getDirection() const {
		return direction;
	}

	Ray getTransformedRay(Affine3d transform) const;
	Vector3d getPosition(double time) const;

	bool operator==(const Ray& r) const;

protected:
	Vector3d origin;
	Vector3d direction;
};

#endif // RAY_H
