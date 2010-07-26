/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * testumlmultiplicity.cpp
 *
 *  Created on: 23.07.2010
 *      Author: Robert Jakob
 */

#include "testumlmultiplicity.h"
#include "../src/uml/multiplicity.h"
#include "../src/uml/exceptions.h"

using namespace uml;

void TestUmlMultiplicity::constructor() {
	Multiplicity m;
	QCOMPARE(m.minimum(),(quint32)1);
	QCOMPARE(m.maximum(),(quint32)1);

	Multiplicity mm(4, 5);
	QCOMPARE(mm.minimum(),(quint32)4);
	QCOMPARE(mm.maximum(),(quint32)5);

	Multiplicity mmm(0, Multiplicity::Infinity);
	QCOMPARE(mmm.minimum(),(quint32)0);
	QCOMPARE(mmm.maximum(),Multiplicity::Infinity);

	Multiplicity mmmm(0, 0);
	QCOMPARE(mmmm.minimum(),(quint32)0);
	QCOMPARE(mmmm.maximum(),(quint32)0);

	try {
		Multiplicity mmmmmm(12, 5);
		QFAIL("InvalidParameterException should have been thrown.");
	} catch (InvalidParameterException e) {
		// Everything is fine
	}
}

void TestUmlMultiplicity::setter() {
	Multiplicity m;
	m.set(1, 99);
	QCOMPARE(m.minimum(),(quint32)1);
	QCOMPARE(m.maximum(),(quint32)99);

	m.set(Multiplicity::Infinity, Multiplicity::Infinity);
	QCOMPARE(m.minimum(),Multiplicity::Infinity);
	QCOMPARE(m.maximum(),Multiplicity::Infinity);

	try {
		m.set(12, 5);
		QFAIL("InvalidParameterException should have been thrown.");
	} catch (InvalidParameterException e) {
		// Everything is fine
	}
}

void TestUmlMultiplicity::equal() {
	Multiplicity m(1, 1);
	Multiplicity mm(1, 1);
	Multiplicity mMm(1, 2);

	QVERIFY(m == mm);
	QVERIFY(!(m == mMm));
}

void TestUmlMultiplicity::unequal() {
	Multiplicity m(1, 1);
	Multiplicity mm(1, 1);
	Multiplicity mMm(1, 2);

	QVERIFY(m != mMm);
	QVERIFY(!(m != mm));
}
