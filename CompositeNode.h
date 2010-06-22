#ifndef COMPOSITENODE_H
#define COMPOSITENODE_H

#include <list>
#include "Node.h"

using std::list;

class CompositeNode: public Node
{
public:
	CompositeNode(NodePointer parent = NodePointer(0));
	virtual ~CompositeNode();

	void addChild(NodePointer child);

protected:
	list<NodePointer> children;
};

typedef QSharedPointer<CompositeNode> CompositeNodePointer;

#endif // COMPOSITENODE_H
