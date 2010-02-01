#include <QtCore/QCoreApplication>
#include <Eigen/Core>
#include <Eigen/LU>

using namespace Eigen;
using namespace std;

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

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

    cout<<"S (ray origin):\n";
    cout<<rayOrigin<<endl;

    cout<<"c (ray direction):\n";
    cout<<rayDirection<<endl;

    Vector4d rayOrigin4d;
    rayOrigin4d<<rayOrigin,1;

    Vector4d rayDirection4d;
    rayDirection4d<<rayDirection,0;

    Vector3d transformedRayOrigin;
    transformedRayOrigin=(M.inverse()*rayOrigin4d).start<3>();
    cout<<"M inverse * S: "<<endl;
    cout<<transformedRayOrigin<<endl;

    Vector3d transformedRayDirection;
    transformedRayDirection=(M.inverse()*rayDirection4d).start<3>();
    cout<<"M inverse * c\n";
    cout<<transformedRayDirection<<endl;


    double A = transformedRayDirection.squaredNorm();
    double B = transformedRayOrigin.dot(transformedRayDirection);
    double C = transformedRayOrigin.squaredNorm() - 1;
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
        Vector3d intersectionPoint = rayOrigin+rayDirection*solutionTime;
        cout<<intersectionPoint<<endl;


    } else {
        cout<<"No solutions"<<endl;
    }

    //return a.exec();
}
