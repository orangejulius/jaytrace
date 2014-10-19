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

Ray Ray::getTransformedRay(Matrix4d transform) const
{
	Vector4d transformedOrigin = transform * origin;
	Vector4d transformedDirection = transform * direction;
	return Ray(transformedOrigin, transformedDirection);
}

Vector3d Ray::getPosition(double time) const
{
	return (origin + direction * time).head<3>();
}

bool Ray::operator==(const Ray& r) const
{
	return (r.origin == origin) && (r.direction == direction);
}
