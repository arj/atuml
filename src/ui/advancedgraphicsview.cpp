/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * advancedgraphicsview.cpp
 *
 *  Created on: 20.08.2010
 *      Author: Robert Jakob
 */

#include "advancedgraphicsview.h"
#include "../globals.h"
#include <QDebug>
#include <cmath>

// For OpenGL based rendering enable the following line and add opengl
// to QT variable in the project file
// #include <QGLWidget>

AdvancedGraphicsView::AdvancedGraphicsView(QWidget* parent) :
	QGraphicsView(parent) {

	this->setDragMode(QGraphicsView::RubberBandDrag);
	this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	this->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	// For OpenGL based rendering enable the following line:
	// this->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));

	zoomFactor = 1;
}

void AdvancedGraphicsView::updateMatrix() {
	QMatrix matrix(1,0,
			0,1,
			0,0);

	matrix.scale(zoomFactor, zoomFactor);
	this->setMatrix(matrix);
}

void AdvancedGraphicsView::setZoom(qreal zoom) {
	if (fabs(this->zoomFactor - zoom) > atuml::globals::epsilon) {
		this->zoomFactor = zoom;
		updateMatrix();
	}
}

qreal AdvancedGraphicsView::zoom() const {
	return zoomFactor;
}

void AdvancedGraphicsView::wheelEvent(QWheelEvent* event) {
	static qreal normalZoomFactor = 1.2;

	qreal numDegrees = event->delta() / 8.0;
	qreal numSteps = numDegrees / 15.0;

	qreal factor = 1;

	if (event->orientation() == Qt::Vertical) {
		factor = pow(normalZoomFactor, numSteps);
	} else {
		factor = 1.0/pow(normalZoomFactor, numSteps);
	}

	setZoom(zoom() * factor);

	event->accept();
}
