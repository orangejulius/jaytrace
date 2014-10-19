#include "TransformNode.h"

#include <Eigen/LU>

TransformNode::TransformNode(NodePointer parent): Node(parent)
{
	transform.setIdentity();
	if (parent) {
		transform = parent->getMatrixState();
	} else {
		transform.setIdentity();
	}
	inverseMatrix = transform.inverse();
}

TransformNode::TransformNode(Affine3d t, NodePointer parent): Node(parent), transform(t)
{
	if (parent) {
		transform = parent->getMatrixState() * t;
	}
	inverseMatrix = transform.inverse();
}

Affine3d TransformNode::getMatrixState()
{
	return transform;
}

Affine3d TransformNode::getInverseMatrix()
{
	return inverseMatrix;
}
