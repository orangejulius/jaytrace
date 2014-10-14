#include "RotationNode.h"

#include <Eigen/LU>

RotationNode::RotationNode(Angle radians, Vector3d axis, NodePointer parent): TransformNode(parent), rotation(radians.getRadians(), axis)
{
	transform *= rotation;
	inverseMatrix = transform.matrix().inverse();
}
