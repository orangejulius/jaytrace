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
	setCentralWidget(raytracerWidget);
	raytracerWidget->render();
}

void MainWindow::createActions()
{
	raytraceAction = new QAction(tr("Raytrace"), this);
	connect(raytraceAction, SIGNAL(triggered()), raytracerWidget, SLOT(render()));
}

void MainWindow::createToolbars()
{
	raytraceToolbar = addToolBar(tr("Raytrace"));
	raytraceToolbar->addAction(raytraceAction);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
	raytracerWidget->resize(size());
}

