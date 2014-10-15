#ifndef CUBETEST_H
#define CUBETEST_H

#include <QtTest/QtTest>

class CubeTest: public QObject
{
	Q_OBJECT
private slots:
	void testBasicIntersection();
};

#endif // CUBETEST_H
