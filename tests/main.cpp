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

	QStringList testArguments;
	testArguments << " "<< "-silent";

	int result = 0;

	result += QTest::qExec(&angleTest, testArguments);
	result += QTest::qExec(&cameraTest, testArguments);
	result += QTest::qExec(&intersectionLibraryTest, testArguments);
	result += QTest::qExec(&materialTest, testArguments);
	result += QTest::qExec(&rayTest, testArguments);
	result += QTest::qExec(&sceneGraphTest, testArguments);
	result += QTest::qExec(&sphereTest, testArguments);

	if (result) {
		qDebug()<<"Tests failed\n";
		return 1;
	} else {
		return 0;
	}
}
