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
	uml::Class(name), BasicItem(parent) {

	setFlags(ItemIsMovable | ItemIsSelectable);

	QRectF myRect = QRectF(10, 10, 200, 200);
	myRect.translate(-myRect.center());

	this->setRect(myRect);

	setPos(10, 110);
}

ClassGraphicsItem::~ClassGraphicsItem() {
}

QRectF ClassGraphicsItem::boundingRect() const {
	QRectF m = rect();
	m.translate(-rect().center());

	return m;
}

void ClassGraphicsItem::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* options, QWidget* widget) {

	QBrush brush(QColor("#edff00"));

	if (options->state & QStyle::State_Selected) {
		brush.setColor(QColor("#b7ff00"));
	}

	QRectF pRect = rect();

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

	BasicItem::paint(painter, options, widget);
}

QPainterPath ClassGraphicsItem::shape() const {
	QPainterPath p;
	p.addRect(rect());
	return p;
}

QVariant ClassGraphicsItem::itemChange(GraphicsItemChange change,
		const QVariant& value) {
	return BasicItem::itemChange(change, value);
}

}

}

}
