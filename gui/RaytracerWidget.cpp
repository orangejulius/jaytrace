#include "RaytracerWidget.h"

RaytracerWidget::RaytracerWidget(QWidget* parent): QLabel(parent), raytracer(size().width(), size().height())
{
	QPixmap emptyPixmap = QPixmap(size());
	emptyPixmap.fill(Qt::black);
	setPixmap(emptyPixmap);
}

void RaytracerWidget::setScene(ScenePointer newScene)
{
	raytracer.setScene(newScene);
}

void RaytracerWidget::render()
{
	setPixmap(QPixmap::fromImage(raytracer.render()));
}
