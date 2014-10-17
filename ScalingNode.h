#ifndef SCALINGNODE_H
#define SCALINGNODE_H

#include "TransformNode.h"

using Eigen::AlignedScaling3d;

class ScalingNode: public TransformNode
{
public:
	ScalingNode(double x, double y, double z, NodePointer parent = NodePointer(0));

protected:
	AlignedScaling3d scaling;
};

#endif // TRANSLATION_H
