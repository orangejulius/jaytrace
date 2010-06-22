#include "TransformNodeTest.h"

#include <iostream>
#include "TransformNode.h"

using Eigen::Matrix4d;
using std::cout;
using std::endl;

void TransformNodeTest::testSingle()
{
	TransformNode t1;
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	cout << "expected: " << endl << expected << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected);
}
