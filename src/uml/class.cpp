#include "class.h"
#include "../exceptions.h"

#include <QApplication>

namespace atuml {

namespace uml {

struct Class::Pimpl {

    Pimpl() : abstract(false), active(false) {}

    /**
     * The name of the class.
     */
    QString name;

    /**
     * The abstractness property of the class.
     */
    bool abstract;

    /**
     * The activity property of the class.
     */
    bool active;

    /**
     * The list of attributes for the class.
     */
    QList<Attribute> attributes;

    /**
     * The list of methods for the class.
     */
    QList<Method> methods;
};

Class::Class(const QString name) : impl_(std::make_shared<Pimpl>()) {
	setName(name);
}

void Class::addMethod(Method method) {
    if (!impl_->methods.contains(method)) {
        impl_->methods.append(method);
	}
}

void Class::addAttribute(Attribute attribute) {
    if (!impl_->attributes.contains(attribute)) {
        impl_->attributes.append(attribute);
	}
}

void Class::removeMethod(Method method) {
    impl_->methods.removeOne(method);
}

void Class::removeAttribute(Attribute attribute) {
    impl_->attributes.removeOne(attribute);
}

const QList<Method> Class::methods() const {
    return impl_->methods;
}

const QList<Attribute> Class::attributes() const {
    return impl_->attributes;
}

void Class::setName(const QString name) {
	if (name.isEmpty()) {
		throw atuml::InvalidParameterException(qApp->translate("Exception",
				"Class does not allow an empty name."));
	}

    impl_->name = name;
}

void Class::setAbstract(bool value) {
    impl_->abstract = value;
}

void Class::setActive(bool value) {
    impl_->active = value;
}

bool Class::abstract() const {
    return impl_->abstract;
}

QString Class::name() const {
    return impl_->name;
}

bool Class::active() const {
    return impl_->active;
}

}

}
