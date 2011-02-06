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
	RaytracerWidget* raytracerWidget;
};

#endif // MAINWINDOW_H_INCLUDED
