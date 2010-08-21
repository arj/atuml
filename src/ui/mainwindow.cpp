#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new QGraphicsScene(0,0,400,300);

	ui.graphicsView->setScene(scene);

	scene->addEllipse(10,10,200,200);

	ui.graphicsView->setZoom(1.5);
}

MainWindow::~MainWindow()
{
	delete scene;
}
