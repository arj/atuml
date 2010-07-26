/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlparameter.cpp
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#include "testumlparameter.h"
#include "../src/uml/parameter.h"
#include "../src/uml/exceptions.h"

using namespace uml;

void TestUmlParameter::constructor() {
	Parameter p("name", "type");
	QCOMPARE(p.name(), QString("name"));
	QCOMPARE(p.type(), QString("type"));

	try {
		Parameter p1("", "type");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		Parameter p1("name", "");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		Parameter p1(QString(), "type");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		Parameter p1("name", QString());
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlParameter::name() {
	Parameter p("name", "type");
	p.setName("myName");
	QCOMPARE(p.name(), QString("myName"));

	try {
		p.setName("");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		p.setName(QString());
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlParameter::type() {
	Parameter p("name", "type");
	p.setType("myType");
	QCOMPARE(p.type(), QString("myType"));

	try {
		p.setType("");
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		p.setType(QString());
		QFAIL("Exception should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlParameter::multiplicity() {
	Parameter p("name", "type");
	QCOMPARE(p.multiplicity(), Multiplicity());

	p.setMultiplicity(Multiplicity(1, 2));
	QCOMPARE(p.multiplicity(), Multiplicity(1,2));
}

void TestUmlParameter::defaultValue() {
	Parameter p("name", "type");
	// Default defaultValue is empty.
	QVERIFY(p.defaultValue().isNull());

	p.setDefaultValue(QVariant(QDate(2010, 07, 25)));
	QCOMPARE(p.defaultValue().toDate(), QDate(2010,07,25));

	p.setDefaultValue(QVariant());
	QVERIFY(p.defaultValue().isNull());
}

void TestUmlParameter::properties() {
	Parameter p("name", "type");
	// List must be empty at the beginning.
	QCOMPARE(p.properties().count(), 0);

	p.addProperty("Testproperty");
	QCOMPARE(p.properties().count(), 1);
	QCOMPARE(p.properties().at(0), QString("Testproperty"));

	// Adding the same again should not change the list at all.
	p.addProperty("Testproperty");
	QCOMPARE(p.properties().count(), 1);
	QCOMPARE(p.properties().at(0), QString("Testproperty"));

	// Removing a not-existing property should not change the list at all.
	p.removeProperty("NonExistantProperty");
	QCOMPARE(p.properties().count(), 1);
	QCOMPARE(p.properties().at(0), QString("Testproperty"));

	// Removing an item.
	p.removeProperty("Testproperty");
	QCOMPARE(p.properties().count(), 0);
}
