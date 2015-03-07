/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * method.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "method.h"
#include "../exceptions.h"

namespace atuml {

namespace uml {

Method::Method(const QString name) : fName(name), fVisibility(Visibility::PUBLIC) {

	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Method does not allow an empty name."));
	}
}

Method::~Method() {
}

bool Method::operator==(const Method &other) const {
	return this->fName == other.fName;
}

void Method::setName(const QString name) {
	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Method does not allow an empty name."));
	}

	fName = name;
}

void Method::setVisibility(Visibility visibility) {
    fVisibility = visibility;
}

void Method::addParameter(const Parameter parameter) {
	if (fParameter.contains(parameter)) {
		throw new atuml::DoubleEntryException(qApp->translate("Exception",
				"Parameter already exists."));
	}

	fParameter.append(parameter);
}

void Method::removeParameter(const Parameter parameter) {
	// Their should not be more than one.
	fParameter.removeOne(parameter);
}

void Method::setReturnType(const QString returnType) {
	fReturnType = returnType;
}

void Method::addProperty(const QString property) {
	if (property.isEmpty()) {
			throw atuml::InvalidParameterException(qApp->translate("Exception",
					"Method does not allow an empty property name to be added."));
	}

	fProperties.append(property);
}

void Method::removeProperty(const QString property) {
	// Their should not be more than one.
	fProperties.removeOne(property);
}

Visibility Method::visibility() const {
	return fVisibility;
}

QString Method::returnType() const {
	return fReturnType;
}

const QStringList Method::properties() const {
	return fProperties;
}

QString Method::name() const {
	return fName;
}

const QList<Parameter> Method::parameter() const {
	return fParameter;
}

}

}
