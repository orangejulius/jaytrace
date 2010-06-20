#include "tests/RayTest.h"
#include "tests/SceneGraphTest.h"

int main()
{
	RayTest rayTest;
	SceneGraphTest sceneGraphTest;

	int result = 0;

	result += QTest::qExec(&rayTest);
	result += QTest::qExec(&sceneGraphTest);

	return result != 0;
}
