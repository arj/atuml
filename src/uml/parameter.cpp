/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * parameter.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "parameter.h"
#include "exceptions.h"

namespace uml {

Parameter::Parameter(const QString name, const QString type) {

	setName(name);
	setType(type);

	fDirection = in;
}

void Parameter::setDirection(Direction direction) {
	fDirection = direction;
}

void Parameter::setName(const QString name) {
	if (name.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty name."));
	}
	fName = name;
}

void Parameter::setType(const QString type) {
	if (type.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty type."));
	}

	fType = type;
}

void Parameter::setMultiplicity(const Multiplicity multiplicity) {
	fMultiplicity = multiplicity;
}

void Parameter::setDefaultValue(const QVariant defaultValue) {
	fDefaultValue = defaultValue;
}

void Parameter::addProperty(const QString property) {
	if (property.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty property name to be added."));
	}

	if (!fProperties.contains(property)) {
		fProperties.append(property);
	}
}

void Parameter::removeProperty(const QString property) {
	fProperties.removeAll(property);
}

Parameter::Direction Parameter::direction() const {
	return fDirection;
}

QString Parameter::name() const {
	return fName;
}

QString Parameter::type() const {
	return fType;
}

Multiplicity Parameter::multiplicity() const {
	return fMultiplicity;
}

QVariant Parameter::defaultValue() const {
	return fDefaultValue;
}

const QStringList Parameter::properties() const {
	return fProperties;
}

}
