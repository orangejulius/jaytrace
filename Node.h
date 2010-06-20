#ifndef NODE_H
#define NODE_H

#include <QtGlobal>
#include <QSharedPointer>

class Node;

typedef QSharedPointer<Node> NodePointer;

class Node
{
public:
	Node() {};
	virtual ~Node();
};

#endif //NODE_H
