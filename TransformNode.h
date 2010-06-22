#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H

#include "CompositeNode.h"

using Eigen::Transform3d;

/* Class TransformNode
 *
 * This class handles the storage of the current matrix state.
 * It does not actually represent a generic transformation, which is currently unsupported.
 * Instead this class stores a Transform3d object for the transformation matrix that any child
 * nodes would use for rendering. Child nodes can store a reference to this matrix data and will
 * be told when the reference should be updated. In this way there is one precomputed source for
 * the transformation matrix that is always up to date and can be accessed by any node that is
 * transformed by it.
 */

class TransformNode : public CompositeNode
{
public:
	TransformNode(NodePointer parent = NodePointer(0));

	virtual Transform3d getMatrixState();

protected:
	Transform3d transform;
};

#endif // TRANSFORMNODE_H
