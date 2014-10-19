#include "CubeTest.h"

#include "Ray.h"
#include "Cube.h"
#include "IntersectionInfo.h"
#include "RotationNode.h"
#include "ScalingNode.h"
#include "TranslationNode.h"

void CubeTest::testBasicIntersection()
{
	//create a ray starting along the Z axis, looking at origin
	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	// the cube by default is centered at the origin
	// with corners at (+-1, +-1, +-1)
	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info != 0);

	//intersection will happen at (0,0,1), 9 time units from the ray's origin
	QCOMPARE(info->time, 9.0);

	//ray will hit the Z face, normal vector is (0, 0, 1)
	QCOMPARE(info->normal, Vector3d(0, 0, 1));
}

void CubeTest::testParallelOutsideRay()
{
	// ray offset from origin, perpendicular to Z axis faces
	Ray ray1(Vector3d(10, 0, 10), Vector3d(0, 0, -1));

	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info == 0);
}

void CubeTest::testParallelOnPlaneRay()
{
	// ray offset from origin, perpendicular to Z axis faces
	// it is exactly on the positive X plane of the square
	Ray ray1(Vector3d(1, 0, 10), Vector3d(0, 0, -1));

	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info == 0);
}

void CubeTest::testRotatedCube()
{
	Ray ray1(Vector3d(0.5, 0, 10), Vector3d(0, 0, -1));

	NodePointer rotation(new RotationNode(Angle::degrees(45), Vector3d::UnitY()));

	RayObjectPointer cube(new Cube(rotation));

	IntersectionInfo* info = cube->intersect(ray1);

	QVERIFY(info != 0);

	double sqrt2 = 1.414213562373095048801688724209;

	QCOMPARE(info->time, 10 + 0.5 - sqrt2);

	QCOMPARE(info->normal.x(), sqrt2 / 2);
	QCOMPARE(info->normal.y(), 0.0);
	QCOMPARE(info->normal.z(), sqrt2 / 2);
}

void CubeTest::testOriginInsideCube()
{
	Ray ray1(Vector3d(0, 0, 0), Vector3d(0, 0, -1));

	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info == 0);
}

void CubeTest::testTranslatedCube()
{
	NodePointer translation(new TranslationNode(10, 0, 0));
	RayObjectPointer cube(new Cube(translation));

	Ray ray1(Vector3d(0, 0, 10), Vector3d(0, 0, -1));
	IntersectionInfo* info1 = cube->intersect(ray1);
	QVERIFY(info1 == 0);

	Ray ray2(Vector3d(10, 0, 10), Vector3d(0, 0, -1));
	IntersectionInfo* info2 = cube->intersect(ray2);
	QVERIFY(info2 != 0);

	Vector3d expectedNormal(Vector3d::UnitZ());
	QCOMPARE(info2->normal.x(), expectedNormal.x());
	QCOMPARE(info2->normal.y(), expectedNormal.y());
	QCOMPARE(info2->normal.z(), expectedNormal.z());
}

void CubeTest::testAngledIntersection()
{
	Vector3d origin(2, 0, -1);
	Vector3d lookAt(0, 0, 1);

	Vector3d direction = lookAt - origin;
	direction.normalize();
	Ray ray1(origin, direction);

	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info != 0);
}

void CubeTest::testAngledMiss()
{
	Vector3d origin(3, 0, -2);
	Vector3d lookAt(0, 0, 3);

	Vector3d direction = lookAt - origin;
	direction.normalize();
	Ray ray1(origin, direction);

	Cube cube;

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info == 0);
}

void CubeTest::testTranslatedRotatedCube()
{
	//rotate 45 degrees around the Y axis
	NodePointer rotation(new RotationNode(Angle::degrees(45), Vector3d::UnitY()));

	// translate 10 units back in the Z direction
	NodePointer translate10Z(new TranslationNode(0, 0, -10, rotation));

	Cube cube(translate10Z);

	double sqrt2 = 1.414213562373095048801688724209;
	Vector3d cubeCenter(-10 * sqrt2/2, 0, -10 * sqrt2/2);

	Ray ray1(Vector3d(cubeCenter.x() + 1, 0, 0), Vector3d(0, 0, -1));

	IntersectionInfo* info = cube.intersect(ray1);
	QVERIFY(info != 0);

	// distance from ray to cube center, plus offset from Z axis,
	// minus distance from cube center to edge
	QCOMPARE(info->time, -cubeCenter.x() + 1.0 - sqrt2);

	QCOMPARE(info->normal.x(), sqrt2 / 2);
	QCOMPARE(info->normal.y(), 0.0);
	QCOMPARE(info->normal.z(), sqrt2 / 2);
}

void CubeTest::testInvertedCube()
{
	NodePointer invert(new ScalingNode(-1, -1, -1));

	Cube cube(invert);

	Ray ray(Vector3d(0, 0, 10), Vector3d(0, 0, -1));

	IntersectionInfo* info = cube.intersect(ray);
	QVERIFY(info != 0);

	QCOMPARE(info->time, 9.0);

	QCOMPARE(info->normal.x(), 0.0);
	QCOMPARE(info->normal.y(), 0.0);
	QCOMPARE(info->normal.z(), 1.0);
}
