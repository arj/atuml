#include "mainwindow.h"
#include <QGraphicsEllipseItem>
#include "advancedgraphicsscene.h"
#include "graphicsitem/classgraphicsitem.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent) {
	ui.setupUi(this);

	scene = new AdvancedGraphicsScene(0, 0, 400, 300);

	ui.graphicsView->setScene(scene);

	uml::ui::ClassGraphicsItem* item = new uml::ui::ClassGraphicsItem("Window");
	((uml::Class*) item)->setActive(true);
	scene->addItem(item);


	srand ( time(NULL) );

	for (int i=0;i<10;i++) {
		uml::ui::ClassGraphicsItem* item2 = new uml::ui::ClassGraphicsItem("Widget");
		qreal x = (float) rand() / (float) RAND_MAX * 100;
		qreal y = (float) rand() / (float) RAND_MAX * 100;
		item2->setPos(x,y);
		scene->addItem(item2);
	}

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
