#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QtTest/QtTest>

class CameraTest: public QObject
{
	Q_OBJECT
private slots:
	/// Test that the default camera settings do not move the camera
	void testStandard();

	/// Test an eye at 10, 10, 10 looking at the origin. no change to up
	void test1();

	/// Test an eye at 4, 4, 4 looking at 0, 1, 0. up is 2, 1, 0
	void test2();

	/**
	 * Basic test of slide
	 * Compare setting eye 0,10,0, look 0,10,-1 to
	 * Default eye and look coordinates with a slide up of 10
	 */
	void testSlide1();

	/**
	 * Another basic test of slide, but with non-default eye, look, and up values for both expected and actual
	 * Compare setting eye 0,10,0 look 0,10,-1 up 1,0,0 to
	 * eye 0,5,0 look 0,5,-1 up 1,0,0 and a slide of 5,0,0
	 */
	void testSlide2();

	/**
	 * Test Camera::rotateAroundLook().
	 * Compare eye 0,0,-2 look 0,0,-1 up 0,1,0 to a default camera rotated 180 degrees around the Y axis
	 */
	void testRotateAroundLook1();
};
#endif // CAMERATEST_H
