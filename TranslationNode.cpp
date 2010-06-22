#include "TranslationNode.h"

TranslationNode::TranslationNode(double x, double y, double z, NodePointer parent): TransformNode(parent), translation(Translation3d(x,y,z))
{
	transform *= translation;
}

