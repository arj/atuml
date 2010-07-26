/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * multiplicity.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _MULTIPLICITY_H_
#define _MULTIPLICITY_H_

#include <QApplication>
#include "exceptions.h"

namespace uml {

/**
 * Class representing a integer interval in [0,Infinity).
 * Here, infinity is set to MAXQUINT32. If quint32 is changed,
 * change the casts in the test case accordingly!
 */
class Multiplicity {
public:
	/**
	 * Static "constant" variable to represent infinity.
	 * It is initialized to MAXQUINT32 (see .cpp file).
	 */
	static const quint32 Infinity;

	/**
	 * Create a new object with default settings to (1,1).
	 */
	Multiplicity(quint32 min = 1, quint32 max = 1) {
		set(min, max);
	}

	/**
	 * Comparison of multiplicity objects is done by comparing
	 * the interval bounds. If both are equal, the objects are equal,
	 * otherwise they are not.
	 */
	bool operator==(const Multiplicity &other) const {
		return this->fminimum == other.fminimum && this->fmaximum
				== other.fmaximum;
	}

	/**
	 * Not equal comparison by negation of equality.
	 */
	bool operator!=(const Multiplicity &other) const {
		return !(*this == other);
	}

	/**
	 * Getter for minimum value.
	 */
	quint32 minimum() const {
		return fminimum;
	}

	/**
	 * Getter for maximum value.
	 */
	quint32 maximum() const {
		return fmaximum;
	}

	/**
	 * Setter for minimum and maximum value.
	 * Checks if minimum <= maximum and throws an InvalidParameterException
	 * otherwise.
	 * There is only one combined setter to prevent initialization
	 * independent code flow, i.e.
	 *   Multiplicity m(5,10);
	 *   m.setMaximum(3);
	 *   m.setMinimum(1);
	 * should throw an exception, whereas
	 *   Multiplicity m(5,10);
	 *   m.setMinimum(1);
	 *   m.setMaximum(3);
	 * Thus, it is better to have one common setter.
	 */
	void set(quint32 minimum, quint32 maximum) {
		if (minimum > maximum) {
			throw InvalidParameterException(qApp->translate("Exception",
					"Minimum must be smaller or equal than maximum."));
		}

		fminimum = minimum;
		fmaximum = maximum;
	}

private:
	quint32 fminimum;
	quint32 fmaximum;
};

}

#endif /* _MULTIPLICITY_H_ */
