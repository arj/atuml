/*
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * class.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _CLASS_H_
#define _CLASS_H_

#include <QList>
#include "attribute.h"
#include "method.h"

#include <memory>

class QString;

namespace atuml {

namespace uml {

class Attribute;
class Method;

/**
 * This class represents an uml class. A uml class consists of
 * attributes, methods and some additional values like abstractness or
 * activity.
 */
class Class {

public:
	/**
	 * Standard constructor.
	 * The standard constructor expects the name of the class.
	 * If must not be empty, otherwise an InvalidParameterException is thrown.
	 *
	 * @param name The name of the new class.
	 */
    explicit Class(const QString name);

	/**
	 * Adds a new method to the class.
	 * The method must not exist in the list before. If the method exists,
	 * nothing happens. The comparison is based on a comparison of the
	 * method, i.e. it is name based.
	 *
	 * @param method The new method to add.
	 */
	void addMethod(Method method);

	/**
	 * Adds a new attribute to the class.
	 * If the attribute already exists (see attribute comparison), then nothing
	 * happens.
	 *
	 * @param attribute The attribute to add.
	 */
	void addAttribute(Attribute attribute);

	/**
	 * Removes a method from the class.
	 * If the method does not exist, nothing happens. The method removed is
	 * determined by method comparison.
	 *
	 * @param method The method to remove.
	 */
	void removeMethod(Method method);

	/**
	 * Removes an attribute from the class.
	 * If the attribute does not exist, nothing happens. The attribute removed
	 * is determined by attribute comparison.
	 *
	 * @param attribute The attribute to remove.
	 */
	void removeAttribute(Attribute attribute);

	/**
	 * Returns a non-modifiable list of methods which are available in this
	 * class.
	 * List is copied, but the elements are not (if they are not changed),
	 * according to the Qt docs.
	 *
	 * @return Returns the list of methods.
	 */
	const QList<Method> methods() const;

	/**
	 * Returns a non-modifiable list of attributes which are available in this
	 * class.
	 * List is copied, but the elements are not (if they are not changed),
	 * according to the Qt docs.
	 *
	 * @return Returns the list of attributes.
	 */
	const QList<Attribute> attributes() const;

	/**
	 * Sets a new name for the class.
	 *
	 * @param name The new name.
	 */
	void setName(const QString name);

	/**
	 * Sets/removes the abstract property of the class.
	 *
	 * @param value The new value of the abstract property.
	 */
	void setAbstract(bool value);

	/**
	 * Sets/removes the active property of the class.
	 *
	 * @param value The new value of the active property.
	 */
	void setActive(bool value);

	/**
	 * Getter for the abstract property.
	 *
	 * @return Returns the current value of the abstractness property.
	 */
	bool abstract() const;

	/**
	 * Getter for the class name.
	 *
	 * @return Returns the name of the class.
	 */
	QString name() const;

	/**
	 * Getter for the active property.
	 *
	 * @return Returns the current value of the activity property.
	 */
	bool active() const;

private:
    struct Pimpl;
    std::shared_ptr<Pimpl> impl_;
};

}

}

#endif
