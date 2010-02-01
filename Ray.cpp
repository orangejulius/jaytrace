#include "Ray.h"

#include <Eigen/Geometry>
#include <Eigen/LU>

Ray::Ray(): origin(Vector3d(0,0,0)),direction(Vector3d(0,0,0))
{

}
Ray::Ray(Vector3d origin, Vector3d direction): origin(origin), direction(direction)
{

}

Ray Ray::getTransformedRay(Matrix4d transformationMatrix)
{
    Vector4d rayOrigin4d;
    rayOrigin4d<<origin,1;

    Vector4d rayDirection4d;
    rayDirection4d<<direction,0;

    Vector3d transformedRayOrigin;
    transformedRayOrigin=(transformationMatrix.inverse()*rayOrigin4d).start<3>();

    Vector3d transformedRayDirection;
    transformedRayDirection=(transformationMatrix.inverse()*rayDirection4d).start<3>();

    return Ray(transformedRayOrigin, transformedRayDirection);
}

Vector3d Ray::getPosition(double time)
{
    return origin+direction*time;
}

bool Ray::operator==(const Ray &r) const
{
	return (r.origin == origin) && (r.direction == direction);
}
