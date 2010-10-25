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
		const QStyleOptionGraphicsItem* options, QWidget* /*widget*/) {

	QBrush brush(QColor("#edff00"));

	if (options->state & QStyle::State_Selected) {
		brush.setColor(QColor("#b7ff00"));
	}

	QRectF pRect = myRect;

	painter->drawRect(pRect);
	painter->fillRect(pRect, brush);

	if (active()) {
		pRect.adjust(5,0,-5,0);

		painter->drawRect(pRect);
		painter->fillRect(pRect, brush);
	}


	QFont font(painter->font());
	font.setPointSize(12);
	font.setBold(true);
	painter->setFont(font);

	painter->drawText(pRect.translated(0,10), Qt::AlignHCenter, this->name());
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
