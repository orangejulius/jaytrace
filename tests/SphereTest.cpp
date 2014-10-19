#include "SphereTest.h"

#include <Eigen/Geometry>
#include <Eigen/LU>
#include "IntersectionInfo.h"
#include "Ray.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "Sphere.h"
#include "TranslationNode.h"

void SphereTest::testMultipleTransformParents()
{
	NodePointer t1(new TranslationNode(1, 0, 0));
	NodePointer t2(new TranslationNode(0, 2, 0, t1));
	Sphere s1(t2);

	Affine3d actualTransform = s1.getTransform();
	Affine3d expectedTransform(Translation3d(1, 2, 0));

	QCOMPARE(expectedTransform.matrix(), actualTransform.matrix());
}

void SphereTest::testAxisAlignedNormalIntersection()
{
	Ray ray(Vector3d(-10, 0, 0), Vector3d(1, 0, 0));
	Sphere sphere;

	IntersectionInfo * info = sphere.intersect(ray);
	QVERIFY(info != 0);

	QCOMPARE(info->time, 9.0);
}

void SphereTest::testParallelMiss()
{
	Ray ray(Vector3d(-10, 0, 0), Vector3d(0, 1, 0));
	Sphere sphere;

	QVERIFY(sphere.intersect(ray) == 0);
}

void SphereTest::testAngledNormalIntersection()
{
	Ray ray(Vector3d(3, 2, 3), Vector3d(-3, -2, -3).normalized());
	Sphere sphere;

	IntersectionInfo * info = sphere.intersect(ray);

	QVERIFY(info != 0);
	QCOMPARE(info->time, ray.getOrigin().norm() - 1);
	Vector3d expectedNormal = ray.getOrigin().normalized();
	QCOMPARE(info->normal.x(), expectedNormal.x());
	QCOMPARE(info->normal.y(), expectedNormal.y());
	QCOMPARE(info->normal.z(), expectedNormal.z());
}

void SphereTest::testTransformedIntersection()
{
	NodePointer t1(new TranslationNode(0, 5, 0));
	Sphere s1(t1);

	Ray ray1(Vector3d(-10, 5, 0), Vector3d(10, 0, 0));
	Ray ray2(Vector3d(-10, 0, 0), Vector3d(10, 0, 0));

	QVERIFY(s1.intersect(ray1));
	QVERIFY(!s1.intersect(ray2));
}

void SphereTest::testEvenlyScaledIntersection()
{
	NodePointer scale2x(new ScalingNode(2, 2, 2));
	Sphere sphere(scale2x);

	Ray ray(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	IntersectionInfo* info = sphere.intersect(ray);

	QVERIFY(info != 0);
	QCOMPARE(info->time, 8.0);
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void SphereTest::testEllipsoidIntersection()
{
	NodePointer scaleToEllipsoid(new ScalingNode(1, 1, 2));
	Sphere sphere(scaleToEllipsoid);
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));
	Ray ray2(Vector3d(0, 0.5, 10), Vector3d(0, 0, -1));

	IntersectionInfo* info1 = sphere.intersect(ray1);
	IntersectionInfo* info2 = sphere.intersect(ray2);

	QVERIFY(info1 != 0);
	QCOMPARE(info1->time, 8.0);
	QCOMPARE(info1->normal, Vector3d(0, 0, 1));

	double sqrt3 = 1.7320508075688772;
	Vector3d expectedIntersection(0, 0.5, sqrt3);
	Vector3d expectedNormal(0, 0.5, sqrt3 / 4);
	expectedNormal.normalize();

	QVERIFY(info2 != 0);
	QVERIFY(ray2.getPosition(info2->time).isApprox(expectedIntersection));
	QCOMPARE(info2->normal.x(), expectedNormal.x());
	QCOMPARE(info2->normal.y(), expectedNormal.y());
	QCOMPARE(info2->normal.z(), expectedNormal.z());
}

void SphereTest::testRotatedEllipsoidIntersection()
{
	NodePointer rotate90degreesY(new RotationNode(Angle::degrees(270), Vector3d::UnitY()));
	NodePointer scaleToEllipsoid(new ScalingNode(2, 1, 1, rotate90degreesY));
	Sphere sphere(scaleToEllipsoid);
	Ray ray(Vector3d(0, 0.5, 10), Vector3d(0, 0, -1));

	IntersectionInfo* info = sphere.intersect(ray);

	double sqrt3 = 1.7320508075688772;
	Vector3d expectedIntersection(0, 0.5, sqrt3);
	Vector3d expectedNormal(0, 0.5, sqrt3 / 4);
	expectedNormal.normalize();

	QVERIFY(info != 0);
	QVERIFY(ray.getPosition(info->time).isApprox(expectedIntersection));
	QCOMPARE(info->normal.x() + 1, expectedNormal.x() + 1);
	QCOMPARE(info->normal.y() + 1, expectedNormal.y() + 1);
	QCOMPARE(info->normal.z() + 1, expectedNormal.z() + 1);
}
