#include "Node.h"

#include <QDebug>

Node::~Node()
{
	qDebug()<<"Deleting Node "<<this;
}

