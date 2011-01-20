#include "MainWindow.h"

#include <QAction>
#include <QMenu>
#include <QMenuBar>

#include "MainWidget.h"

MainWindow::MainWindow()
{
	setWindowTitle(tr("Jaytrace"));

	widget = new MainWidget();
	setCentralWidget(widget);

	//create actions and menus
	render = new QAction(tr("&Render"), this);

	raytraceMenu = menuBar()->addMenu(tr("Raytrace"));
	raytraceMenu->addAction(render);
}
