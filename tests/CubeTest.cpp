#include "CubeTest.h"

#include "Ray.h"
#include "Cube.h"
#include "IntersectionInfo.h"

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
