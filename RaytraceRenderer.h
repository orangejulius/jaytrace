#ifndef RAYTRACERENDERER_H
#define RAYTRACERENDERER_H

#include <QImage>

#include "Renderer.h"

class RaytraceRenderer: public Renderer
{
public:
	RaytraceRenderer(ScenePointer scene, unsigned int width = 640, unsigned int height = 480, Angle projectionAngle = Angle::degrees(25));
	~RaytraceRenderer();

	QImage render();
};

#endif // RAYTRACERENDERER_H
