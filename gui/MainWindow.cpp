#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "RaytracerWidget.h"

MainWindow::MainWindow()
{
	setWindowTitle(tr("Jaytrace"));

	raytracerWidget = new RaytracerWidget();

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
