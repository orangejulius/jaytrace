#ifndef RAYTEST_H
#define RAYTEST_H

#include <QtTest/QtTest>

class RayTest: public QObject
{
	Q_OBJECT
private slots:
	void getPosition();
	void getPosition_data();

	void getTransformedRay();
	void getTransformedRay_data();
};

#endif // RAYTEST_H

