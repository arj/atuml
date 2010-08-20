/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlclassdiagram.h
 *
 *  Created on: 20.08.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLCLASSDIAGRAM_H_
#define _TESTUMLCLASSDIAGRAM_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlClassDiagram: public QObject {
	Q_OBJECT

private slots:

	/**
	 * Testing constructor.
	 * A non-empty name must be given.
	 */
	void constructor();

	/**
	 * Testing (inherited) title property.
	 * Empty property is not allowed.
	 */
	void title();

	/**
	 * Testing classes.
	 */
	void classes();
};

#endif /* _TESTUMLCLASSDIAGRAM_H_ */
