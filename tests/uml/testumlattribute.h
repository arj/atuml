/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlattribute.h
 *
 *  Created on: 23.07.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLATTRIBUTE_H_
#define _TESTUMLATTRIBUTE_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlAttribute : public QObject {
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
	 * There are no restrictions on the type.
	 */
	void type();

	/**
	 * Testing multiplicity property.
	 * No restrictions.
	 */
	void multiplicity();

	/**
	 * Testing visibility.
	 * Default must be public and
	 * null pointer must throw exception.
	 */
	void visibility();

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

#endif /* _TESTUMLATTRIBUTE_H_ */
