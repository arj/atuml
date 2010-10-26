/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * basicitem.cpp
 *
 *  Created on: 26.10.2010
 *      Author: Robert Jakob
 */

#include "basicitem.h"
#include <QApplication>
#include <QPainter>

namespace atuml {

BasicItem::BasicItem(QGraphicsItem* parent) :
	QGraphicsRectItem(parent) {
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

	// TODO Check if this works with version 4.4 or 4.5
#if (QT_VERSION_CHECK(4,6,0))
	setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
#endif

	this->fAdditionalHandles = false;
	this->fSizingSteps = 5;
	this->fBoxSize = 8;

	this->currentState = STATE_NOTHING;
	this->activeHandle = None;
	this->handleBrush = QBrush(QColor("#ffffff"));
	this->handleActiveBrush = QBrush(QColor("#000000"));

	this->updateHandles(this->rect());
}

BasicItem::~BasicItem() {
}

void BasicItem::addConnection(Connection connection) {
	if (fConnections.contains(connection)) {
		throw new DoubleEntryException(qApp->translate("Exception",
				"Class does not allow an empty name."));
	}

	fConnections.append(connection);
}

void BasicItem::removeConnection(Connection connection) {
	fConnections.removeAll(connection);
}

void BasicItem::ItemChange(GraphicsItemChange change, const QVariant& value) {
	if (change == QGraphicsItem::ItemPositionChange) {
		trackConnections();
	}

	if (change == QGraphicsItem::ItemPositionHasChanged) {
		trackConnections();
	}

	QGraphicsRectItem::itemChange(change, value);
}

void BasicItem::trackConnections() {
	Connection c;
	foreach (c, fConnections)
		{
			c.trackNodes();
		}
}

void BasicItem::paint(QPainter* painter,
		const QStyleOptionGraphicsItem* /*option*/, QWidget* /*widget*/) {
	if (this->isSelected()) {
		QBrush oldBrush = painter->brush();

		painter->setBrush(this->handleBrush);
		for (int i = 0; i < 8; i++) {
			painter->drawRect(this->handlePos[i]);
		}

		painter->setBrush(oldBrush);
	}
}

void BasicItem::setRect(const QRectF& rectangle) {
	QGraphicsRectItem::setRect(rectangle);

	updateHandles(rectangle);
	trackConnections();
}

void BasicItem::updateHandles(const QRectF& rect) {
	// now calculating the handle center positions on all edges
	QPointF centerLeft(rect.left(), rect.center().y());
	QPointF centerRight(rect.right(), centerLeft.y());
	QPointF centerTop(rect.center().x(), rect.top());
	QPointF centerBottom(centerTop.x(), rect.bottom());

	handlePos[TopLeft] = QRectF(rect.topLeft(), rect.topLeft() + QPointF(
			this->fBoxSize, this->fBoxSize));
	handlePos[TopRight] = QRectF(rect.topRight() + QPointF(-this->fBoxSize, 0),
			rect.topRight() + QPointF(0, this->fBoxSize));
	handlePos[BottomLeft] = QRectF(rect.bottomLeft() + QPointF(0,
			-this->fBoxSize), rect.bottomLeft() + QPointF(this->fBoxSize, 0));
	handlePos[BottomRight] = QRectF(rect.bottomRight() + QPointF(
			-this->fBoxSize, -this->fBoxSize), rect.bottomRight());
	handlePos[CenterLeft] = QRectF(
			centerLeft + QPointF(0, -this->fBoxSize / 2), centerLeft + QPointF(
					this->fBoxSize, this->fBoxSize / 2));
	handlePos[CenterRight] = QRectF(centerRight + QPointF(-this->fBoxSize,
			-this->fBoxSize / 2), centerRight + QPointF(0, this->fBoxSize / 2));
	handlePos[CenterTop] = QRectF(centerTop + QPointF(-this->fBoxSize / 2, 0),
			centerTop + QPointF(this->fBoxSize / 2, this->fBoxSize));
	handlePos[CenterBottom] = QRectF(centerBottom + QPointF(
			-this->fBoxSize / 2, -this->fBoxSize), centerBottom + QPointF(
			this->fBoxSize / 2, 0));
}

void BasicItem::setAdditionalHandles(const bool additionalHandles) {
	if (this->fAdditionalHandles != additionalHandles) {
		this->fAdditionalHandles = additionalHandles;
		this->update();
	}
}

bool BasicItem::additionalHandles() const {
	return fAdditionalHandles;
}

void BasicItem::setSizingSteps(const int sizingSteps) {
	if (this->fSizingSteps != sizingSteps) {
		this->fSizingSteps = sizingSteps;
		this->update();
	}
}

int BasicItem::sizingSteps() const {
	return fSizingSteps;
}

void BasicItem::setBoxSize(const int boxSize) {
	if (this->fBoxSize != boxSize) {
		this->fBoxSize = boxSize;
		this->update();
	}
}

int BasicItem::boxSize() const {
	return fBoxSize;
}

}
