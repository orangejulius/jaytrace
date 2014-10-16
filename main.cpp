#include "Camera.h"
#include "RaytraceRenderer.h"
#include "CubeScene.h"

#include <cmath>
#include <QDate>

int main()
{
	ScenePointer scene(new CubeScene());
	RaytraceRenderer raytraceRenderer(scene);

	QImage output = raytraceRenderer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
