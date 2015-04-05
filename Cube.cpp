#include "Cube.h"

#include "IntersectionInfo.h"
#include "jaytrace.h"
#include "Ray.h"

#include <QDebug>

Cube::Cube(NodePointer parent): Node(parent)
{

}

Cube::~Cube()
{
	qDebug() << "Deleting Cube " << this;
}

IntersectionInfoPointer Cube::intersect(const Ray& ray)
{
	double tIn = EPSILON, tOut = 100000000.0;

	IntersectionInfoPointer info;

	Ray genericRay = ray.getTransformedRay(getInverseTransform());

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
					return NoHit();
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

						info = IntersectionInfoPointer(new IntersectionInfo());
						info->object = this;
						info->time = tHit;
						info->normal = getFaceNormal(axis, magnitude);
					}
				}
			}
			if (tIn >= tOut) {
				return NoHit(); // ray misses cube
			}
		}
	}
	return info;
}

Vector3d Cube::getFaceNormal(int axis, int magnitude)
{
	Vector3d normal(0, 0, 0);
	normal[axis] = magnitude;

	return (getTransform().linear() * normal).normalized();
}
