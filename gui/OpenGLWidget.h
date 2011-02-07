#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

#include "SceneObjectVisitor.h"

class OpenGLWidget: public QGLWidget, public SceneObjectVisitor
{
	Q_OBJECT
public:
	virtual void visit(const Sphere* sphere);
};

#endif // OpenGLWidget

