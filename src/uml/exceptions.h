/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * exceptions.h
 *
 *  Created on: 23.07.2010
 *      Author: Robert Jakob
 */

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#include <QString>

namespace uml {

class Exception {
private:
	QString fExceptionMessage;
public:
	Exception(QString message) : fExceptionMessage(message) {};
	virtual ~Exception() {};
};

class InvalidParameterException : public Exception {
public:
	InvalidParameterException(QString name) : Exception(name) {};
	virtual ~InvalidParameterException() {};
};

}

#endif /* _EXCEPTIONS_H_ */
