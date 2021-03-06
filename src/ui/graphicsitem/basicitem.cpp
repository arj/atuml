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
#include <QDebug>
#include <QApplication>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

namespace atuml {

BasicItem::BasicItem(QGraphicsItem* parent) :
	QGraphicsRectItem(parent) {
	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

	// TODO Check if this works with version 4.4 or 4.5
#if (QT_VERSION >= QT_VERSION_CHECK(4,6,0))
	setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
#endif

	this->fAdditionalHandles = false;
	this->fSizingSteps = 5;
	this->fBoxSize = 8;

	this->currentState = StateNothing;
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

		int maxHandles = this->fAdditionalHandles ? 8 : 4;

		for (int i = 0; i < maxHandles; i++) {
			painter->drawRect(this->handlePos[i]);
		}

		// if we clicked (and hold) on a handle paint it with handleActiveBrush
		if (this->activeHandle != None) {
			painter->setBrush(this->handleActiveBrush);
			painter->drawRect(this->handlePos[this->activeHandle]);
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

	// Now we calculate all the handle's positions
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

void BasicItem::mousePressEvent(QGraphicsSceneMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		if (this->currentState == StateNothing) {
			this->pressEventPosition = event->scenePos();

			// Now checking if a handle was hit
			for (int i = 0; i < 8; i++) {
				QRectF r = this->mapRectToScene(this->handlePos[i]);
				if (r.contains(this->pressEventPosition)) {
					this->currentState = StateResize;
					this->activeHandle = (Handle) i;
					this->oldRect = this->rect();
					// TODO this->oldPos this->pos();
					this->update();
					break;
				}
			}
		}
	} else {
		// If another button is pressed we cancel everything
		this->currentState = StateNothing;
		this->activeHandle = None;
		// TODO Restore old position and rect!
		this->update();
	}

	QGraphicsRectItem::mousePressEvent(event);
}

void BasicItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
	if (this->currentState == StateResize ){
		QPointF distance = event->scenePos() - this->pressEventPosition;

		QRectF rect = this->rect();

		if (this->activeHandle == 0) {
			rect.setTopLeft(this->oldRect.topLeft() + distance);
		}

		this->setRect(rect);
	} else {
		// This ensures normal movement of the items.
		QGraphicsRectItem::mouseMoveEvent(event);
	}

	/* Original Python prototype code:
	 * if self.__state == SizeableItem.STATE_NOTHING:
            QtGui.QGraphicsRectItem.mouseMoveEvent(self,event)
            return
        elif self.__state == SizeableItem.STATE_RESIZE:

            # calculate the distance with
            distance = event.scenePos() - self.pressPosition

            # Continuous or discrete stepping.
            if self.sizingSteps > 1:
                steps = math.floor(distance.x() / self.sizingSteps)
                distance.setX(steps * self.sizingSteps)
                steps = math.floor(distance.y() / self.sizingSteps)
                distance.setY(steps * self.sizingSteps)

            rect = self.rect()

            # Different resizing operations according to selected handle.
            if self.__activeHandle == 0:
                rect.setTopLeft(self.__oldRect.topLeft() + distance)
            elif self.__activeHandle == 1:
                rect.setTopRight(self.__oldRect.topRight() + distance)
            elif self.__activeHandle == 2:
                rect.setBottomLeft(self.__oldRect.bottomLeft() + distance)
            elif self.__activeHandle == 3:
                rect.setBottomRight(self.__oldRect.bottomRight() + distance)
            elif self.additionalHandles:
                if self.__activeHandle == 4:
                    rect.setLeft(self.__oldRect.left() + distance.x())
                elif self.__activeHandle == 5:
                    rect.setRight(self.__oldRect.right() + distance.x())
                elif self.__activeHandle == 6:
                    rect.setTop(self.__oldRect.top() + distance.y())
                elif self.__activeHandle == 7:
                    rect.setBottom(self.__oldRect.bottom() + distance.y())

            # A minimum size must be preserved
            if rect.width() < self.boxsize * 2:
                rect.setWidth(self.boxsize * 2)

            if rect.height() < self.boxsize * 2:
                rect.setHeight(self.boxsize * 2)

            self.setRect(rect)
        else:
            QtGui.QGraphicsRectItem.mouseMoveEvent(self,event)
	 */
}

void BasicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {

	if (event->button() == Qt::LeftButton) {
		this->currentState = StateNothing;
		this->activeHandle = None;
		this->update();
		QRectF rect = this->rect();

		if (rect.left() != 0 || rect.top() != 0) {
			QPointF distance = rect.topLeft();
			QPointF newPos = this->pos() + distance;
			rect.adjust(-distance.x(),-distance.y(),-distance.x(),-distance.y());
			this->setPos(newPos);
			this->setRect(rect);
		}
	}

	QGraphicsRectItem::mouseReleaseEvent(event);
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
