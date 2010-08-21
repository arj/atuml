/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlmethod.h
 *
 *  Created on: 21.08.2010
 *      Author: Robert Jakob
 */

#ifndef _TESTUMLMETHOD_H_
#define _TESTUMLMETHOD_H_

#include <QtTest/QtTest>
#include <QObject>

class TestUmlMethod : public QObject {
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
	 * Testing returnType property.
	 */
	void returnType();

	/**
	 * Testing visibility.
	 * Default must be public and
	 * null pointer must throw exception.
	 */
	void visibility();

	/**
	 * Testing parameters.
	 * No double parameters allowed.
	 */
	void parameters();

	/**
	 * Testing properties.
	 * Adding an empty string must throw an exception.
	 */
	void properties();
};

#endif /* _TESTUMLMETHOD_H_ */
