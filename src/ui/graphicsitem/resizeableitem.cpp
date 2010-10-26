/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * resizeableitem.cpp
 *
 *  Created on: 06.09.2010
 *      Author: Robert Jakob
 */

#include "resizeableitem.h"
#include "../../exceptions.h"
#include <QApplication>
#include <QPainter>

namespace atuml {

ResizeableItem::ResizeableItem(const QRectF& rect, QGraphicsItem* parent, bool additionalHandles, int sizingSteps,
		int boxsize) :
	ConnectableItem(parent) {

	QGraphicsItem::setFlag(QGraphicsItem::ItemIsMovable);
	QGraphicsItem::setFlag(QGraphicsItem::ItemIsSelectable);

	this->fAdditionalHandles = additionalHandles;
	this->fSizingSteps = sizingSteps;
	this->fBoxSize = boxsize;

	this->currentState = STATE_NOTHING;
	this->activeHandle = -1;
	this->handleBrush = QBrush(QColor("#ffffff"));
	this->handleActiveBrush = QBrush(QColor("#000000"));

	this->updateHandles(rect);
}

void ResizeableItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget* /*widget*/) {
	if (this->isSelected()) {
		QBrush oldBrush = painter->brush();

		painter->setBrush(this->handleBrush);
		painter->drawRect(this->handlePos[0]);

		painter->setBrush(oldBrush);
	}
}

void ResizeableItem::updateHandles(const QRectF& rect) {
	// now calculating the handle center positions on all edges
	QPointF centerLeft(rect.left(), rect.center().y());
	QPointF centerRight(rect.right(), centerLeft.y());
	QPointF centerTop(rect.center().x(), rect.top());
    QPointF centerBottom(centerTop.x(), rect.bottom());

	handlePos[0] = QRectF(rect.topLeft(), rect.topLeft() + QPointF(this->fBoxSize, this->fBoxSize));
}

void ResizeableItem::setAdditionalHandles(const bool additionalHandles) {
	if (this->fAdditionalHandles != additionalHandles) {
		this->fAdditionalHandles = additionalHandles;
		this->update();
	}
}

bool ResizeableItem::additionalHandles() const {
	return fAdditionalHandles;
}

void ResizeableItem::setSizingSteps(const int sizingSteps) {
	if (this->fSizingSteps != sizingSteps) {
		this->fSizingSteps = sizingSteps;
		this->update();
	}
}

int ResizeableItem::sizingSteps() const {
	return fSizingSteps;
}

void ResizeableItem::setBoxSize(const int boxSize) {
	if (this->fBoxSize != boxSize) {
		this->fBoxSize = boxSize;
		this->update();
	}
}

int ResizeableItem::boxSize() const {
	return fBoxSize;
}

}
