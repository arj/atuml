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

class Parameter {
public:
	enum Direction {in, out, inout};

	// [Übergaberichtung] name : Typ [ Multiplizität ] [= Vorgabewert] [{eigenschaftswert*}]
	Parameter(const QString &name, const QString &type) : fName(name), fType(type) {}

private:
	Direction fDirection;
	QString fName;
	QString fType;
	Multiplicity fMultiplicity;
	QVariant fDefaultValue;
	QStringList properties;
};

}

#endif /* _PARAMETER_H_ */
