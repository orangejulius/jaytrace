#ifndef TRANSFORMNODETEST_H
#define TRANSFORMNODETEST_H

#include <QtTest/QtTest>

class TransformNodeTest: public QObject
{
	Q_OBJECT
private slots:
	void testNoOp();
	void testAssignment();
	void testParent();
	void testComposition();
};
#endif // TRANSFORMNODETEST_H
