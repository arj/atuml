/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlmultiplicity.h
 *
 *  Created on: 23.07.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLMULTIPLICITY_H_
#define _TESTUMLMULTIPLICITY_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlMultiplicity : public QObject {
	Q_OBJECT

private slots:
	void constructor();
	void setter();
	void equal();
	void unequal();
};

#endif /* _TESTUMLMULTIPLICITY_H_ */
