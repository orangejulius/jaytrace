#include "Node.h"

#include <QDebug>

Node::Node(NodePointer parent): parent(parent)
{

}

Node::~Node()
{
	qDebug()<<"Deleting Node "<<this;
}

Transform3d Node::getMatrixState()
{
	if (parent){
		return parent->getMatrixState();
	} else {
		Transform3d noTransform;
		noTransform.setIdentity();
		return noTransform;
	}
}
