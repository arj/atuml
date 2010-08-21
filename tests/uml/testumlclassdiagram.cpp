/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlclassdiagram.cpp
 *
 *  Created on: 20.08.2010
 *      Author: Robert Jakob
 */

#include "testumlclassdiagram.h"
#include "../src/uml/classdiagram.h"
#include "../src/uml/class.h"

using namespace uml;

void TestUmlClassDiagram::constructor() {
    ClassDiagram cd("Test");
    QCOMPARE(cd.title(), QString("Test")); 
}

void TestUmlClassDiagram::title() {
    ClassDiagram cd("Empty");
    cd.setTitle("Test");
    QCOMPARE(cd.title(), QString("Test"));
}

void TestUmlClassDiagram::classes() {
    ClassDiagram cd("Empty");
    QCOMPARE(cd.classes().count(), 0);

    Class c1("MyClass1");

    // Adding a new class
    cd.addClass(&c1);
    QCOMPARE(cd.classes().count(), 1);
    QCOMPARE(cd.classes().at(0)->name(), QString("MyClass1"));

    // Adding the same again is ok.
    cd.addClass(&c1);
    QCOMPARE(cd.classes().count(), 2);
    QCOMPARE(cd.classes().at(0)->name(), QString("MyClass1"));
    QCOMPARE(cd.classes().at(1)->name(), QString("MyClass1"));
}
