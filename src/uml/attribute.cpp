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
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QDebug>

#include <memory>

#include "visibility.h"
#include "multiplicity.h"
#include "../exceptions.h"

namespace atuml {

namespace uml {

struct Attribute::Pimpl {
    /**
     * Name of the class. Must not be empty!
     */
    QString name;

    /**
     * The visibility of the attribute.
     * As it is a pointer it must be initialized in the constructor(s).
     */
    Visibility visibility;

    /**
     * Type of the attribute. Currently, this is represented as
     * a string, but maybe this should change to a specific C++ class as
     * uml classes can be type of an attribute, too.
     */
    QString type;

    /**
     * The multiplicity of the attribute.
     */
    Multiplicity multiplicity;

    /**
     * The default value of the attribute.
     */
    QVariant defaultValue;

    /**
     * The list of properties of the attribute.
     * The following properties are defined in uml:
     * - ordered The data is returned ordered.
     * - read-only The attribute is read only.
     */
    QStringList properties;
};

Attribute::Attribute(const QString name) : impl_(std::make_shared<Pimpl>()) {

    if (name.isEmpty()) {
        throw atuml::InvalidParameterException(qApp->translate("Exception",
                "Attribute does not allow an empty name."));
    }

    impl_->name = name;
    impl_->visibility = Visibility::PUBLIC;
}

void Attribute::setVisibility(Visibility visibility) {
    impl_->visibility = visibility;
}

void Attribute::setName(const QString name) {
	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Attribute does not allow an empty name."));
	}

    impl_->name = name;
}

void Attribute::setType(const QString type) {
    impl_->type = type;
}

void Attribute::setMultiplicity(const Multiplicity multiplicity) {
    impl_->multiplicity = multiplicity;
}

void Attribute::setDefaultValue(const QVariant defaultValue) {
    impl_->defaultValue = defaultValue;
}

void Attribute::addProperty(const QString property) {
	if (property.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Attribute does not allow an empty property name to be added."));
    }

    if (!impl_->properties.contains(property)) {
        impl_->properties.append(property);
	}
}

bool Attribute::operator==(const Attribute &other) const {
    return this->impl_->name == other.impl_->name;
}

void Attribute::removeProperty(const QString property) {
    impl_->properties.removeAll(property);
}

Visibility Attribute::visibility() const {
    return impl_->visibility;
}

QString Attribute::name() const {
    return impl_->name;
}

QString Attribute::type() const {
    return impl_->type;
}

Multiplicity Attribute::multiplicity() const {
    return impl_->multiplicity;
}

QVariant Attribute::defaultValue() const {
    return impl_->defaultValue;
}

const QStringList Attribute::properties() const {
    return impl_->properties;
}

}

}
