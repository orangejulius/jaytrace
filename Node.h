#ifndef NODE_H
#define NODE_H

#include <Eigen/Geometry>
#include <QtGlobal>
#include <QSharedPointer>

using Eigen::Matrix4d;
using Eigen::Transform3d;

class Material;
class Node;

typedef QSharedPointer<Node> NodePointer;
typedef QWeakPointer<Node> WeakNodePointer;

class Node
{
public:
	Node(WeakNodePointer parent = WeakNodePointer());

	virtual ~Node();

	virtual Transform3d getMatrixState();

	virtual Matrix4d getInverseMatrix();

	virtual Material getMaterial();

protected:
        WeakNodePointer parent;
};

#endif //NODE_H

