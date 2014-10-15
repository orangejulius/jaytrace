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
	double tIn = -100000000.0;

	IntersectionInfo* info = 0;

	Ray genericRay = ray.getTransformedRay(getInverseMatrix());

	// check each face in x, y, z order
	for(int axis = 0; axis < 3; axis++) {
		// check the positive and negative face for each axis
		for (int magnitude = -1; magnitude <= 1; magnitude += 2) {
			double numerator = 1.0 - genericRay.getOrigin()[axis];
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

				if (denominator < 0) {
					if (tHit > tIn) {
						//this is a new latest hit going in
						info = new IntersectionInfo();
						info->object = this;
						info->time = tHit;
						info->normal = getFaceNormal(axis, magnitude);
					}
				}
			}
		}
	}
	return info;
}

Vector3d Cube::getFaceNormal(int axis, int magnitude)
{
	Vector4d normal(0, 0, 0, 1);
	normal[axis] = magnitude;

	Matrix4d transformationMatrix = getMatrixState().matrix();

	Vector4d transformedNormal = transformationMatrix * normal;

	return transformedNormal.start<3>();
}
