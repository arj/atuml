/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * tests.cpp
 *
 *  Created on: 23.07.2010
 *      Author: Robert Jakob
 */

#include <QTest>
#include <QString>
#include "uml/testumlattribute.h"
#include "uml/testumlmultiplicity.h"
#include "uml/testumlvisibility.h"
#include "uml/testumlparameter.h"
#include "uml/testumlclass.h"

// global arguments because QTest needs them for parameter parsing.
int gargc;
char **gargv;

/**
 * Runs a simple test with the application arguments.
 */
void runTest(QObject *classToTest) {
	int returnValue = QTest::qExec(classToTest,gargc,gargv);

	// If test was not successfull, quit application.
	if (returnValue != 0) {
		exit(-1);
	}
}

/**
 * Runs all tests for classes in the uml namespace.
 */
void umlTests() {
	TestUmlAttribute testumlattribute;
	runTest(&testumlattribute);

	TestUmlMultiplicity testumlmultiplicity;
	runTest(&testumlmultiplicity);

	TestUmlVisibility testumlvisibility;
	runTest(&testumlvisibility);

	TestUmlParameter testumlparameter;
	runTest(&testumlparameter);

	TestUmlClass testumlclass;
	runTest(&testumlclass);
}

int main(int argc, char *argv[]) {

	gargc = argc;
	gargv = argv;

	umlTests();

	return 0;
}
