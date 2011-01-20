#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

class MainWidget;

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	MainWidget* widget;

	QMenu* raytraceMenu;

	QAction* render;
};

#endif // MAINWINDOW_H_INCLUDED