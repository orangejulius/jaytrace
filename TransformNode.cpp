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
	inverseMatrix = transform.matrix().inverse();
}

TransformNode::TransformNode(Affine3d t, NodePointer parent): Node(parent), transform(t)
{
	if (parent) {
		transform = parent->getMatrixState() * t;
	}
	inverseMatrix = transform.matrix().inverse();
}

Affine3d TransformNode::getMatrixState()
{
	return transform;
}

Matrix4d TransformNode::getInverseMatrix()
{
	return inverseMatrix;
}
