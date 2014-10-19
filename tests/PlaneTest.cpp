#include "PlaneTest.h"

#include "Ray.h"
#include "Plane.h"
#include "IntersectionInfo.h"
#include "RotationNode.h"
#include "TranslationNode.h"

void PlaneTest::testNormalIntersection()
{
	//create a ray starting along the Z axis, looking at origin
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	//defaults to the Z=0 plane
	Plane plane;

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info != 0);
	QCOMPARE(info->time, 10.0);
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void PlaneTest::testTranslatedIntersection()
{
	//create a ray starting along the Z axis, looking at origin
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	//move the plane away by 10
	NodePointer translation(new TranslationNode(0, 0, -10));

	//defaults to the Z=0 plane
	Plane plane(translation);

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info != 0);
	QCOMPARE(info->time, 20.0);
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void PlaneTest::testRotatedIntersection()
{
	//create a ray starting along the Z axis, at -10y, looking down Z axis
	Ray ray1(Vector3d(0, -10, 10), Vector3d(0, 0, -1));

	//rotate the plane 45 degrees around the X axis
	NodePointer rotation(new RotationNode(Angle::degrees(45), Vector3d::UnitX()));

	//defaults to the Z=0 plane
	Plane plane(rotation);

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info != 0);
	QCOMPARE(info->time, 20.0);

	Vector3d expectedNormal = rotation->getMatrixState() * Vector3d::UnitZ();
	QCOMPARE(info->normal[0], expectedNormal[0]);
	QCOMPARE(info->normal[1], expectedNormal[1]);
	QCOMPARE(info->normal[2], expectedNormal[2]);
}

void PlaneTest::testAngledIntersection()
{
	//defaults to the Z=0 plane
	Plane plane;

	Vector3d origin(10, 10, 10);
	Vector3d look = Vector3d::Zero();

	Vector3d direction = look - origin;
	direction.normalize();

	Ray ray1(origin, direction);

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info != 0);

	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void PlaneTest::testInPlaneRay()
{
	Plane plane;

	Ray ray1(Vector3d(0, 0, 0), Vector3d::UnitX() * -1);

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info == 0);
}

void PlaneTest::testParallelRayMiss()
{
	Plane plane;

	Ray ray1(Vector3d(2, 5, 0), -1 * Vector3d::UnitX());

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info == 0);
}

void PlaneTest::testNegativeHit()
{
	Plane plane;

	// ray starts at -10 Z, so hit time is negative
	Ray ray1(Vector3d(0, 0, -10), Vector3d::UnitX() * -1);

	IntersectionInfo* info = plane.intersect(ray1);
	QVERIFY(info == 0);
}
