/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlattribute.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "testumlattribute.h"
#include "../src/uml/attribute.h"
#include "../src/exceptions.h"

using namespace uml;
using namespace atuml;

void TestUmlAttribute::constructor() {
	Attribute attrib("test");
	QCOMPARE(attrib.name(),QString("test"));

	try {
		Attribute attrib2("");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		Attribute attrib2(QString());
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlAttribute::name() {
	Attribute attrib("Empty");
	attrib.setName("test");
	QCOMPARE(attrib.name(),QString("test"));

	try {
		attrib.setName(QString());
		QFAIL("Setting of an empty name should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		attrib.setName("");
		QFAIL("Setting of an empty name should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlAttribute::type() {
	Attribute attrib("Empty");

	// after initialization it should be empty.
	QCOMPARE(attrib.type(),QString());

	attrib.setType("test");
	QCOMPARE(attrib.type(),QString("test"));
}

void TestUmlAttribute::multiplicity() {
	Attribute attrib("Empty");
	Multiplicity m(0, 42);
	attrib.setMultiplicity(m);
	QCOMPARE(attrib.multiplicity(),Multiplicity(0,42));
}

void TestUmlAttribute::visibility() {
	Attribute attrib("Empty");
	// default visibility has to be public
	QVERIFY(dynamic_cast<const Public*>(attrib.visibility()));

	attrib.setVisibility(new Protected());
	QVERIFY(dynamic_cast<const Protected*>(attrib.visibility()));

	try {
		attrib.setVisibility(0);
		QFAIL("Should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}

void TestUmlAttribute::defaultValue() {
	Attribute attrib("Empty");
	// Default defaultValue is empty.
	QVERIFY(attrib.defaultValue().isNull());

	attrib.setDefaultValue(QVariant(QDate(2010, 07, 25)));
	QCOMPARE(attrib.defaultValue().toDate(), QDate(2010,07,25));

	attrib.setDefaultValue(QVariant());
	QVERIFY(attrib.defaultValue().isNull());
}

void TestUmlAttribute::properties() {
	Attribute attrib("Empty");
	// List must be empty at the beginning.
	QCOMPARE(attrib.properties().count(), 0);

	attrib.addProperty("Testproperty");
	QCOMPARE(attrib.properties().count(), 1);
	QCOMPARE(attrib.properties().at(0), QString("Testproperty"));

	// Adding the same again should not change the list at all.
	attrib.addProperty("Testproperty");
	QCOMPARE(attrib.properties().count(), 1);
	QCOMPARE(attrib.properties().at(0), QString("Testproperty"));

	// Removing a not-existing property should not change the list at all.
	attrib.removeProperty("NonExistantProperty");
	QCOMPARE(attrib.properties().count(), 1);
	QCOMPARE(attrib.properties().at(0), QString("Testproperty"));

	// Removing an item.
	attrib.removeProperty("Testproperty");
	QCOMPARE(attrib.properties().count(), 0);

	// Adding an empty item
	try {
		attrib.addProperty("");
		QFAIL("Should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}
