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
	void testOriginInsideCube();
	void testTranslatedCube();
	void testAngledIntersection();
	void testAngledMiss();
	void testTranslatedRotatedCube();
	void testInvertedCube();
};

#endif // CUBETEST_H
