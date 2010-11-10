#include "Poisson.h"

#include <stdlib.h>

Poisson::Poisson(int maxIterations)
{
	minDistance = .25 / maxIterations;
}

void Poisson::clear()
{
	history.clear();
}

Vector2d Poisson::generate()
{
	bool valid = true;
	Vector2d p1;
	do {
		p1 = Vector2d((double)rand() / RAND_MAX, (double)rand() / RAND_MAX);
		valid = true;
		list<Vector2d>::iterator i;
		for (i = history.begin(); i != history.end(); i++) {
			Vector2d p2 = *i;

			if ((p1 - *i).squaredNorm() < minDistance) {
				valid = false;
			}
		}
	} while (false == valid);

	history.push_back(p1);
	return p1;
}
