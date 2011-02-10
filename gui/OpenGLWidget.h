#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QGLWidget>

#include "Config.h"
#include "Scene.h"
#include "SceneObjectVisitor.h"

class OpenGLWidget: public QGLWidget, public SceneObjectVisitor
{
	Q_OBJECT
public:
	virtual void visit(const Sphere* sphere);
	void setScene(ScenePointer newScene);
	void drawAxes();

	void setConfig(ConfigPointer newConfig);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	ConfigPointer config;
	ScenePointer scene;

	float aspectRatio;
};

#endif // OpenGLWidget

