#include "Cube.h"

#include "IntersectionInfo.h"
#include "Ray.h"

#include <QDebug>

Cube::Cube(NodePointer parent): Node(parent)
{

}

Cube::~Cube()
{
	qDebug() << "Deleting Cube " << this;
}

IntersectionInfo* Cube::intersect(const Ray& ray)
{
	double tIn = 0.000000001, tOut = 100000000.0;

	IntersectionInfo* info = 0;

	Ray genericRay = ray.getTransformedRay(getInverseMatrix());

	// check each face in x, y, z order
	for(int axis = 0; axis < 3; axis++) {
		// check the positive and negative face for each axis
		for (int magnitude = -1; magnitude <= 1; magnitude += 2) {
			double numerator = 1.0 - magnitude * genericRay.getOrigin()[axis];
			double denominator = magnitude * genericRay.getDirection()[axis];

			// check for parallel ray
			if (denominator == 0) {
				if (numerator <= 0) {
					//ray is never inside cube
					//note this includes rays exactly in the plane of one face
					return 0;
				}
			} else {
				double tHit = numerator / denominator;

				if (denominator > 0) {
					//exiting cube, simply keep track of tOut
					if (tHit < tOut) {
						tOut = tHit;
					}
				} else {
					if (tHit > tIn) {
						//this is a new latest hit going in
						tIn = tHit;

						if (info) {
							delete info;
						}

						info = new IntersectionInfo();
						info->object = this;
						info->time = tHit;
						info->normal = getFaceNormal(axis, magnitude);
					}
				}
			}
			if (tIn >= tOut) {
				return 0; // ray misses cube
			}
		}
	}
	return info;
}

Vector3d Cube::getFaceNormal(int axis, int magnitude)
{
	Vector3d normal(0, 0, 0);
	normal[axis] = magnitude;

	return getMatrixState().linear() * normal;
}
