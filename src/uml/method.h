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

class Method {
public:
	Method(const QString name);

	/**
	 * Comparison of Method objects is done by comparing
	 * their name. This should be sufficient (inside classes!)
	 */
	bool operator==(const Method &other) const {
		return this->fName == other.fName;
	}

	/* Getters */
	QString name() const;

private:
	Visibility* fVisibility;
	QString fName;
	QList<Parameter> fParameter;
	QString fReturnType;
	QStringList fProperties;
};

}

#endif /* _METHOD_H_ */
