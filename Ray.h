#ifndef RAY_H
#define RAY_H

#include <Eigen/Core>

using Eigen::Vector3d;
using Eigen::Vector4d;
using Eigen::Matrix4d;

class Ray
{
    protected:
        Vector3d origin;
        Vector3d direction;

    public:
	Ray();
        Ray(Vector3d origin, Vector3d direction);

        Vector3d getOrigin() {return origin;}
        Vector3d getDirection() {return direction;}

        Ray getTransformedRay(Matrix4d transformationMatrix) const;
        Vector3d getPosition(double time) const;

	bool operator==(const Ray &r) const;
};

#endif // RAY_H
