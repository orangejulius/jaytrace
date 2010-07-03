#ifndef INTERSECTIONINFO_H
#define INTERSECTIONINFO_H

#include <Eigen/Core>
#include <QSharedPointer>

#include "Node.h"

using Eigen::Vector3d;

class IntersectionInfo
{
public:
	Vector3d normal;
	double time;
	NodePointer object;
};

#endif // INTERSECTIONINFO_H
