#include "SceneGraphTest.h"

#include "CompositeNode.h"

void SceneGraphTest::testCreation()
{
	CompositeNodePointer c1(new CompositeNode());
	qDebug()<<"Created CompositeNode "<<c1.data();
	NodePointer c2(new CompositeNode());
	qDebug()<<"Created CompositeNode "<<c2.data();
	NodePointer n1(new Node());
	qDebug()<<"Created Node "<<n1.data();
	c1->addChild(n1);
	c1->addChild(c2);
}
