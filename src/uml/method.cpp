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
#include "parameter.h"
#include "visibility.h"
#include "../exceptions.h"

#include <QString>
#include <QStringList>
#include <QApplication>

namespace atuml {

namespace uml {

struct Method::Pimpl {

    Pimpl(const QString name) : name(name), visibility(Visibility::PUBLIC) {}

    /**
     * The name of the method. Must not be empty.
     */
    QString name;

    /**
     * The visibility of the method. Must not be null.
     */
    Visibility visibility;

    /**
     * The list of parameters.
     */
    QList<Parameter> parameter;

    /**
     * The return type of the method.
     * Currently, this is represented as
     * a string, but maybe this should change to a specific C++ class as
     * uml classes can be type of a method, too.
     */
    QString returnType;

    /**
     * The properties of a method. The following properties are defined in uml:
     * - ordered The data is returned ordered.
     * - redefines <operation> overwrite the operation <operation>
     * - read-only
     */
    QStringList properties;
};

Method::Method(const QString name) : impl_(std::make_shared<Pimpl>(name)) {

	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Method does not allow an empty name."));
	}
}

bool Method::operator==(const Method &other) const {
    return this->impl_->name == other.impl_->name;
}

void Method::setName(const QString name) {
	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Method does not allow an empty name."));
	}

    impl_->name = name;
}

void Method::setVisibility(Visibility visibility) {
    impl_->visibility = visibility;
}

void Method::addParameter(const Parameter parameter) {
    if (impl_->parameter.contains(parameter)) {
		throw new atuml::DoubleEntryException(qApp->translate("Exception",
				"Parameter already exists."));
	}

    impl_->parameter.append(parameter);
}

void Method::removeParameter(const Parameter parameter) {
	// Their should not be more than one.
    impl_->parameter.removeOne(parameter);
}

void Method::setReturnType(const QString returnType) {
    impl_->returnType = returnType;
}

void Method::addProperty(const QString property) {
	if (property.isEmpty()) {
			throw atuml::InvalidParameterException(qApp->translate("Exception",
					"Method does not allow an empty property name to be added."));
	}

    impl_->properties.append(property);
}

void Method::removeProperty(const QString property) {
	// Their should not be more than one.
    impl_->properties.removeOne(property);
}

Visibility Method::visibility() const {
    return impl_->visibility;
}

QString Method::returnType() const {
    return impl_->returnType;
}

const QStringList Method::properties() const {
    return impl_->properties;
}

QString Method::name() const {
    return impl_->name;
}

const QList<Parameter> Method::parameter() const {
    return impl_->parameter;
}

}

}
