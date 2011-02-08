#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

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
};

#endif // MAINWINDOW_H_INCLUDED
