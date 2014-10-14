#include "Ray.h"

#include <Eigen/Geometry>
#include <Eigen/LU>

Ray::Ray()
{

}

Ray::Ray(Vector3d origin, Vector3d direction)
{
	this->origin << origin, 1;
	this->direction << direction, 0;
}

Ray::Ray(Vector4d origin, Vector4d direction): origin(origin), direction(direction)
{

}

Ray Ray::getTransformedRay(Matrix4d inverseTransformationMatrix) const
{
	Vector4d transformedRayOrigin;
	transformedRayOrigin = (inverseTransformationMatrix * origin);

	Vector4d transformedRayDirection;
	transformedRayDirection = (inverseTransformationMatrix * direction);

	return Ray(transformedRayOrigin, transformedRayDirection);
}

Vector3d Ray::getPosition(double time) const
{
	return (origin + direction * time).start<3>();
}

bool Ray::operator==(const Ray& r) const
{
	return (r.origin == origin) && (r.direction == direction);
}
