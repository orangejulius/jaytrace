#ifndef MAINWIDGET_H_INCLUDED
#define MAINWIDGET_H_INCLUDED

#include <QGLWidget>

#include "RaytraceRenderer.h"

class MainWidget: public QGLWidget
{
	Q_OBJECT

public:
	MainWidget(QWidget *parent = 0);

	QSize minimumSizeHint() const;
	QSize sizeHint() const;
};

#endif // MAINWIDGET_H_INCLUDED