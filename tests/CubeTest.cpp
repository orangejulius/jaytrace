#include "CubeTest.h"

#include "Ray.h"
#include "Cube.h"
#include "IntersectionInfo.h"
#include "RotationNode.h"

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
