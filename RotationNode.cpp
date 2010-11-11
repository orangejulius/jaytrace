#include "RotationNode.h"

RotationNode::RotationNode(double radians, Vector3d axis, NodePointer parent): TransformNode(parent), rotation(radians, axis)
{
	transform *= rotation;
}
