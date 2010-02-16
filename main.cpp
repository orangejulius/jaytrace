#include <QtCore/QCoreApplication>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/LU>

#include "Ray.h"

using namespace Eigen;
using namespace std;

void rayTest() {
    Matrix4d M;
    M<< 1, 0, 0, 2,
        0, 4, 0, 4,
        0, 0, 4, 9,
        0, 0, 0, 1;
    M=Matrix4d::Identity();
    cout<<"M:\n";
    cout<<M<<endl;
    cout<<"M inverse:\n";
    cout<<M.inverse()<<endl;

    //Vector3d rayOrigin(10,20,5);
    //Vector3d rayDirection(-8,-12,4);
    Vector3d rayOrigin(3,2,3);
    Vector3d rayDirection(-3,-2,-3);

    Ray ray(rayOrigin,rayDirection);
    Ray transformedRay=ray.getTransformedRay(M);

    cout<<"S (ray origin):\n";
    cout<<ray.getOrigin()<<endl;

    cout<<"c (ray direction):\n";
    cout<<ray.getDirection()<<endl;

    double A = transformedRay.getDirection().squaredNorm();
    double B = transformedRay.getOrigin().dot(transformedRay.getDirection());
    double C = transformedRay.getOrigin().squaredNorm() - 1;
    cout<<"A: "<<A<<" B: "<<B<<" C: "<<C<<endl;

    double discrim = B*B-A*C;
    cout<<"Discriminant: "<<discrim<<endl;

    if (discrim>=0) {
        double discRoot= sqrt(discrim);
        cout<<"Discriminant root: "<<discRoot<<endl;
        double t1 = (-B - discRoot) / A;
        double t2 = (-B + discRoot) / A;
        cout<<"t1: "<<t1<<" t2: "<<t2<<endl;

        double solutionTime = min(t1,t2);
        cout<<"Solution: "<<solutionTime<<endl;
        Vector3d intersectionPoint = ray.getPosition(solutionTime);
        cout<<intersectionPoint<<endl;
    } else {
        cout<<"No solutions"<<endl;
    }
}

void transformationTest() {
    Transform3d transform(Matrix4d::Identity());
    cout<<transform.matrix()<<endl;

    transform*=Translation3d(1,2,3);
    cout<<endl<<transform.matrix()<<endl;

    transform*=AngleAxisd(10,Vector3d::UnitX());
    cout<<transform.matrix()<<endl;

}

int main(int argc, char *argv[])
{
    transformationTest();
}
