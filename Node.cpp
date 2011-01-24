#include "Node.h"

#include <QDebug>

#include "Material.h"

Node::Node(NodePointer parent): parent(parent)
{
	if (parent) {
		parent->addChild(this);
		qDebug()<<"Adding "<<this<<" as child of "<<parent.data();
	} else {
		qDebug()<<this<<"has invalid parent: "<<parent.data();
	}
}

Node::~Node()
{
	qDebug()<<"Deleting Node "<<this;
}

void Node::addChild(Node* child)
{
	children.push_back(NodePointer(child));
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

Matrix4d Node::getInverseMatrix()
{
	if (parent) {
		return parent->getInverseMatrix();
	} else {
		return Matrix4d::Identity();
	}
}

Material Node::getMaterial()
{
	if (parent) {
		return parent->getMaterial();
	} else {
		Material material;
		return material;
	}
}