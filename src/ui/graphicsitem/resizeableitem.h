/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * resizeableitem.h
 *
 *  Created on: 06.09.2010
 *      Author: Robert Jakob
 */

#ifndef _RESIZEABLEITEM_H_
#define _RESIZEABLEITEM_H_

#include <QString>
#include <QGraphicsItem>
#include <QBrush>
#include "connectableitem.h"

namespace atuml {

/**
 * Different states a resizeable item can take.
 */
enum ResizeableItemState {
	STATE_NOTHING, /**< Normal state, no resize operation is currently happening. */
	STATE_RESIZE
/**< Currently a resize operation is handled. */
};

/**
 * Base class for a resizable item.
 */
class ResizeableItem: public ConnectableItem {
public:

	/**
	 * Constructor which create a new ResizeableItem.
	 */
	ResizeableItem(bool additionalHandles = true, int sizingSteps = 1,
			int boxsize = 8, QGraphicsItem* parent = 0);

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
	// def updateHandles(self, rect):

	// def paint(self, painter, option, widget = None):

	// def mousePressEvent(self, event)

	// def mouseMoveEvent(self, event)

	// def mouseReleaseEvent(self, event):

private:
	// Internal variables

	/**
	 * Internal variable for the current state of the resizable item.
	 */
	ResizeableItemState currentState;

	/**
	 * Internal variable corresponding to the handle selected during a
	 * resize event.
	 * @todo Give internal numbering of the handles, e.g. via enum?
	 */
	int activeHandle;

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
};

}

#endif /* _RESIZEABLEITEM_H_ */
