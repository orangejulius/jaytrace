#ifndef ROTATIONNODE_H
#define ROTATIONNODE_H

#include "TransformNode.h"

using Eigen::AngleAxisd;
using Eigen::Vector3d;

class RotationNode: public TransformNode
{
public:
	RotationNode(double radians, Vector3d axis, NodePointer parent = NodePointer(0));

protected:
	AngleAxisd rotation;
};

#endif // ROTATIONNODE_H
