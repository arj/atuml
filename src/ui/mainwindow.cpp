#include "mainwindow.h"
#include <QGraphicsEllipseItem>
#include "advancedgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new AdvancedGraphicsScene(0,0,400,300);

	ui.graphicsView->setScene(scene);

	QGraphicsEllipseItem* item = scene->addEllipse(10,10,200,200);
	item->setFlag(QGraphicsItem::ItemIsMovable, true);
}

MainWindow::~MainWindow()
{
	delete scene;
}
