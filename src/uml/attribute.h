/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * attribute.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _ATTRIBUTE_H_
#define _ATTRIBUTE_H_

#include <QString>
#include <QStringList>
#include <QVariant>
#include <QDebug>
#include "visibility.h"
#include "multiplicity.h"

namespace uml {

/**
 * This class represents an attribute (property) of a uml class.
 * An attribute is described as follows:
 *   [Visibility] [/] name [: Type] [ multiplicity ] [= defaultValue] [{property*}]
 */
class Attribute {
public:
	/**
	 * Construct a new attribute with the given name.
	 * Throws an InvalidParameterException if name is empty.
	 *
	 * @param name The name of the new attribute
	 *
	 */
	Attribute(const QString name);

	/**
	 * Copy constructor.
	 * Copies all the private referenced elements.
	 */
	Attribute(const Attribute& copy);

	/**
	 * Deconstructor
	 */
	virtual ~Attribute();

	/**
	 * Setter for visibility.
	 * Throws InvalidParameterException if parameter is null.
	 * @param visibility The new visibility to set.
	 */
	void setVisibility(Visibility* visibility);

	/**
	 * Setter for name.
	 * Throws InvalidParameterException if string is empty.
	 */
	void setName(const QString name);

	/**
	 * Setter for type.
	 * An empty value is allowed.
	 */
	void setType(const QString type);

	/**
	 * Setter for multiplicity.
	 */
	void setMultiplicity(const Multiplicity multiplicity);

	/**
	 * Setter for default value.
	 * For setting an empty defaultValue simple call
	 *   setDefaultValue(QVariant);
	 */
	void setDefaultValue(const QVariant defaultValue);

	/**
	 * Adds a new property if it is not set.
	 * Throws an InvalidParameterException if property is empty.
	 */
	void addProperty(const QString property);

	/**
	 * Removes given property if it exists.
	 */
	void removeProperty(const QString property);

	/**
	 * Comparison of Attribute objects is done by comparing
	 * their name. This should be sufficient (inside uml classes!)
	 */
	bool operator==(const Attribute &other) const {
		return this->fName == other.fName;
	}

	/**
	 * Returns the visibility of the attribute.
	 *
	 * @return The visibility.
	 */
	Visibility* visibility() const;

	/**
	 * Returns the name of the attribute.
	 *
	 * @return The name of the attribute.
	 */
	QString name() const;

	/**
	 * Returns the type of the attribute.
	 *
	 * @return The type of the attribute.
	 */
	QString type() const;

	/**
	 * Returns the multiplicity of the attribute.
	 * A multiplicity of (1,6) means that the attribute can
	 * have one to six occurences.
	 *
	 * @return Returns the multiplicity.
	 */
	Multiplicity multiplicity() const;

	/**
	 * Getter for the default value of the attribute.
	 *
	 * @return Returns a QVariant holding the default value.
	 */
	QVariant defaultValue() const;

	/**
	 * Getter for the list of properties.
	 *
	 * @return Returns a non-modifiable list of attribute properties.
	 */
	const QStringList properties() const;

private:
	/**
	 * The visibility of the attribute.
	 * As it is a pointer it must be initialized in the constructor(s).
	 */
	Visibility* fVisibility;

	/**
	 * Name of the class. Must not be empty!
	 */
	QString fName;

	/**
	 * Type of the attribute. Currently, this is represented as
	 * a string, but maybe this should change to a specific C++ class as
	 * uml classes can be type of an attribute, too.
	 */
	QString fType;

	/**
	 * The multiplicity of the attribute.
	 */
	Multiplicity fMultiplicity;

	/**
	 * The default value of the attribute.
	 */
	QVariant fDefaultValue;

	/**
	 * The list of properties of the attribute.
	 * The following properties are defined in uml:
	 * - ordered The data is returned ordered.
	 * - read-only The attribute is read only.
	 */
	QStringList fProperties;
};

}

#endif /* _ATTRIBUTE_H_ */
