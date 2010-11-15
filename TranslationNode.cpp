#include "TranslationNode.h"

#include <Eigen/LU>

TranslationNode::TranslationNode(double x, double y, double z, NodePointer parent): TransformNode(parent), translation(x,y,z)
{
	transform *= translation;
	inverseMatrix = transform.matrix().inverse();
}

