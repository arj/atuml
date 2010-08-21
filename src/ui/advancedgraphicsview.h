/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * advancedgraphicsview.h
 *
 *  Created on: 20.08.2010
 *      Author: Robert Jakob
 */

#ifndef _ADVANCEDGRAPHICSVIEW_H_
#define _ADVANCEDGRAPHICSVIEW_H_

#include <QGraphicsView>
#include <QWheelEvent>

class AdvancedGraphicsView : public QGraphicsView {
public:

	/**
	 * Standard constructor which creates an advanced QGrahpicsView.
	 *
	 * @param parent The parent of the AdvancedGraphicsView.
	 */
	AdvancedGraphicsView(QWidget* parent = 0);

	/**
	 * Sets zoom factor to 1 (=100%).
	 */
	void zoom100();

	/**
	 * Sets the new zoom value for the view.
	 *
	 * @param zoom The new zoom value.
	 */
	void setZoom(qreal zoom);

	/**
	 * Sets zoom values in percentage.
	 *
	 * @param value The new zoom factor.
	 */
	void setZoomPercentage(unsigned int value);

	/**
	 * Getter for the current zoom value.
	 *
	 * @return Returns the current zoom value.
	 */
	qreal zoom() const;

protected:

	/**
	 * Updates the view matrix according to the values of zoom.
	 */
	void updateMatrix();

	/**
	 * This method is called when a mouse wheel event occurs
	 * with AdvancedGraphicsWindow having the focus.
	 *
	 * @param event The event with all its data.
	 */
	virtual void wheelEvent(QWheelEvent* event);

private:

	/**
	 * The zoomfactor used to display the scene.
	 */
	qreal zoomFactor;
};

#endif /* _ADVANCEDGRAPHICSVIEW_H_ */
