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

#include <memory>

class QString;
class QStringList;
class QVariant;

namespace atuml {

namespace uml {

class Multiplicity;

/**
 * Class representing a parameter of an operation (method) of a class.
 * A parameter is described as follows:
 *    [direction] name : type [ multiplicity ] [= defaultValue] [{property*}]
 */
class Parameter {
public:
    enum class Direction {
        IN,
        OUT,
        INOUT
	};

	/**
	 * Constructs a new parameter with the given name and type.
	 * Both are mandatory, otherwise an exception is thrown.
	 */
	Parameter(const QString name, const QString type);

	/**
	 * Comparison of Parameter objects is done by comparing
	 * their name. This should be sufficient (inside methods!)
	 *
	 * @param other The parameter which is compared to the current.
	 * @return Returns true of the names are equal.
	 */
	bool operator==(const Parameter &other) const;

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
	 * Getter for the parameter direction.
	 *
	 * @return Returns the direction of the parameter.
	 */
	Direction direction() const;

	/**
	 * Getter for the name of the parameter.
	 *
	 * @return Returns the name of the parameter.
	 */
	QString name() const;

	/**
	 * Getter for the type of the parameter.
	 *
	 * @return Returns the type of the parameter.
	 */
	QString type() const;

	/**
	 * Getter for the multiplicity of the parameter.
	 *
	 * @return Returns the multiplicity of the parameter.
	 */
	Multiplicity multiplicity() const;

	/**
	 * Getter for the default of the parameter.
	 *
	 * @return Returns the default of the parameter.
	 */
	QVariant defaultValue() const;

	/**
	 * Getter for the properties of the parameter.
	 *
	 * @return Returns a non-modifiable list of properties of the parameter.
	 */
	const QStringList properties() const;

private:
    struct Pimpl;
    std::shared_ptr<Pimpl> impl_;
};

}

}

#endif /* _PARAMETER_H_ */
