#include "MainWidget.h"

#include <QtGui>
#include "Sphere.h"

MainWidget::MainWidget(QWidget* parent) : QGLWidget(parent)
{

}

QSize MainWidget::minimumSizeHint() const
{
	return QSize(320, 240);
}

QSize MainWidget::sizeHint() const
{
	return QSize(640, 480);
}