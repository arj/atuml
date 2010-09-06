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
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include "class.h"
#include "../connectableitem.h"

namespace uml {

namespace ui {

class ClassGraphicsItem: public uml::Class, public atuml::ConnectableItem {
public:
	ClassGraphicsItem(const QString name, QGraphicsItem* parent = 0);
	virtual ~ClassGraphicsItem();

	virtual QRectF boundingRect() const;

	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget*);

	virtual QPainterPath shape() const;

protected:
	virtual QVariant itemChange(GraphicsItemChange change, const QVariant& value);

private:
	QRectF myRect;

};

}

}

#endif /* _CLASSGRAPHICSITEM_H_ */
