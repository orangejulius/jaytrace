#include "AngleTest.h"

#include "Angle.h"

void AngleTest::testAngleCreation()
{
	Angle a1 = Angle::radians(PI/2);
	Angle a2 = Angle::degrees(90);

	QVERIFY(a1.getRadians() == PI/2);
	QCOMPARE(a2.getDegrees(), 90.);
}
