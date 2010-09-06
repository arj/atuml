/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * connectableitem.h
 *
 *  Created on: 26.08.2010
 *      Author: Robert Jakob
 */

#ifndef _CONNECTABLEITEM_H_
#define _CONNECTABLEITEM_H_

#include <QString>
#include <QGraphicsItem>

namespace atuml {

class Connection {
public:
    void trackNodes() {}

    bool operator==(const Connection&) const {
        return false; // Template only
	}

};

/**
 * An item which can be connected by a Connection.
 */
class ConnectableItem : public QGraphicsItem {
public:
	/**
	 * Constructor which create a new ConnectableItem.
	 */
    ConnectableItem(QGraphicsItem* parent = 0);

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

protected:
    
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

private:
    QList<Connection> fConnections;
};

}

#endif /* _CONNECTABLEITEM_H_ */
