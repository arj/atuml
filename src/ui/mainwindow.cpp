#include "mainwindow.h"
#include <QGraphicsEllipseItem>
#include "advancedgraphicsscene.h"
#include "../uml/classgraphicsitem.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent) {
	ui.setupUi(this);

	scene = new AdvancedGraphicsScene(0, 0, 400, 300);

	ui.graphicsView->setScene(scene);

	/*QGraphicsEllipseItem* item = scene->addEllipse(10, 10, 200, 200);*/
	uml::ui::ClassGraphicsItem* item = new uml::ui::ClassGraphicsItem("Class1");
	scene->addItem(item);

	connect(ui.graphicsView, SIGNAL(mousePositionChanged(const QPointF)), this,
			SLOT(setMousePosition(const QPointF)));
}

void MainWindow::setMousePosition(const QPointF pos) {
	QString msg = QString("(%1 %2)").arg(pos.x(), 0, 'f', 2).arg(pos.y(), 0,
			'f', 2);

	// if (QGraphicsItem *item = scene->itemAt(pos)) {
	if (scene->itemAt(pos)) {
		ui.statusbar->showMessage(msg + " inside item");
	} else {
		ui.statusbar->showMessage(msg);
	}
}

MainWindow::~MainWindow() {
	delete scene;
}
