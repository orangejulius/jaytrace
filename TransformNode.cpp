#include "TransformNode.h"

#include <Eigen/LU>

TransformNode::TransformNode(NodePointer parent): Node(parent)
{
	transform.setIdentity();
	if (parent) {
		transform = parent->getMatrixState();
	}
	inverseMatrix = transform.matrix().inverse();
}

TransformNode::TransformNode(Affine3d transform, NodePointer parent): Node(parent), transform(transform)
{
	if (parent) {
		transform = parent->getMatrixState();
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
