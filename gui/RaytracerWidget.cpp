#include "RaytracerWidget.h"

RaytracerWidget::RaytracerWidget(QWidget* parent): QLabel(parent), raytracer(size().width(), size().height())
{
	QPixmap emptyPixmap = QPixmap(size());
	emptyPixmap.fill(Qt::black);
	setPixmap(emptyPixmap);
}

void RaytracerWidget::setConfig(ConfigPointer newConfig)
{
	raytracer.setConfig(newConfig);
}

void RaytracerWidget::setScene(ScenePointer newScene)
{
	raytracer.setScene(newScene);
}

void RaytracerWidget::resizeEvent(QResizeEvent* event)
{
	raytracer.resize(size().width(), size().height());
}

void RaytracerWidget::render()
{
	setPixmap(QPixmap::fromImage(raytracer.render()));
}
