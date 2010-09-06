/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * connectableitem.cpp
 *
 *  Created on: 26.08.2010
 *      Author: Robert Jakob
 */

#include "connectableitem.h"
#include "exceptions.h"
#include <QApplication>

namespace atuml {

ConnectableItem::ConnectableItem() : QGraphicsItem() {
    
}

void ConnectableItem::addConnection(Connection connection) {
    if (fConnections.contains(connection)) {
        throw new DoubleEntryException(qApp->translate("Exception",
                "Class does not allow an empty name."));
    }

    fConnections.append(connection);
}

void ConnectableItem::removeConnection(Connection connection) {
    fConnections.removeAll(connection);
}

void ConnectableItem::ItemChange(GraphicsItemChange change, const QVariant& value) {
    if (change == QGraphicsItem::ItemPositionChange) {
        trackConnections();
    }

    if (change == QGraphicsItem::ItemPositionHasChanged) {
        trackConnections();
    }

    QGraphicsItem::itemChange(change, value);
}

void ConnectableItem::trackConnections() {
    Connection c;
    foreach (c, fConnections) {
        c.trackNodes();
    } 
}

}
