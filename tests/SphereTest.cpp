#include "SphereTest.h"

#include <Eigen/Geometry>
#include <Eigen/LU>
#include "Ray.h"
#include "Sphere.h"
#include "TranslationNode.h"

void SphereTest::testMultipleTransformParents()
{
	NodePointer t1(new TranslationNode(1, 0, 0));
	NodePointer t2(new TranslationNode(0, 2, 0, t1));
	QSharedPointer<Sphere> s1(new Sphere(t2));

	Affine3d actualTransform = s1->getTransform();
	Affine3d expectedTransform(Translation3d(1, 2, 0));

	QCOMPARE(expectedTransform.matrix(), actualTransform.matrix());
}

void SphereTest::testUntransformedIntersection()
{
	Ray ray1(Vector3d(-10, 0, 0), Vector3d(10, 0, 0));
	Ray ray2(Vector3d(-10, 0, 0), Vector3d(0, 10, 0));
	Ray ray3(Vector3d(3, 2, 3), Vector3d(-3, -2, -3));
	Sphere sphere;
	QVERIFY(sphere.intersect(ray1));
	QVERIFY(!sphere.intersect(ray2));
	QVERIFY(sphere.intersect(ray3));
}

void SphereTest::testTransformedIntersection()
{
	NodePointer t1(new TranslationNode(0, 5, 0));
	QSharedPointer<Sphere> s1(new Sphere(t1));

	Ray ray1(Vector3d(-10, 5, 0), Vector3d(10, 0, 0));
	Ray ray2(Vector3d(-10, 0, 0), Vector3d(10, 0, 0));

	QVERIFY(s1->intersect(ray1));
	QVERIFY(!s1->intersect(ray2));
}
