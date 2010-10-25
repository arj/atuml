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

namespace atuml {

ResizeableItem::ResizeableItem(bool additionalHandles, int sizingSteps,
		int boxsize, QGraphicsItem* parent) :
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
