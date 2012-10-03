#include "AngleTest.h"

#include "Angle.h"

void AngleTest::testAngleCreation()
{
	Angle a1 = Angle::radians(PI/2);

	QVERIFY(a1.getRadians() == PI/2);
}
