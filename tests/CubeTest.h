#ifndef CUBETEST_H
#define CUBETEST_H

#include <QtTest/QtTest>

class CubeTest: public QObject
{
	Q_OBJECT
private slots:
	void testBasicIntersection();
	void testParallelOutsideRay();
	void testParallelOnPlaneRay();
	void testRotatedCube();
};

#endif // CUBETEST_H
