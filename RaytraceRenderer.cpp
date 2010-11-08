#include "RaytraceRenderer.h"

#include <Eigen/Core>
#include <QtDebug>

#include "Ray.h"

using Eigen::Vector3d;

const float PI = 3.1415926535897932384626;

RaytraceRenderer::RaytraceRenderer()
{

}

RaytraceRenderer::~RaytraceRenderer()
{

}

QImage RaytraceRenderer::render()
{
	for (list<RayObjectPointer>::iterator it = objects.begin(); it != objects.end(); it++) {
		intersectionLibrary.addObject(*it);
	}

	float yMin = -tan(projectionAngle * PI / 360);
	float yHeight = -2 * yMin;

	float xMin = aspectRatio * yMin;
	float xWidth = -2 * xMin;

	image = QImage(width, height, QImage::Format_RGB32);

	image.fill(0xff000000);

	for (unsigned int row = 0; row < height; row++) {
		for (unsigned int col = 0; col < width; col++) {
			float x = xMin + (col + .5) / width * xWidth;
			float y = yMin + ((height - row) + .5) / height * yHeight;
			float z = -1;

			Vector3d origin(0, 0, 0);
			Vector3d direction(x, y, z);
			direction.normalize();

			Ray pixelRay(origin, direction);

			IntersectionInfo* info = intersectionLibrary.intersect(pixelRay);
			if (info) {
				image.setPixel(col, row, 0xff000099);
			}
		}
	}

	return image;
}
