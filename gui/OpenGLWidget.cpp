#include "OpenGLWidget.h"

void OpenGLWidget::visit(const Sphere* sphere)
{
}

void OpenGLWidget::setScene(ScenePointer newScene)
{
	scene = newScene;
}

void OpenGLWidget::drawAxes()
{
	glDisable(GL_LIGHTING);

	glBegin(GL_LINES);
	int size = 500;
	glColor3d(1., 0., 0.);
	glVertex3d(0., 0., 0.);
	glVertex3d(size, 0., 0.);

	glColor3d(0., 1., 0.);
	glVertex3d(0., 0., 0.);
	glVertex3d(0., size, 0.);

	glColor3d(0., 0., 1.);
	glVertex3d(0., 0., 0.);
	glVertex3d(0., 0., size);

	glEnd();
	glEnable(GL_LIGHTING);
}

void OpenGLWidget::setConfig(ConfigPointer newConfig)
{
	config = newConfig;
}

void OpenGLWidget::initializeGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLWidget::resizeGL(int width, int height)
{
	aspectRatio = size().width()/size().height();
}

void OpenGLWidget::paintGL()
{
	drawAxes();
}

