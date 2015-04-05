#include "Camera.h"
#include "RaytraceRenderer.h"
#include "OBJScene.h"

#include <cmath>
#include <QDate>

int main(int argc, char* argv[])
{
	unsigned int rows = 640;
	unsigned int cols = 480;
	unsigned int aaSamples = 1;

	if (argc > 2) {
			rows = atoi(argv[1]);
			cols = atoi(argv[2]);
	}

	if (argc > 3) {
		aaSamples = atoi(argv[3]);
	}
	ScenePointer scene(new OBJScene());
	RaytraceRenderer raytraceRenderer(scene, rows, cols, aaSamples);

	QImage output = raytraceRenderer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
