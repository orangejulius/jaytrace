#include "ScalingNode.h"

#include <Eigen/LU>

ScalingNode::ScalingNode(double x, double y, double z, NodePointer parent): TransformNode(parent), scaling(x, y, z)
{
	transform *= scaling;
	inverseMatrix = transform.inverse();
}
