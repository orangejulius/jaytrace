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
