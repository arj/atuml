/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * classgraphicsitem.cpp
 *
 *  Created on: 21.08.2010
 *      Author: Robert Jakob
 */

#include "classgraphicsitem.h"

namespace uml {

namespace ui {

ClassGraphicsItem::ClassGraphicsItem(const QString name, QGraphicsItem* parent) :
	uml::Class(name), QGraphicsItem(parent) {

	prepareGeometryChange();
	myRect = QRectF(10, 10, 400, 400);
	setPos(0,0);
}

ClassGraphicsItem::~ClassGraphicsItem() {
}

QRectF ClassGraphicsItem::boundingRect() const {
	QRectF r = myRect;
	r.translate(pos());
	return r;
}

void ClassGraphicsItem::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* options, QWidget* widget) {
	QRectF r = myRect;
	r.translate(pos());

	painter->drawRoundRect(r, 10, 10);
}

}

}
