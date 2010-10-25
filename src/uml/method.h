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

namespace atuml {

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
	 * Copy constructor.
	 * Copies all the private referenced elements.
	 */
	Method(const Method& copy);

	/**
	 * Destructor which removes created class instances.
	 */
	virtual ~Method();

	/**
	 * Comparison of Method objects is done by comparing
	 * their name. This should be sufficient (inside classes!)
	 *
	 * @param other The method which is compared to the current.
	 * @return Returns true of the names are equal.
	 */
	bool operator==(const Method &other) const;

	/**
	 * Sets a new name for the method.
	 * Must not be empty. If the given name is empty, a
	 * InvalidParameterException is thrown.
	 *
	 * @param name The new name.
	 */
	void setName(const QString name);

	/**
	 * Sets a new visibility for the method.
	 *
	 * @param visibility The new visibility.
	 */
	void setVisibility(const Visibility* visibility);

	/**
	 * Adds a new parameter to the method.
	 * If a parameter with the same name already exists a
	 * DoubleEntryException is thrown.
	 *
	 * @param parameter The parameter to add.
	 */
	void addParameter(const Parameter parameter);

	/**
	 * Removes a parameter if from the method.
	 * If the parameter does not exist, nothing happens.
	 *
	 * @param parameter The parameter to remove.
	 */
	void removeParameter(const Parameter parameter);

	/**
	 * Sets a return type for the method.
	 *
	 * @param returnType The new return type.
	 */
	void setReturnType(const QString returnType);

	/**
	 * Adds a new property.
	 * If a property with the same name already exists nothing happens.
	 *
	 * @param property The new property.
	 */
	void addProperty(const QString property);

	/**
	 * Removes a property.
	 * If the property does not exist, nothing happens.
	 *
	 * @param property The property to remove.
	 */
	void removeProperty(const QString property);

	/**
	 * Getter for the method name.
	 * As a copy of fName is implicitly created there
	 * is no const qualifier.
	 *
	 * @return Returns the name of the method.
	 */
	QString name() const;

	/**
	 * Getter for the visibility.
	 * Note that the pointer remains valid only as long as the
	 * visibility is not modified.
	 *
	 * @return Returns a const visibility.
	 */
	const Visibility* visibility() const;

	/**
	 * Getter for the parameters.
	 *
	 * @return Returns a const list of parameters.
	 */
	const QList<Parameter> parameter() const;

	/**
	 * Getter for return type.
	 * As a copy of fReturnType is implicitly created there
	 * is no const qualifier.
	 *
	 * @return Returns the return type.
	 */
	QString returnType() const;

	/**
	 * Getter for the properties.
	 *
	 * @return Returns a non-modifiable list properties.
	 */
	const QStringList properties() const;

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

}

#endif /* _METHOD_H_ */
