#ifndef NODE_H
#define NODE_H

#include <Eigen/Geometry>
#include <QtGlobal>
#include <QSharedPointer>

using Eigen::Affine3d;

class Material;
class Node;

typedef QSharedPointer<Node> NodePointer;

class Node
{
public:
	Node(NodePointer parent = NodePointer(0));

	virtual ~Node();

	virtual Affine3d getTransform();

	virtual Affine3d getInverseTransform();

	virtual Material getMaterial();

protected:
	NodePointer parent;
};

#endif //NODE_H
