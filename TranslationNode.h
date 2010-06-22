#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "TransformNode.h"

using Eigen::Translation3d;

class TranslationNode: public TransformNode
{
public:
	TranslationNode(double x, double y, double z, NodePointer parent = NodePointer(0));

protected:
	Translation3d translation;
};

#endif // TRANSLATION_H
