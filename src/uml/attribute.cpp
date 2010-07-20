/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * attribute.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "attribute.h"

Attribute::Attribute(const QString name) :
	fName(name) {

	fVisibility = new Public();
}

Attribute::~Attribute() {
	delete fVisibility;
}

void Attribute::setVisibility(Visibility* visibility) {
	fVisibility = visibility;
}

void Attribute::setName(const QString name) {
	fName = name;
}

void Attribute::setType(const QString type) {
	fType = type;
}

void Attribute::setMultiplicity(const Multiplicity multiplicity) {
	fMultiplicity = multiplicity;
}

void Attribute::setDefaultValue(const QVariant defaultValue) {
	fDefaultValue = defaultValue;
}

Visibility* Attribute::visibility() const {
	return fVisibility;
}

QString Attribute::name() const {
	return fName;
}

QString Attribute::type() const {
	return fType;
}

Multiplicity Attribute::multiplicity() const {
	return fMultiplicity;
}

QVariant Attribute::defaultValue() const {
	return fDefaultValue;
}
