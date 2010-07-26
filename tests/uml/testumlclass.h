/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlclass.h
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLCLASS_H_
#define _TESTUMLCLASS_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlClass: public QObject {
	Q_OBJECT

private slots:

	/**
	 * Testing constructor.
	 * A non-empty name must be given.
	 */
	void constructor();

	/**
	 * Testing name property.
	 * Empty property is not allowed.
	 */
	void name();

	/**
	 * Testing abstract property.
	 */
	void abstract();

	/**
	 * Testing active property.
	 */
	void active();

	/**
	 * Testing methods.
	 */
	void methods();

	/**
	 * Testing attributes.
	 */
	void attributes();
};

#endif /* _TESTUMLCLASS_H_ */
