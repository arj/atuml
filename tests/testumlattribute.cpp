/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlattribute.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include <QtTest/QtTest>
#include <QString>
#include "../src/uml/attribute.h"

class TestUmlAttribute : public QObject {
	Q_OBJECT

private slots:
	void constructor();
	void name();
};

void TestUmlAttribute::constructor() {
	Attribute attrib("test");
	QCOMPARE(attrib.name(),QString("test"));
}

void TestUmlAttribute::name() {
	Attribute attrib("");
	attrib.setName("test");
	QCOMPARE(attrib.name(),QString("test"));
}

QTEST_MAIN(TestUmlAttribute)
#include "testumlattribute.moc"
