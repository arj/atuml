/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * method.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _METHOD_H_
#define _METHOD_H_

#include <QString>
#include <QStringList>
#include <QList>
#include "visibility.h"
#include "parameter.h"

namespace uml {

/**
 * The Method class represents an uml method or operation which is part of a
 * uml class.
 */
class Method {
public:
	/**
	 * Constructor which create a new method with a name.
	 *
	 * @oaram name The name of the method to create-
	 */
	Method(const QString name);

	/**
	 * Comparison of Method objects is done by comparing
	 * their name. This should be sufficient (inside classes!)
	 *
	 * @param other The method which is compared to the current.
	 * @return Returns true of the names are equal.
	 */
	bool operator==(const Method &other) const {
		return this->fName == other.fName;
	}

	/**
	 * Getter for the method name.
	 *
	 * @return Returns the name of the method.
	 */
	QString name() const;

	// TODO Implement missing getters and setters.
private:

	/**
	 * The visibility of the method. Must not be null.
	 */
	Visibility* fVisibility;

	/**
	 * The name of the method. Must not be empty.
	 */
	QString fName;

	/**
	 * The list of parameters.
	 */
	QList<Parameter> fParameter;

	/**
	 * The return type of the method.
	 * Currently, this is represented as
	 * a string, but maybe this should change to a specific C++ class as
	 * uml classes can be type of a method, too.
	 */
	QString fReturnType;

	/**
	 * The properties of a method. The following properties are defined in uml:
	 * - ordered The data is returned ordered.
	 * - redefines <operation> overwrite the operation <operation>
	 * - read-only
	 */
	QStringList fProperties;
};

}

#endif /* _METHOD_H_ */
