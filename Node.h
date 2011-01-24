#ifndef NODE_H
#define NODE_H

#include <Eigen/Geometry>
#include <list>
#include <QtGlobal>
#include <QSharedPointer>

using Eigen::Matrix4d;
using Eigen::Transform3d;
using std::list;

class Material;
class Node;

typedef QSharedPointer<Node> NodePointer;

class Node
{
public:
	Node(NodePointer parent = NodePointer(0));

	virtual ~Node();

	void addChild(Node* child);

	virtual Transform3d getMatrixState();

	virtual Matrix4d getInverseMatrix();

	virtual Material getMaterial();

protected:
        NodePointer parent;
		list<NodePointer> children;
};

#endif //NODE_H

