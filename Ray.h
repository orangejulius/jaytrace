#ifndef RAY_H
#define RAY_H

#include <Eigen/Core>

using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::Matrix4d;
using namespace std;

class Ray
{
    protected:
        Vector3d origin;
        Vector3d direction;

    public:
        Ray(Vector3d origin, Vector3d direction);

        Vector3d getOrigin() { return origin;}
        Vector3d getDirection() {return direction;}

        Ray getTransformedRay(Matrix4d transformationMatrix);
        Vector3d getPosition(double time);
};

#endif // RAY_H
