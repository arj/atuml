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

class AdvancedGraphicsView : public QGraphicsView {
public:
	AdvancedGraphicsView(QWidget* parent = 0) : QGraphicsView(parent) {}
};

#endif /* _ADVANCEDGRAPHICSVIEW_H_ */
