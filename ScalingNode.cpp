#include "ScalingNode.h"

ScalingNode::ScalingNode(double x, double y, double z, NodePointer parent): TransformNode(parent), scaling(x, y, z)
{
	transform *= scaling;
}
