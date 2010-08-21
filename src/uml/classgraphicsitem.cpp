/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * classgraphicsitem.cpp
 *
 *  Created on: 21.08.2010
 *      Author: Robert Jakob
 */

#include "classgraphicsitem.h"

namespace uml {

namespace ui {

ClassGraphicsItem::ClassGraphicsItem(const QString name, QGraphicsItem* parent) :
	uml::Class(name), QGraphicsItem(parent) {
}

ClassGraphicsItem::~ClassGraphicsItem() {
}

}

}
