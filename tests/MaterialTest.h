#ifndef MATERIALTEST_H
#define MATERIALTEST_H

#include <QtTest/QtTest>

class MaterialTest: public QObject
{
	Q_OBJECT
private slots:
	void testMaterialCreation();
	void testSingleParent();
	void testMultipleParents();
};

#endif // MATERIALTEST_H
