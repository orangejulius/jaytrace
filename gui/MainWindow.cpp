#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include "OpenGLWidget.h"
#include "RaytracerWidget.h"

MainWindow::MainWindow()
{
	setWindowTitle(tr("Jaytrace"));

	raytracerWidget = new RaytracerWidget();
	openglWidget = new OpenGLWidget();
	scene = ScenePointer(new Scene(Scene::get4SphereScene()));
	raytracerWidget->setScene(scene);
	openglWidget->setScene(scene);

	createActions();
	createToolbars();

	setCentralWidget(raytracerWidget);
}

QSize MainWindow::minimumSizeHint() const
{
	return QSize(320, 240);
}

QSize MainWindow::sizeHint() const
{
	return QSize(640, 480);
}

void MainWindow::setRaytrace()
{
	raytraceToolbar->setVisible(true);
	openglToolbar->setVisible(false);
	setCentralWidget(raytracerWidget);
	raytracerWidget->render();
}

void MainWindow::setOpenGL()
{
	openglToolbar->setVisible(true);
	raytraceToolbar->setVisible(false);
	setCentralWidget(openglWidget);
}

void MainWindow::createActions()
{
	raytraceAction = new QAction(tr("Raytrace"), this);
	connect(raytraceAction, SIGNAL(triggered()), raytracerWidget, SLOT(render()));

	setOpenGLAction = new QAction(tr("Set OpenGL"), this);
	connect(setOpenGLAction, SIGNAL(triggered()), this, SLOT(setOpenGL()));

	setRaytraceAction = new QAction(tr("Set Raytrace"), this);
	connect(setRaytraceAction, SIGNAL(triggered()), this, SLOT(setRaytrace()));
}

void MainWindow::createToolbars()
{
	raytraceToolbar = addToolBar(tr("Raytrace"));
	raytraceToolbar->addAction(setOpenGLAction);
	raytraceToolbar->addAction(raytraceAction);

	openglToolbar = addToolBar(tr("OpenGL"));
	openglToolbar->addAction(setRaytraceAction);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
	raytracerWidget->resize(size());
}

