#include "RaytracerWidget.h"

RaytracerWidget::RaytracerWidget(QWidget* parent): QLabel(parent), raytracer(size().width(), size().height())
{
	QPixmap emptyPixmap = QPixmap(size());
	emptyPixmap.fill(Qt::black);
	setPixmap(emptyPixmap);
}
