#include "tests/AngleTest.h"
#include "tests/CameraTest.h"
#include "tests/CubeTest.h"
#include "tests/IntersectionLibraryTest.h"
#include "tests/MaterialTest.h"
#include "tests/PlaneTest.h"
#include "tests/RayTest.h"
#include "tests/RotationNodeTest.h"
#include "tests/SceneGraphTest.h"
#include "tests/SphereTest.h"
#include "tests/TransformNodeTest.h"

int main()
{
	AngleTest angleTest;
	CameraTest cameraTest;
	CubeTest cubeTest;
	IntersectionLibraryTest intersectionLibraryTest;
	MaterialTest materialTest;
	PlaneTest planeTest;
	RayTest rayTest;
	RotationNodeTest rotationNodeTest;
	SceneGraphTest sceneGraphTest;
	SphereTest sphereTest;
	TransformNodeTest transformNodeTest;

	QStringList testArguments;
	testArguments << " "<< "-silent";

	int result = 0;

	result += QTest::qExec(&angleTest, testArguments);
	result += QTest::qExec(&cameraTest, testArguments);
	result += QTest::qExec(&cubeTest, testArguments);
	result += QTest::qExec(&intersectionLibraryTest, testArguments);
	result += QTest::qExec(&materialTest, testArguments);
	result += QTest::qExec(&planeTest, testArguments);
	result += QTest::qExec(&rayTest, testArguments);
	result += QTest::qExec(&rotationNodeTest, testArguments);
	result += QTest::qExec(&sceneGraphTest, testArguments);
	result += QTest::qExec(&sphereTest, testArguments);
	result += QTest::qExec(&transformNodeTest, testArguments);

	if (result) {
		qDebug()<<"Tests failed\n";
		return 1;
	} else {
		return 0;
	}
}
