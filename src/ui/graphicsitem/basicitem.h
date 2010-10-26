/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * basicitem.h
 *
 *  Created on: 26.10.2010
 *      Author: Robert Jakob
 */

#ifndef _BASICITEM_H_
#define _BASICITEM_H_

#include <QRectF>
#include <QString>
#include <QGraphicsItem>
#include <QBrush>
#include <QList>
#include "../../exceptions.h"

namespace atuml {

/**
 * Different states a resizeable item can take.
 */
enum ResizingState {
	StateNothing, /**< Normal state, no resize operation is currently happening. */
	StateResize
/**< Currently a resize operation is handled. */
};

class Connection {
public:
	void trackNodes() {
	}

	bool operator==(const Connection&) const {
		return false; // Template only
	}
};

class BasicItem: public QGraphicsRectItem {
public:
	BasicItem(QGraphicsItem* parent = 0);

	virtual ~BasicItem();

	/**
	 * The paint method draws the handles on the item.
	 * The child item must call this function after it has
	 * completed its own paintings.
	 *
	 * @param painter The painter object used for painting
	 * @param option The current state of the graphic item
	 * @param widget The widget that is beiing painted on.
	 */
	virtual void paint(QPainter *painter,
			const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

	/**
	 * Sets the rectangle of the item.
	 *
	 * @param rectangle The new rectangle.
	 */
	virtual void setRect(const QRectF& rectangle);

	/**
	 * Adds a new connection to the item.
	 * If the same connection is added again, a
	 * DoubleEntryException is thrown.
	 *
	 * @param connection The connection to add.
	 */
	void addConnection(Connection connection);

	/**
	 * Removes a connection from the item.
	 * If the connection does not exist, nothing happens.
	 *
	 * @param connection The connection to remove.
	 */
	void removeConnection(Connection connection);

	// **** getter and setter **** //

	/**
	 * Enables or disables the additional handles.
	 * If false, then there are 4 handles, each vertex having on.
	 * If true, the there are 8 handles, each vertex and each edge having one.
	 *
	 * @param additionalHandles The new handle value.
	 */
	void setAdditionalHandles(const bool additionalHandles);

	/**
	 * Getter for the additionalHandles property.
	 *
	 * @return Returns if additional handles are enabled.
	 */
	bool additionalHandles() const;

	void setSizingSteps(const int sizingSteps);
	int sizingSteps() const;

	void setBoxSize(const int boxSize);
	int boxSize() const;

protected:
	/**
	 *  Stores the positions of the handles (according to the item rect)
	 *  into this->handlePos which can easily be used for drawing.
	 */
	void updateHandles(const QRectF& rect);

	/**
	 * ItemChange event which is automatically triggered if the item
	 * is changed somehow.
	 * This maybe position, size and other things.
	 *
	 * @param change The parameter of the item changing.
	 * @param value The new value of the parameter.
	 */
	void ItemChange(GraphicsItemChange change, const QVariant& value);

	/**
	 * Track connections informs all connected connections of position
	 * updates.
	 */
	void trackConnections();

	/**
	 * This method is called when the mouse button is pressed down.
	 * If click is in handle position and left button then
	 * current position and rect are saved and internal state is changed to
	 * resizing.
	 */
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event);

	/**
	 * This method is called after releasing the mouse button.
     * If we were in resizing state, restore state and
     * adjust final rectangle, i.e. topLeft == (0,0)
	 */
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

	// def mousePressEvent(self, event)

	// def mouseMoveEvent(self, event)

	// def mouseReleaseEvent(self, event):

private:
	enum Handle {
		None = -1,
		TopLeft = 0,
		TopRight,
		BottomLeft,
		BottomRight,
		CenterLeft,
		CenterRight,
		CenterTop,
		CenterBottom,
	};

	// Internal variables

	/**
	 * Internal variable for the current state of the resizable item.
	 */
	ResizingState currentState;

	/**
	 * Internal variable corresponding to the handle selected during a
	 * resize event.
	 * @todo Give internal numbering of the handles, e.g. via enum?
	 */
	Handle activeHandle;

	/**
	 * The brush used to paint the handles in normal state.
	 * @deprecated Will be replaced by global properties provider.
	 */
	QBrush handleBrush;

	/**
	 * The brush used to paint the handles in active state.
	 * @deprecated Will be replaced by global properties provider.
	 */
	QBrush handleActiveBrush;

	/**
	 * Field variable for additional handles property.
	 */
	bool fAdditionalHandles;

	/**
	 * Field variable for sizing steps, 1 means continuous resizing is possible.
	 */
	int fSizingSteps;

	/**
	 * The size of the boxes/handles.
	 */
	int fBoxSize;

	/**
	 * An array containing the position rectangles for all 8
	 * handles.
	 */
	QRectF handlePos[8];

	/**
	 * List holding all the connections.
	 */
	QList<Connection> fConnections;

	/**
	 * Holds the point where the mouse button was pressed.
	 */
	QPointF pressEventPosition;
};

}

#endif /* _BASICITEM_H_ */
