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
