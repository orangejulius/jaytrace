#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>

MainWindow::MainWindow()
{
	setWindowTitle(tr("Jaytrace"));

	render = new QAction(tr("&Render"), this);

	raytraceMenu = menuBar()->addMenu(tr("Raytrace"));
	raytraceMenu->addAction(render);
}
