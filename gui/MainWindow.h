#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	QMenu* raytraceMenu;

	QAction* render;
};

#endif // MAINWINDOW_H_INCLUDED