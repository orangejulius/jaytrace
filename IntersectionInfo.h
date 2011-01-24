#ifndef INTERSECTIONINFO_H
#define INTERSECTIONINFO_H

#include <Eigen/Core>

#include "Node.h"

using Eigen::Vector3d;

class IntersectionInfo
{
public:
	Vector3d normal;
	double time;
	Node* object;
};

#endif // INTERSECTIONINFO_H
