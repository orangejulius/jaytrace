#ifndef ANGLETEST_H
#define ANGLETEST_H

#include <QtTest/QtTest>

class AngleTest: public QObject
{
	Q_OBJECT
private slots:
	void testRadiansToDegrees();
	void testDegreesToRadians();
	void testAngleEquality();
	void testCopyConstructor();
	void testAssignmentOperator();
	void testAdditionOperator();
	void testSubtractionOperator();
	void testScalarMultiplicationOperator();
};

#endif // ANGLETEST_H
