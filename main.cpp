#include "Raytracer.h"
#include <QDate>

int main()
{
	Raytracer raytracer(640, 480, Angle::degrees(25));

	ScenePointer scene(new Scene(Scene::getSpiralScene()));

	raytracer.setScene(scene);

	QImage output = raytracer.render();
	QString filename = QDateTime::currentDateTime().toString(Qt::ISODate) + ".png";
	output.save(filename, "PNG");
	return 0;
}
