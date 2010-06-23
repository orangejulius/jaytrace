#include "tests/RayTest.h"
#include "tests/SceneGraphTest.h"
#include "tests/SphereTest.h"

int main()
{
	RayTest rayTest;
	SceneGraphTest sceneGraphTest;
	SphereTest sphereTest;

	int result = 0;

	result += QTest::qExec(&rayTest);
	result += QTest::qExec(&sceneGraphTest);
	result += QTest::qExec(&sphereTest);

	return result != 0;
}
