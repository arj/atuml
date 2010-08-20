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
 * Class representing an attribute (property) of a class.
 * An attribute is described as follows:
 *   [Visibility] [/] name [: Type] [ multiplicity ] [= defaultValue] [{property*}]
 */
class Attribute {
public:
	/**
	 * Construct a new attribute with the name given.
	 * Throws an InvalidParameterException if name is empty.
	 */
	Attribute(const QString name);

	/**
	 * Copy constructor.
	 * Copies all the private referenced elements.
	 */
	Attribute(const Attribute& copy);

	/**
	 * Deconstructor which removes create variables.
	 */
	virtual ~Attribute();

	/**
	 * Setter for visibility.
	 * Throws InvalidParameterException if parameter is null.
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

	/* Getters */
	Visibility* visibility() const;
	QString name() const;
	QString type() const;
	Multiplicity multiplicity() const;
	QVariant defaultValue() const;
	const QStringList properties() const;

private:
	Visibility* fVisibility;
	QString fName;
	QString fType;
	Multiplicity fMultiplicity;
	QVariant fDefaultValue;
	QStringList fProperties;
};

}

#endif /* _ATTRIBUTE_H_ */
