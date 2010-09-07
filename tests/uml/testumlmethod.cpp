/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlattribute.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "testumlmethod.h"
#include "../src/uml/attribute.h"
#include "../src/uml/method.h"
#include "../src/exceptions.h"

using namespace atuml;
using namespace atuml::uml;

void TestUmlMethod::constructor() {
	Method method("test");
	QCOMPARE(method.name(),QString("test"));

	try {
		Method method2("");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		Method method2(QString());
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlMethod::name() {
	Method method("Empty");
	method.setName("test");
	QCOMPARE(method.name(),QString("test"));

	try {
		method.setName(QString());
		QFAIL("Setting of an empty name should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine
	}

	try {
		method.setName("");
		QFAIL("Setting of an empty name should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlMethod::returnType() {
	Method method("Empty");

	// after initialization it should be non empty.
	QCOMPARE(method.returnType(),QString());

	method.setReturnType("test");
	QCOMPARE(method.returnType(),QString("test"));
}

void TestUmlMethod::visibility() {
	Method method("Empty");
	// default visibility has to be public
	QVERIFY(dynamic_cast<const Public*>(method.visibility()));

	method.setVisibility(new Protected());
	QVERIFY(dynamic_cast<const Protected*>(method.visibility()));

	try {
		method.setVisibility(0);
		QFAIL("Should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}

void TestUmlMethod::parameters() {
	Method method("Empty");
	// List must be empty at the beginning.
	QCOMPARE(method.parameter().count(), 0);

	method.addParameter(Parameter("MyParameter","MyType"));
	QCOMPARE(method.parameter().count(), 1);
	QCOMPARE(method.parameter().at(0), Parameter("MyParameter","MyType"));

	// Adding the same again should throw an exception.
	try {
		method.addParameter(Parameter("MyParameter","MyType"));
		QFAIL("Should have thrown an exception!");
	} catch (DoubleEntryException) {
		// Everything is fine.
	}

	// Removing a not-existing property should not change the list at all.
	method.removeParameter(Parameter("MyParameter2","MyType"));
	QCOMPARE(method.parameter().count(), 1);
	QCOMPARE(method.parameter().at(0), Parameter("MyParameter","MyType"));

	// Removing an item.
	method.removeParameter(Parameter("MyParameter","MyType"));
	QCOMPARE(method.parameter().count(), 0);
}

void TestUmlMethod::properties() {
	Method method("Empty");
	// List must be empty at the beginning.
	QCOMPARE(method.properties().count(), 0);

	method.addProperty("Testproperty");
	QCOMPARE(method.properties().count(), 1);
	QCOMPARE(method.properties().at(0), QString("Testproperty"));

	// Adding the same again should not change the list at all.
	method.addProperty("Testproperty");
	QCOMPARE(method.properties().count(), 1);
	QCOMPARE(method.properties().at(0), QString("Testproperty"));

	// Removing a not-existing property should not change the list at all.
	method.removeProperty("NonExistantProperty");
	QCOMPARE(method.properties().count(), 1);
	QCOMPARE(method.properties().at(0), QString("Testproperty"));

	// Removing an item.
	method.removeProperty("Testproperty");
	QCOMPARE(method.properties().count(), 0);

	// Adding an empty item
	try {
		method.addProperty("");
		QFAIL("Should have thrown an exception!");
	} catch (InvalidParameterException) {
		// Everything is fine.
	}
}
