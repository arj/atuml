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

namespace atuml {

namespace uml {

namespace ui {

ClassGraphicsItem::ClassGraphicsItem(const QString name, QGraphicsItem* parent) :
	uml::Class(name), ConnectableItem(parent) {

	setFlags(ItemIsMovable | ItemIsSelectable);

	myRect = QRectF(10, 10, 200, 200);
	myRect.translate(-myRect.center());
	setPos(10, 110);
}

ClassGraphicsItem::~ClassGraphicsItem() {
}

QRectF ClassGraphicsItem::boundingRect() const {
	QRectF m = myRect;
	m.adjust(-5,-5,5,5);
	m.translate(-myRect.center());

	return m;
}

void ClassGraphicsItem::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* options, QWidget* widget) {

	QPen pen;
	pen.setWidth(10);

	if (options->state & QStyle::State_Selected) {
		pen.setColor(QColor("green"));
	} else {
		pen.setColor(QColor("blue"));
	}

	painter->setPen(pen);

	/*QRectF m = myRect;
	m.translate(-myRect.center());*/

	painter->drawRoundRect(myRect);
	painter->drawPoint(QPoint(0,0));
}

QPainterPath ClassGraphicsItem::shape() const {
	QPainterPath p;
	p.addRoundRect(myRect,25,25);
	return p;
}

QVariant ClassGraphicsItem::itemChange(GraphicsItemChange change,
		const QVariant& value) {
	return QGraphicsItem::itemChange(change, value);
}

}

}

}
