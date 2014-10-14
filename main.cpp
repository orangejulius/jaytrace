#include "Camera.h"
#include "RaytraceRenderer.h"
#include "SpiralScene.h"

#include <cmath>
#include <QDate>

int main()
{
	ScenePointer scene(new SpiralScene());
	RaytraceRenderer raytraceRenderer(scene);

	QImage output = raytraceRenderer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
