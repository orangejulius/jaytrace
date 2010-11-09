#include "SceneGraphTest.h"

#include <Eigen/Geometry>
#include <iostream>
#include "ScalingNode.h"
#include "TranslationNode.h"

using Eigen::Matrix4d;
using std::cout;
using std::endl;

Q_DECLARE_METATYPE(Matrix4d)

void SceneGraphTest::testCreation()
{
	NodePointer n1(new Node());
	qDebug() << "Created Node " << n1.data();
	NodePointer n2(new Node(n1));
	qDebug() << "Created Node " << n2.data();
	NodePointer n3(new Node(n2));
	qDebug() << "Created Node " << n3.data();
}

void SceneGraphTest::testSingleTransformNode()
{
	TransformNode t1;
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	cout << "expected: " << endl << expected << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected);
}

void SceneGraphTest::testSingleTranslationNode()
{
	TranslationNode t1(0, 0, 0);
	Matrix4d expected = Matrix4d::Identity();
	Matrix4d actual = t1.getMatrixState().matrix();
	cout << "expected: " << endl << expected << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected);
}

void SceneGraphTest::testScalingNodeParent()
{
	NodePointer t1(new ScalingNode(1, 5, 1));
	NodePointer n1(new Node(t1));
	Transform3d expected;
	expected.setIdentity();
	Scaling3d expectedScaling(1, 5, 1);
	expected *= expectedScaling;
	Matrix4d actual = n1->getMatrixState().matrix();
	cout << "expected: " << endl << expected.matrix() << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected.matrix());
}

void SceneGraphTest::testScalingNodeParents()
{
	NodePointer t1(new ScalingNode(1, 5, 1));
	NodePointer t2(new ScalingNode(4, 1, 1, t1));
	NodePointer n1(new Node(t2));
	Transform3d expected;
	expected.setIdentity();
	Scaling3d expectedScaling(4, 5, 1);
	expected *= expectedScaling;
	Matrix4d actual = n1->getMatrixState().matrix();
	cout << "expected: " << endl << expected.matrix() << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected.matrix());
}

void SceneGraphTest::testTranslationNodeParent()
{
	NodePointer t1(new TranslationNode(0, 5, 0));
	NodePointer n1(new Node(t1));
	Transform3d expected;
	expected.setIdentity();
	Translation3d expectedTranslation(0, 5, 0);
	expected *= expectedTranslation;
	Matrix4d actual = n1->getMatrixState().matrix();
	cout << "expected: " << endl << expected.matrix() << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected.matrix());
}

void SceneGraphTest::testTranslationNodeParents()
{
	NodePointer t1(new TranslationNode(0, 5, 0));
	NodePointer t2(new TranslationNode(4, 0, 0, t1));
	NodePointer n1(new Node(t2));
	Transform3d expected;
	expected.setIdentity();
	Translation3d expectedTranslation(4, 5, 0);
	expected *= expectedTranslation;
	Matrix4d actual = n1->getMatrixState().matrix();
	cout << "expected: " << endl << expected.matrix() << endl;
	cout << "actual: " << endl << actual << endl;
	QCOMPARE(actual, expected.matrix());
}
