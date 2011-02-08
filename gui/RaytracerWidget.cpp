#include "RaytracerWidget.h"

RaytracerWidget::RaytracerWidget(QWidget* parent): QLabel(parent)
{
	QPixmap emptyPixmap = QPixmap(size());
	emptyPixmap.fill(Qt::black);
	setPixmap(emptyPixmap);
}
