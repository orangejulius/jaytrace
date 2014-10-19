#include "TransformNodeTest.h"

#include "TransformNode.h"

using Eigen::Matrix4d;
using Eigen::Vector3d;
using Eigen::Translation3d;
using Eigen::AngleAxisd;

void TransformNodeTest::testNoOp()
{
	TransformNode t1;
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	QCOMPARE(actual, expected);
}

void TransformNodeTest::testAssignment()
{
	//simply define a matrix in initialization and ensure it comes back out
	Matrix4d expected;
	expected << 1, 2, 3, 4,
			    5, 6, 7, 8,
				9, 0, 1, 2,
				3, 4, 5, 6;
	Affine3d transform(expected);

	TransformNode t1(transform);

	Matrix4d actual = t1.getMatrixState().matrix();
	QCOMPARE(actual, expected);
}

void TransformNodeTest::testParent()
{
	Affine3d translation(Translation3d(1, 2, 3));
	NodePointer t1(new TransformNode(translation));

	TransformNode t2(t1);

	QCOMPARE(t2.getMatrixState().matrix(), translation.matrix());
}

void TransformNodeTest::testComposition()
{

	Affine3d transform1(AngleAxisd(3, Vector3d::UnitX()));
	Affine3d transform2(Translation3d(1, 1, 1));
	Affine3d result(transform1 * transform2);

	NodePointer t1(new TransformNode(transform1));
	NodePointer t2(new TransformNode(transform2, t1));

	QCOMPARE(t2->getMatrixState().matrix(), result.matrix());
}
