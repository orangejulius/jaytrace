#ifndef MAINWINDOW_H_INCLUDED
#define MAINWINDOW_H_INCLUDED

#include <QMainWindow>

class RaytracerWidget;

class MainWindow: public QMainWindow
{
	Q_OBJECT

public:
	MainWindow();

private:
	RaytracerWidget* raytracerWidget;
};

#endif // MAINWINDOW_H_INCLUDED
