/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * classgraphicsitem.h
 *
 *  Created on: 21.08.2010
 *      Author: Robert Jakob
 */

#ifndef _CLASSGRAPHICSITEM_H_
#define _CLASSGRAPHICSITEM_H_

#include <QGraphicsItem>
#include "class.h"

namespace uml {

namespace ui {

class ClassGraphicsItem: public uml::Class, public QGraphicsItem {
public:
	ClassGraphicsItem(const QString name, QGraphicsItem* parent = 0);
	virtual ~ClassGraphicsItem();

	virtual QRectF boundingRect() const {
		return QRectF();
	}

	virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) {
	}
};

}

}

#endif /* _CLASSGRAPHICSITEM_H_ */
