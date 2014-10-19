#include "Ray.h"

Ray::Ray()
{

}

Ray::Ray(Vector3d origin, Vector3d direction): origin(origin), direction(direction)
{

}

Ray Ray::getTransformedRay(Affine3d transform) const
{
	return Ray(transform * origin, transform.linear() * direction);
}

Vector3d Ray::getPosition(double time) const
{
	return origin + direction * time;
}

bool Ray::operator==(const Ray& r) const
{
	return (r.origin == origin) && (r.direction == direction);
}
