#include "CameraTest.h"

#include <iostream>
#include "Camera.h"

using Eigen::Matrix4d;
using std::cout;
using std::endl;

void CameraTest::testStandard()
{
	Camera c1;
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = c1.getTransform().matrix();
	cout<<"expected: "<<endl<<expected<<endl;
	cout<<"actual: "<<endl<<actual<<endl;
	QVERIFY(actual.isApprox(expected));
}

void CameraTest::test1()
{
	Vector3d eye(10, 10, 10);
	Vector3d look(0, 0, 0);
	Vector3d up(0, 1, 0);
	Camera c1(eye, look, up);
	Matrix4d expected;
	expected<< 0.7071, 0, -0.7071, 0,
	-0.4082, 0.8165, -0.4082, 0,
	0.5774, 0.5774, 0.5774, -17.32,
	0, 0, 0, 1;

	Matrix4d actual = c1.getTransform().matrix();
	cout<<"expected: "<<endl<<expected<<endl;
	cout<<"actual: "<<endl<<actual<<endl;
	QVERIFY(actual.isApprox(expected,1));
}

void CameraTest::test2()
{
	Vector3d eye(4, 4, 4);
	Vector3d look(0, 1, 0);
	Vector3d up(2, 1, 0);
	Camera c1(eye, look, up);
	Matrix4d expected;
	expected<< 0.4364, -0.8729, 0.2182, 0.8729,
	0.6475, 0.1363, -0.7498, -0.1363,
	0.6247, 0.4685, 0.6247, -6.872,
	0, 0, 0, 1;

	Matrix4d actual = c1.getTransform().matrix();
	cout<<"expected: "<<endl<<expected<<endl;
	cout<<"actual: "<<endl<<actual<<endl;
	QVERIFY(actual.isApprox(expected,1));
}

void CameraTest::testSlide1()
{
	Vector3d eye(0, 10, 0);
	Vector3d look(0, 10, -1);
	Vector3d up(0, 1, 0);
	Vector3d slideDelta(0, 10, 0);

	Camera c1(eye, look, up);

	Camera c2;
	c2.slide(slideDelta);

	Matrix4d expected = c1.getTransform().matrix();
	Matrix4d actual = c2.getTransform().matrix();

	cout<<"expected: "<<endl<<expected<<endl;
	cout<<"actual: "<<endl<<actual<<endl;
	QVERIFY(actual.isApprox(expected));
}

void CameraTest::testSlide2()
{
	Vector3d eye1(0, 10, 0);
	Vector3d look1(0, 10, -1);
	Vector3d up1(1, 0, 0);
	Camera c1(eye1, look1, up1);

	Vector3d eye2(0, 5, 0);
	Vector3d look2(0, 5, -1);
	Vector3d up2(1, 0, 0);
	Vector3d slideDelta(5, 0, 0);
	Camera c2(eye2, look2, up2);
	c2.slide(slideDelta);

	Matrix4d expected = c1.getTransform().matrix();
	Matrix4d actual = c2.getTransform().matrix();

	cout<<"expected: "<<endl<<expected<<endl;
	cout<<"actual: "<<endl<<actual<<endl;
	QVERIFY(actual.isApprox(expected));
}
