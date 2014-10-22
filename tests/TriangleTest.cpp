#include "TriangleTest.h"

#include "Ray.h"
#include "Triangle.h"
#include "IntersectionInfo.h"
#include "RotationNode.h"
#include "TranslationNode.h"

void TriangleTest::testConstructor()
{
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	QCOMPARE(triangle.getN().x(), 0.0);
	QCOMPARE(triangle.getN().y(), 0.0);
	QCOMPARE(triangle.getN().z(), 1.0);
}

void TriangleTest::testNormalIntersection()
{
	//create a ray starting along the Z axis, looking at origin
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info != 0);

	QCOMPARE(info->time, 10.0);

	//triangle normal is the unit Z vector
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void TriangleTest::testTransformedIntersection()
{
	// offset 10 units in X, looking down -Z axis
	Ray ray1(Vector3d(10, 0, 10), Vector3d(0, 0, -1));

	// translate triangle 10 units in X
	NodePointer translation(new TranslationNode(10, 0, 0));
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0), translation);

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info != 0);

	QCOMPARE(info->time, 10.0);

	//triangle normal is still the unit Z vector
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void TriangleTest::testAngledIntersection()
{
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	Vector3d origin(10, 0, 10);
	Vector3d direction = Vector3d::Zero() - origin;
	direction.normalize();
	Ray ray1(origin, direction);

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info != 0);

	//triangle normal is the unit Z vector
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void TriangleTest::testInPlaneRay()
{
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	Ray ray1(Vector3d(2, 0, 0), -1 * Vector3d::UnitX());

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info == 0);
}

void TriangleTest::testParallelRayMiss()
{
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	Ray ray1(Vector3d(2, 5, 0), -1 * Vector3d::UnitX());

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info == 0);
}

void TriangleTest::testNormalMiss()
{
	Ray ray1(Vector3d(10, 0, 10), Vector3d(0, 0, -1));

	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info == 0);
}

void TriangleTest::testAngledMiss()
{
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0));

	Vector3d origin(10, 0, 10);
	Vector3d direction = Vector3d(5, 0, 0) - origin;
	direction.normalize();
	Ray ray1(origin, direction);

	IntersectionInfoPointer info = triangle.intersect(ray1);
	QVERIFY(info == 0);
}

void TriangleTest::testRotatedIntersection()
{
	// ray on Z axis, looking down Z axis
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));
	//rotate triangle about Y axis by 45 degrees CCW
	Angle angle(Angle::degrees(45));
	NodePointer rotation(new RotationNode(angle, Vector3d(0, 1, 0)));
	//triangle situated on the Z=0 plane
	Triangle triangle(Vector3d(0, 1, 0), Vector3d(-1, -1, 0), Vector3d(1, -1, 0), rotation);

	IntersectionInfoPointer info = triangle.intersect(ray1);
	double sqrt2 = 1.414213562373095048801688724209;
	Vector3d expectedNormal(sqrt2 / 2, 0, sqrt2 / 2);

	QVERIFY(info != 0);
	QCOMPARE(info->time, 10.0);
	QVERIFY(info->normal.isApprox(expectedNormal));
}
