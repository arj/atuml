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
#include "../exceptions.h"
#include "multiplicity.h"

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QApplication>

namespace atuml {

namespace uml {

struct Parameter::Pimpl {

    Pimpl() : direction_(Direction::IN) {}

    /**
     * The direction of the parameter. Defaults to Direction::IN.
     */
    Direction direction_;

    /**
     * The name of the parameter.
     */
    QString name_;

    /**
     * Type of the parameter. Currently, this is represented as
     * a string, but maybe this should change to a specific C++ class as
     * uml classes can be type of an parameter, too.
     */
    QString type_;

    /**
     * The multiplicity of the parameter.
     */
    Multiplicity multiplicity_;

    /**
     * The default value of the parameter.
     */
    QVariant defaultValue_;

    /**
     * The list of properties for the parameter.
     */
    QStringList properties_;
};

Parameter::Parameter(const QString name, const QString type) : impl_(std::make_shared<Pimpl>()) {
	setName(name);
	setType(type);
}

bool Parameter::operator==(const Parameter &other) const {
    return this->impl_->name_ == other.impl_->name_;
}

void Parameter::setDirection(Direction direction) {
    impl_->direction_ = direction;
}

void Parameter::setName(const QString name) {
	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty name."));
	}
    impl_->name_ = name;
}

void Parameter::setType(const QString type) {
	if (type.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty type."));
	}

    impl_->type_ = type;
}

void Parameter::setMultiplicity(const Multiplicity multiplicity) {
    impl_->multiplicity_ = multiplicity;
}

void Parameter::setDefaultValue(const QVariant defaultValue) {
    impl_->defaultValue_ = defaultValue;
}

void Parameter::addProperty(const QString property) {
    if (property.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Parameter does not allow an empty property name to be added."));
	}

    if (!impl_->properties_.contains(property)) {
        impl_->properties_.append(property);
	}
}

void Parameter::removeProperty(const QString property) {
    impl_->properties_.removeAll(property);
}

Parameter::Direction Parameter::direction() const {
    return impl_->direction_;
}

QString Parameter::name() const {
    return impl_->name_;
}

QString Parameter::type() const {
    return impl_->type_;
}

Multiplicity Parameter::multiplicity() const {
    return impl_->multiplicity_;
}

QVariant Parameter::defaultValue() const {
    return impl_->defaultValue_;
}

const QStringList Parameter::properties() const {
    return impl_->properties_;
}

}

}
