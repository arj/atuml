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
#include "visibility.h"
#include "multiplicity.h"

class Attribute {
public:
	Attribute(const QString name);
	virtual ~Attribute();

	void setVisibility(Visibility* visibility);
	void setName(const QString name);
	void setType(const QString type);
	void setMultiplicity(const Multiplicity multiplicity);
	void setDefaultValue(const QVariant defaultValue);

	// TODO missing set/get fProperties

	Visibility* visibility() const;
	QString name() const;
	QString type() const;
	Multiplicity multiplicity() const;
	QVariant defaultValue() const;

private:
	Visibility* fVisibility;
	QString fName;
	QString fType; // TODO maybe an additional field for some reference?
	Multiplicity fMultiplicity;
	QVariant fDefaultValue;
	QStringList fProperties;
};

#endif /* _ATTRIBUTE_H_ */
