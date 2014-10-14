#include "tests/AngleTest.h"
#include "tests/CameraTest.h"
#include "tests/IntersectionLibraryTest.h"
#include "tests/MaterialTest.h"
#include "tests/RayTest.h"
#include "tests/SceneGraphTest.h"
#include "tests/SphereTest.h"

int main()
{
	AngleTest angleTest;
	CameraTest cameraTest;
	IntersectionLibraryTest intersectionLibraryTest;
	MaterialTest materialTest;
	RayTest rayTest;
	SceneGraphTest sceneGraphTest;
	SphereTest sphereTest;

	int result = 0;

	result += QTest::qExec(&angleTest);
	result += QTest::qExec(&cameraTest);
	result += QTest::qExec(&intersectionLibraryTest);
	result += QTest::qExec(&materialTest);
	result += QTest::qExec(&rayTest);
	result += QTest::qExec(&sceneGraphTest);
	result += QTest::qExec(&sphereTest);

	if (result) {
		qDebug()<<"Tests failed\n";
		return 1;
	} else {
		return 0;
	}
}
