#include "RayObject.h"

#include <QDebug>

RayObject::~RayObject()
{
	qDebug()<<"Deleting RayObject "<<this;
}
