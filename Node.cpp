#include "Node.h"

#include <QDebug>

#include "Material.h"

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