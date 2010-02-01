#include "Ray.h"

#include <Eigen/Geometry>
#include <Eigen/LU>

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
    cout<<"M inverse * S: "<<endl;
    cout<<transformedRayOrigin<<endl;

    Vector3d transformedRayDirection;
    transformedRayDirection=(transformationMatrix.inverse()*rayDirection4d).start<3>();
    cout<<"M inverse * c\n";
    cout<<transformedRayDirection<<endl;

    return Ray(transformedRayOrigin, transformedRayDirection);
}

Vector3d Ray::getPosition(double time)
{
    return origin+direction*time;
}
