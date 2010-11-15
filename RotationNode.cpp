#include "RotationNode.h"

#include <Eigen/LU>

RotationNode::RotationNode(double radians, Vector3d axis, NodePointer parent): TransformNode(parent), rotation(radians,axis)
{
	transform *= rotation;
	inverseMatrix = transform.matrix().inverse();
}
