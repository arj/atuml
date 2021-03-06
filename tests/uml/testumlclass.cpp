/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlclass.cpp
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#include "testumlclass.h"
#include "../src/uml/class.h"
#include "../src/uml/attribute.h"
#include "../src/exceptions.h"

using namespace atuml;
using namespace atuml::uml;

void TestUmlClass::constructor() {
	Class c("TestClass");
	QCOMPARE(c.name(), QString("TestClass"));

	try {
		Class c1("");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}

void TestUmlClass::name() {
	Class c("TestClass");
	c.setName("MyTest");
	QCOMPARE(c.name(), QString("MyTest"));

	try {
		c.setName("");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}

void TestUmlClass::abstract() {
	Class c("TestClass");
	QCOMPARE(c.abstract(), false);

	c.setAbstract(true);
	QCOMPARE(c.abstract(), true);
}

void TestUmlClass::active() {
	Class c("TestClass");
	QCOMPARE(c.active(), false);

	c.setActive(true);
	QCOMPARE(c.active(), true);
}

void TestUmlClass::methods() {
	Class c("TestClass");
	QCOMPARE(c.methods().count(), 0);

    // Adding a new method
	c.addMethod(Method("Test"));
	QCOMPARE(c.methods().count(), 1);
	QCOMPARE(c.methods().at(0).name(), QString("Test"));

	// Adding the same again should not change anything
	c.addMethod(Method("Test"));
	QCOMPARE(c.methods().count(), 1);
	QCOMPARE(c.methods().at(0).name(), QString("Test"));

	// Removing a not-existing
	c.removeMethod(Method("Test123"));
	QCOMPARE(c.methods().count(), 1);
	QCOMPARE(c.methods().at(0).name(), QString("Test"));

	// Removing an existing
	c.removeMethod(Method("Test"));
	QCOMPARE(c.methods().count(), 0);
}

void TestUmlClass::attributes() {
    Class c("TestClass");
	QCOMPARE(c.attributes().count(), 0);

    // Adding a new attribute
	c.addAttribute(Attribute("Test"));

	QCOMPARE(c.attributes().at(0).name(), QString("Test"));

	// Adding the same again should not change anything
	c.addAttribute(Attribute("Test"));
	QCOMPARE(c.attributes().count(), 1);
	QCOMPARE(c.attributes().at(0).name(), QString("Test"));

	// Removing a not-existing
	c.removeAttribute(Attribute("Test123"));
	QCOMPARE(c.attributes().count(), 1);
	QCOMPARE(c.attributes().at(0).name(), QString("Test"));

	// Removing an existing
	c.removeAttribute(Attribute("Test"));
	QCOMPARE(c.attributes().count(), 0);
}
