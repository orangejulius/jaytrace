#include "Raytracer.h"
#include <QDate>

int main()
{
	ConfigPointer config(new Config);
	config->projectionAngle = Angle::degrees(25);
	Raytracer raytracer(640, 480);

	raytracer.setConfig(config);

	ScenePointer scene(new Scene(Scene::getSpiralScene()));

	raytracer.setScene(scene);

	QImage output = raytracer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
