#include "Node.h"

#include <QDebug>

#include "Material.h"

Node::Node(NodePointer parent): parent(parent)
{

}

Node::~Node()
{
	qDebug() << "Deleting Node " << this;
}

Affine3d Node::getTransform()
{
	if (parent) {
		return parent->getTransform();
	} else {
		Affine3d noTransform;
		noTransform.setIdentity();
		return noTransform;
	}
}

Affine3d Node::getInverseMatrix()
{
	if (parent) {
		return parent->getInverseMatrix();
	} else {
		return Affine3d::Identity();
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
