#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

#include "Scene.h"

class OpenGLWidget;
class RaytracerWidget;

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

private slots:
	void setRaytrace();
	void setOpenGL();

private:
	void createActions();
	void createToolbars();

	void resizeEvent(QResizeEvent* event);

	QAction* raytraceAction;
	QAction* setRaytraceAction;

	QToolBar* openglToolbar;
	QToolBar* raytraceToolbar;

	OpenGLWidget* openglWidget;
	RaytracerWidget* raytracerWidget;

	ScenePointer scene;
};

#endif // MAINWINDOW_H_INCLUDED
