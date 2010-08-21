#include "class.h"
#include "exceptions.h"

namespace uml {

Class::Class(const QString name) : fAbstract(false), fActive(false) {
	setName(name);
}

Class::~Class() {
	qDebug() << "~Class";
}

void Class::addMethod(Method method) {
	if (!fMethods.contains(method)) {
		fMethods.append(method);
	}
}

void Class::addAttribute(Attribute attribute) {
	if (!fAttributes.contains(attribute)) {
		fAttributes.append(attribute);
	}
}

void Class::removeMethod(Method method) {
	fMethods.removeOne(method);
}

void Class::removeAttribute(Attribute attribute) {
	fAttributes.removeOne(attribute);
}

const QList<Method> Class::methods() const {
	return fMethods;
}

const QList<Attribute> Class::attributes() const {
	return fAttributes;
}

void Class::setName(const QString name) {
	if (name.isEmpty()) {
		throw InvalidParameterException(qApp->translate("Exception",
				"Class does not allow an empty name."));
	}

	fName = name;
}

void Class::setAbstract(bool value) {
	fAbstract = value;
}

void Class::setActive(bool value) {
	fActive = value;
}

bool Class::abstract() const {
	return fAbstract;
}

QString Class::name() const {
	return fName;
}

bool Class::active() const {
	return fActive;
}

}
