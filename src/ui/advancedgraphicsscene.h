/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * advancedgraphicsscene.h
 *
 *  Created on: 22.08.2010
 *      Author: Robert Jakob
 */

#ifndef _ADVANCEDGRAPHICSSCENE_H_
#define _ADVANCEDGRAPHICSSCENE_H_

#include <QGraphicsScene>
#include <QPainter>
#include <QRectF>

class AdvancedGraphicsScene : public QGraphicsScene {
public:
	AdvancedGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject * parent = 0);
	virtual ~AdvancedGraphicsScene();

protected:
	virtual void drawBackground(QPainter* painter, const QRectF& rect);
};

#endif /* _ADVANCEDGRAPHICSSCENE_H_ */
