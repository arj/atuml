/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * visibility.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

#include <QString>
#include <QApplication>
#include "exceptions.h"

namespace uml {

/**
 * Abstract class representing the Visibility type.
 */
class Visibility {
public:
	/**
	 * Give a string representation of the visibility class.
	 */
	virtual QString string() = 0;
};

/**
 * Represents a public visibility.
 */
class Public : public Visibility {
public:
	virtual QString string() { return "+"; }
};

/**
 * Represents a public visibility.
 */
class Protected : public Visibility {
public:
	virtual QString string()  { return "#"; }
};

/**
 * Represents a private visibility.
 */
class Private : public Visibility {
public:
	virtual QString string()  { return "-"; }
};

/**
 * Represents a package visibility.
 */
class Package : public Visibility {
public:
	virtual QString string()  { return "~"; }
};

/**
 * Factory class for the creation of a new visibility using the
 * UML defined abbreviations.
 * - "+" means public
 * - "#" means protected
 * - "-" means private
 * - "~" means package
 * according to UML.
 * When an incorrect parameter is given, a InvalidParameterException
 * is thrown.
 */
class VisibilityFactory {
public:

	/**
	 * Creates a new Visibility class according to the parameter.
	 * If invalid code is given, a InvalidParameterException is thrown.
	 */
	static Visibility* createVisibility(const QString code) {
		if (code == "+") {
			return new Public();
		} else if (code == "#") {
			return new Protected();
		} else if (code == "-") {
			return new Private();
		} else if (code == "~") {
			return new Package();
		}

		QString msg = QString("Unknown parameter for visibility construction \"%1\"").arg(code);
		throw InvalidParameterException(qApp->translate("Exception", qPrintable(msg)));
	}
};

}

#endif /* _VISIBILITY_H_ */
