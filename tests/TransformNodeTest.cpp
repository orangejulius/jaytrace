#include "TransformNodeTest.h"

#include "TransformNode.h"

using Eigen::Matrix4d;

void TransformNodeTest::testNoOp()
{
	TransformNode t1;
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	QCOMPARE(actual, expected);
}
