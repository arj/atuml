/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlvisibility.h
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLVISIBILITY_H_
#define _TESTUMLVISIBILITY_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlVisibility: public QObject {
	Q_OBJECT

private slots:
	void constructor();
	void factory();
	void string();
};

#endif /* _TESTUMLVISIBILITY_H_ */
