#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>
#include <QStackedWidget>

#include "Config.h"
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
	QAction* setOpenGLAction;
	QAction* setRaytraceAction;

	QToolBar* openglToolbar;
	QToolBar* raytraceToolbar;

	OpenGLWidget* openglWidget;
	RaytracerWidget* raytracerWidget;

	QStackedWidget* stackedWidget;

	ConfigPointer config;
	ScenePointer scene;
};

#endif // MAINWINDOW_H_INCLUDED
