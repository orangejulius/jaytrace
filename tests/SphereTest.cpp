#include "SphereTest.h"

#include <Eigen/Geometry>
#include <Eigen/LU>
#include "IntersectionInfo.h"
#include "Ray.h"
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
