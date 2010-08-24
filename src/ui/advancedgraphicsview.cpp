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
#include <cmath>
#include <QPoint>
#include <QDebug>

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

	// Mouse move events should occur without any button pressed
	setMouseTracking(true);
}

void AdvancedGraphicsView::updateMatrix() {
	QMatrix matrix(1,0,
			0,1,
			0,0);

	matrix.scale(zoomFactor, zoomFactor);
	this->setMatrix(matrix);
}

void AdvancedGraphicsView::zoom100() {
	setZoom(1);
}

void AdvancedGraphicsView::setZoom(qreal zoom) {
	// Normal float equality comparison
	if (fabs(this->zoomFactor - zoom) > atuml::globals::epsilon) {
		this->zoomFactor = zoom;
		updateMatrix();
	}
}

void AdvancedGraphicsView::setZoomPercentage(unsigned int value) {
	setZoom(value / 100.0);
}

qreal AdvancedGraphicsView::zoom() const {
	return zoomFactor;
}

void AdvancedGraphicsView::wheelEvent(QWheelEvent* event) {
	// As suggested by http://doc.trolltech.com/4.5/qwheelevent.html#delta
	static qreal normalZoomFactor = 1.125;

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

void AdvancedGraphicsView::mouseMoveEvent(QMouseEvent* e) {
	QPoint mousePos = e->pos();
	QPointF scenePos = mapToScene(mousePos);

	emit mousePositionChanged(scenePos);
}
