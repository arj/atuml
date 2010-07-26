/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlparameter.h
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLPARAMETER_H_
#define _TESTUMLPARAMETER_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlParameter: public QObject {
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
	 * Testing type property.
	 * Empty property is not allowed.
	 */
	void type();

	/**
	 * Testing multiplicity property.
	 * No restrictions.
	 */
	void multiplicity();

	/**
	 * Testing defaultValue.
	 * Default must be empty.
	 */
	void defaultValue();

	/**
	 * Testing properties.
	 * Adding an empty string must throw an exception.
	 */
	void properties();
};

#endif /* _TESTUMLPARAMETER_H_ */
