#include "RayTest.h"

#include <Eigen/Geometry>
#include <Eigen/LU>
#include "Ray.h"

using Eigen::Affine3d;
using Eigen::Translation3d;

Q_DECLARE_METATYPE(Vector3d)
Q_DECLARE_METATYPE(Ray)
Q_DECLARE_METATYPE(Affine3d)

void RayTest::getPosition()
{
	QFETCH(Vector3d, rayOrigin);
	QFETCH(Vector3d, rayDirection);
	QFETCH(double, time);
	QFETCH(Vector3d, position);

	Ray ray(rayOrigin, rayDirection);
	Vector3d testPosition = ray.getPosition(time);
	QCOMPARE(position, testPosition);
}

void RayTest::getPosition_data()
{
	QTest::addColumn<Vector3d>("rayOrigin");
	QTest::addColumn<Vector3d>("rayDirection");
	QTest::addColumn<double>("time");
	QTest::addColumn<Vector3d>("position");

	QTest::newRow("null test") << Vector3d(0, 0, 0) << Vector3d(0, 0, 0) << 0.0 << Vector3d(0, 0, 0);
	QTest::newRow("origin test") << Vector3d(3, 2, 3) << Vector3d(-3, -2, -3) << 1.0 << Vector3d(0, 0, 0);
	QTest::newRow("basic test") << Vector3d(5, 6, 7) << Vector3d(1, -2, 3) << 2.5 << Vector3d(7.5, 1, 14.5);
}

void RayTest::getTransformedRay()
{
	QFETCH(Ray, initialRay);
	QFETCH(Affine3d, transformationMatrix);
	QFETCH(Ray, transformedRay);

	Ray testTransformedRay = initialRay.getTransformedRay(transformationMatrix);
	QCOMPARE(testTransformedRay, transformedRay);
}

void RayTest::getTransformedRay_data()
{
	QTest::addColumn<Ray>("initialRay");
	QTest::addColumn<Affine3d>("transformationMatrix");
	QTest::addColumn<Ray>("transformedRay");

	Ray ray1(Vector3d(1, 2, 3), Vector3d(4, 5, 6));
	Affine3d identityMatrix = Affine3d::Identity();
	QTest::newRow("identityMatrix") << ray1 << identityMatrix << ray1;

	Affine3d translateUp10X(Translation3d(10, 0, 0));
	Ray ray2Expected(Vector3d(11, 2, 3), Vector3d(4, 5, 6));

	QTest::newRow("translateUp10X") << ray1 << translateUp10X << ray2Expected;
}
