/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * parameter.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _PARAMETER_H_
#define _PARAMETER_H_

#include <QString>
#include <QStringList>
#include <QVariant>
#include "multiplicity.h"

namespace uml {

/**
 * Class representing a parameter of an operation (method) of a class.
 * A parameter is described as follows:
 *    [direction] name : type [ multiplicity ] [= defaultValue] [{property*}]
 */
class Parameter {
public:
	enum Direction {
		in, out, inout
	};

	/**
	 * Constructs a new parameter with the given name and type.
	 * Both are mandator, otherwise an exception is thrown.
	 */
	Parameter(const QString name, const QString type);

	/**
	 * Setter for direction.
	 */
	void setDirection(Direction direction);

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
	 * Comparison of Parameter objects is done by comparing
	 * their name. This should be sufficient (inside methods!)
	 */
	bool operator==(const Parameter &other) const {
		return this->fName == other.fName;
	}

	/* Getter */
	Direction direction() const;
	QString name() const;
	QString type() const;
	Multiplicity multiplicity() const;
	QVariant defaultValue() const;
	const QStringList properties() const;

private:
	Direction fDirection;
	QString fName;
	QString fType;
	Multiplicity fMultiplicity;
	QVariant fDefaultValue;
	QStringList fProperties;
};

}

#endif /* _PARAMETER_H_ */
