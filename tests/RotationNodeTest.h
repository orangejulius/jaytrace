#ifndef ROTATIONNODETEST_H
#define ROTATIONNODETEST_H

#include <QtTest/QtTest>

class RotationNodeTest: public QObject
{
	Q_OBJECT
private slots:
	void testNoOp();
	void testAssignment();
	void testParent();
	void testRotationComposition();
};
#endif // ROTATIONNODETEST_H
