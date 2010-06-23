#ifndef SPHERETEST_H
#define SPHERETEST_H

#include <QtTest/QtTest>

class SphereTest: public QObject
{
	Q_OBJECT
private slots:
	void testMultipleTransformParents();
	void testUntransformedIntersection();
	void testTransformedIntersection();
};

#endif // SPHERETEST_H

