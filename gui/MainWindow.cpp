#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include "RaytracerWidget.h"

MainWindow::MainWindow()
{
	setWindowTitle(tr("Jaytrace"));

	raytracerWidget = new RaytracerWidget();
	scene = ScenePointer(new Scene(Scene::get4SphereScene()));
	raytracerWidget->setScene(scene);

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

void MainWindow::createActions()
{
	raytraceAction = new QAction(tr("Raytrace"), this);
}

void MainWindow::createToolbars()
{
	raytraceToolbar = addToolBar(tr("Raytrace"));
	raytraceToolbar->addAction(raytraceAction);
}
