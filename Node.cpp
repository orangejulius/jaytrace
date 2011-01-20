#include "Node.h"

#include <QDebug>

#include "Material.h"

Node::Node(WeakNodePointer parent): parent(parent)
{

}

Node::~Node()
{
	qDebug()<<"Deleting Node "<<this;
}

Transform3d Node::getMatrixState()
{
	NodePointer strongParent = parent.toStrongRef();
	if (strongParent){
		return strongParent->getMatrixState();
	} else {
		Transform3d noTransform;
		noTransform.setIdentity();
		return noTransform;
	}
}

Matrix4d Node::getInverseMatrix()
{
	NodePointer strongParent = parent.toStrongRef();
	if (strongParent) {
		return strongParent->getInverseMatrix();
	} else {
		return Matrix4d::Identity();
	}
}

Material Node::getMaterial()
{
	NodePointer strongParent = parent.toStrongRef();
	if (strongParent) {
		return strongParent->getMaterial();
	} else {
		Material material;
		return material;
	}
}