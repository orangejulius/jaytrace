#ifndef TRIANGLETEST_H
#define TRIANGLETEST_H

#include <QtTest/QtTest>

class TriangleTest: public QObject
{
	Q_OBJECT
private slots:
	void testConstructor();
	void testNormalIntersection();
	void testTransformedIntersection();
	void testAngledIntersection();
	void testInPlaneRay();
	void testParallelRayMiss();
	void testNormalMiss();
	void testAngledMiss();
	void testRotatedIntersection();
};

#endif // TRIANGLETEST_H
