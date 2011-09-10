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
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);

	// Cull backfacing polygons
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
}

void OpenGLWidget::resizeGL(int width, int height)
{
	aspectRatio = float(width) / height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Angle projectionAngle;
	if (config) {
		projectionAngle = config->projectionAngle;
	}
	gluPerspective(projectionAngle.getDegrees(), aspectRatio, 0.0001, 10000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	setOpenGLMatrix(scene->getCamera().getTransform());
	drawAxes();
}

void OpenGLWidget::setOpenGLMatrix(Transform3d transform)
{
	glLoadMatrixd(transform.data());
}

