#ifndef RAYTRACERENDERER_H
#define RAYTRACERENDERER_H

#include "Renderer.h"

class RaytraceRenderer: public Renderer
{
public:
	RaytraceRenderer();
	~RaytraceRenderer();

	void render();
};

#endif // RAYTRACERENDERER_H
