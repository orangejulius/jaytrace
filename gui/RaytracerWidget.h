#ifndef RAYTRACERWIDGET_H
#define RAYTRACERWIDGET_H

#include <QLabel>

#include "Raytracer.h"

class RaytracerWidget: public QLabel
{
	Q_OBJECT

public:
	RaytracerWidget(QWidget* parent = 0);

	void setConfig(ConfigPointer newConfig);
	void setScene(ScenePointer newScene);

	void resizeEvent(QResizeEvent* event);

public slots:
	void render();

protected:
	Raytracer raytracer;
};

#endif // RAYTRACERWIDGET_H