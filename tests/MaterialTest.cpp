#include "MaterialTest.h"

#include "MaterialNode.h"

void MaterialTest::testMaterialCreation()
{
	Color red(1,0,0);
	Color green(0,1,0);
	Color blue(0,0,1);

	Material m1;
	m1.setAmbient(red);
	m1.setDiffuse(green);
	m1.setSpecular(blue);

	QVERIFY(m1.getAmbient() == red);
	QVERIFY(m1.getAmbient() != green);
	QVERIFY(m1.getDiffuse() == green);
	QVERIFY(m1.getSpecular() == blue);
}

void MaterialTest::testSingleParent()
{
	Color red(1,0,0);
	Color green(0,1,0);
	Color blue(0,0,1);

	MaterialNodePointer m1(new MaterialNode);
	m1->setAmbient(red);
	m1->setDiffuse(green);

	NodePointer n1(new Node(m1));

	QVERIFY(n1->getMaterial().getAmbient() == red);
	QVERIFY(n1->getMaterial().getDiffuse() == green);

	m1->setAmbient(blue);

	QVERIFY(n1->getMaterial().getAmbient() == blue);
}

void MaterialTest::testMultipleParents()
{
	Color red(1,0,0);
	Color green(0,1,0);
	Color blue(0,0,1);

	MaterialNodePointer m1 (new MaterialNode);
	MaterialNodePointer m2 (new MaterialNode(m1));

	NodePointer n1(new Node(m1));
	NodePointer n2(new Node(m2));

	m1->setAmbient(red);
	m2->setAmbient(blue);

	QVERIFY(n1->getMaterial().getAmbient() == red);
	QVERIFY(n2->getMaterial().getAmbient() == blue);
}
