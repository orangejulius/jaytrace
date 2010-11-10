#ifndef POISSON_H
#define POISSON_H

#include <Eigen/Core>
#include <list>

using Eigen::Vector2d;
using std::list;


class Poisson
{
public:
	Poisson(int maxIterations);
	void clear();
	Vector2d generate();

protected:
	double minDistance;//stores the *SQUARE* of the minimum distance allowed between points
	list <Vector2d> history;
};

#endif // POISSON_H
