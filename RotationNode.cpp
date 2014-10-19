#include "RotationNode.h"

#include <Eigen/LU>

RotationNode::RotationNode(Angle angle, Vector3d axis, NodePointer parent): TransformNode(parent), rotation(angle.getRadians(), axis)
{
	transform *= rotation;
	inverseMatrix = transform.matrix().inverse();
}
