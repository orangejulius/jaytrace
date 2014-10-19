#ifndef TRANSFORMNODE_H
#define TRANSFORMNODE_H

#include "Node.h"

using Eigen::Affine3d;

/* Class TransformNode
 *
 * This class handles the storage of the current matrix state.
 * It can store an arbitrary transformation matrix, but is primarily used by subclassing it and
 * creating a cleaner interface around a specific transformation (rotation, translation, etc)
 */

class TransformNode : public Node
{
public:
	TransformNode(NodePointer parent = NodePointer(0));

	/// Store an arbitrary transformation
	TransformNode(Affine3d t, NodePointer parent = NodePointer(0));

	virtual Affine3d getTransform();

	virtual Affine3d getInverseMatrix();

protected:
	Affine3d transform;
	Affine3d inverseMatrix;
};

#endif // TRANSFORMNODE_H
