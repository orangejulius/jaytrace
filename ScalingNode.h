#ifndef SCALINGNODE_H
#define SCALINGNODE_H

#include "TransformNode.h"

using Eigen::Scaling3d;

class ScalingNode: public TransformNode
{
public:
	ScalingNode(double x, double y, double z, NodePointer parent = NodePointer(0));

protected:
	Scaling3d scaling;
};

#endif // TRANSLATION_H
