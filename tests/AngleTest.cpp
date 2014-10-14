#include "AngleTest.h"

#include "Angle.h"

void AngleTest::testRadiansToDegrees()
{
	Angle a1 = Angle::radians(PI/2);

	QCOMPARE(a1.getDegrees(), 90.);
}

void AngleTest::testDegreesToRadians()
{
	Angle a1 = Angle::degrees(90.);

	QCOMPARE(a1.getRadians(), PI/2);
}

void AngleTest::testAngleEquality()
{
	Angle a1 = Angle::radians(PI/2);
	Angle a2 = Angle::radians(PI/2);

	QVERIFY(a1 == a2);
}

// the default C++ copy constructor is sufficient at the moment
void AngleTest::testCopyConstructor()
{
	Angle a1 = Angle::radians(PI);
	Angle a2 = a1;

	QCOMPARE(a2.getRadians(), PI);
}
