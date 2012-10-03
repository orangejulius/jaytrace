#ifndef ANGLETEST_H
#define ANGLETEST_H

#include <QtTest/QtTest>

class AngleTest: public QObject
{
	Q_OBJECT
private slots:
	void testAngleEquality();
};

#endif // ANGLETEST_H
