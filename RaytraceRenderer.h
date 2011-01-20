#ifndef RAYTRACERENDERER_H
#define RAYTRACERENDERER_H

#include <QImage>

#include "Renderer.h"

class RaytraceRenderer: public Renderer
{
public:
	RaytraceRenderer();
	~RaytraceRenderer();

	QImage render();
};

#endif // RAYTRACERENDERER_H
