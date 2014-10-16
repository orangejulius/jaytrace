#ifndef PLANETEST_H
#define PLANETEST_H

#include <QtTest/QtTest>

class PlaneTest: public QObject
{
	Q_OBJECT
private slots:
	void testNormalIntersection();
	void testTranslatedIntersection();
	void testRotatedIntersection();
	void testAngledIntersection();
	void testInPlaneRay();
	void testParallelRayMiss();
	void testNegativeHit();
};

#endif // PLANETEST_H
