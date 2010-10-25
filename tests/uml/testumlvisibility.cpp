/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlvisibility.cpp
 *
 *  Created on: 25.07.2010
 *      Author: Robert Jakob
 */

#include "testumlvisibility.h"
#include "../src/uml/visibility.h"
#include "../src/exceptions.h"

using namespace atuml;
using namespace atuml::uml;

void TestUmlVisibility::constructor() {
	// No exception must occur.
	Public();
	Protected();
	Private();
	Package();
}

void TestUmlVisibility::factory() {
	// Now check if the correct classes are created with the factory.
	// A subclass of each class is fine, too thus we can use dynamic_cast
	QVERIFY(dynamic_cast<Public*>(VisibilityFactory::createVisibility("+")));
	QVERIFY(dynamic_cast<Protected*>(VisibilityFactory::createVisibility("#")));
	QVERIFY(dynamic_cast<Private*>(VisibilityFactory::createVisibility("-")));
	QVERIFY(dynamic_cast<Package*>(VisibilityFactory::createVisibility("~")));

	try {
		VisibilityFactory::createVisibility("");
		QFAIL("InvalidParameterException should have been thrown.");
	} catch (InvalidParameterException) {
		// Everything is fine
	}
}

void TestUmlVisibility::string() {
	QCOMPARE(Public().string(), QString("+"));
	QCOMPARE(Protected().string(), QString("#"));
	QCOMPARE(Private().string(), QString("-"));
	QCOMPARE(Package().string(), QString("~"));
}
