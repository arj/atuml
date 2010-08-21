/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * advancedgraphicsccene.cpp
 *
 *  Created on: 22.08.2010
 *      Author: Robert Jakob
 */

#include "advancedgraphicsscene.h"

AdvancedGraphicsScene::AdvancedGraphicsScene(qreal x, qreal y, qreal width,
		qreal height, QObject * parent) :
	QGraphicsScene(x, y, width, height, parent) {
}

AdvancedGraphicsScene::~AdvancedGraphicsScene() {
}

void AdvancedGraphicsScene::drawBackground(QPainter* painter, const QRectF& rect) {
	/*// Check for normalized rect!
	painter->setPen(Qt::blue);
	for (int x=rect.left();x<rect.right();x+=20) {
		for (int y=rect.top();y<rect.bottom();y+=20) {
			painter->drawPoint(x,y);
		}
	}*/
}
