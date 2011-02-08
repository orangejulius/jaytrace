#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

#include "Scene.h"

class RaytracerWidget;

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

private:
	void createActions();
	void createToolbars();

	QAction* raytraceAction;

	QToolBar* raytraceToolbar;

	RaytracerWidget* raytracerWidget;

	ScenePointer scene;
};

#endif // MAINWINDOW_H_INCLUDED
