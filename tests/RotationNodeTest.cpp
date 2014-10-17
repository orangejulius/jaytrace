#include "RotationNodeTest.h"

#include "RotationNode.h"

using Eigen::Vector3d;
using Eigen::Translation3d;

void RotationNodeTest::testNoOp()
{
	RotationNode t1(Angle::degrees(0), Vector3d::UnitX());
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	QCOMPARE(actual, expected);
}

void RotationNodeTest::testAssignment()
{
	RotationNode rotationNode(Angle::degrees(90), Vector3d::UnitX());
	AngleAxisd a(Angle::degrees(90).getRadians(), Vector3d::UnitX());
	Affine3d transform(a);

	Matrix4d expected = transform.matrix();
	Matrix4d actual = rotationNode.getMatrixState().matrix();

	QCOMPARE(actual, expected);
}

void RotationNodeTest::testParent()
{
	Vector3d axis = Vector3d::UnitY();
	Angle angle1 = Angle::degrees(30);

	NodePointer rotationNode1(new RotationNode(angle1, axis));
	NodePointer rotationNode2(new RotationNode(Angle::degrees(0), axis, rotationNode1));

	AngleAxisd resultRotation(angle1.getRadians(), axis);
	Affine3d resultTransform(resultRotation);
	Matrix4d expected = resultTransform.matrix();
	Matrix4d actual = rotationNode2->getMatrixState().matrix();

	QCOMPARE(expected, actual);
}

void RotationNodeTest::testComposition()
{
	Angle angle1 = Angle::degrees(30);
	Angle angle2 = Angle::degrees(60);
	Angle angle3 = angle1 + angle2;
	Vector3d axis = Vector3d::UnitY();

	NodePointer rotationNode1(new RotationNode(angle1, axis));
	NodePointer rotationNode2(new RotationNode(angle2, axis, rotationNode1));

	AngleAxisd resultRotation(angle3.getRadians(), axis);
	Affine3d resultTransform(resultRotation);

	Matrix4d expected = resultTransform.matrix();
	Matrix4d actual = rotationNode2->getMatrixState().matrix();

	// fuzzy comparisons against zero are unreliable
	// add one to each element of the two matricies before comparing
	for(int i = 0; i < 16; i++) {
		QCOMPARE(actual.data()[i] + 1 , expected.data()[i] + 1);
	}
}
