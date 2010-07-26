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
#include <QApplication>
#include "exceptions.h"

namespace uml {

Attribute::Attribute(const QString name) {

	if (name.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Attribute does not allow an empty name."));
	}

	fName = name;
	fVisibility = new Public();
}

Attribute::~Attribute() {
	delete fVisibility;
}

void Attribute::setVisibility(Visibility* visibility) {
	if (visibility == 0) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Parameter is null."));
	}

	// Destroy last value
	delete fVisibility;
	fVisibility = visibility;
}

void Attribute::setName(const QString name) {
	if (name.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Attribute does not allow an empty name."));
	}

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

void Attribute::addProperty(const QString property) {
	if (property.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Attribute does not allow an empty property name to be added."));
	}

	if (!fProperties.contains(property)) {
		fProperties.append(property);
	}
}

void Attribute::removeProperty(const QString property) {
	fProperties.removeAll(property);
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

const QStringList Attribute::properties() const {
	return fProperties;
}

}
