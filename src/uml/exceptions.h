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

/**
 * The basic exception class which is used for all uml based exceptions.
 */
class Exception {
public:
	/**
	 * Constructor which create a new exception.
	 *
	 * @param message The message of the exception.
	 */
	Exception(QString message) :
		fExceptionMessage(message) {
	}

	/**
	 * Virtual destructor. Not used but perhaps by subclasses.?
	 */
	virtual ~Exception() {
	}

private:
	/**
	 * The message of the exception.
	 */
	QString fExceptionMessage;
};

/**
 * The InvalidParameterException can be used if a given parameter
 * is not valid.
 */
class InvalidParameterException: public Exception {
public:

	/**
	 * Constructor creating an exception with a message.
	 *
	 * @param message The message for the exception.
	 */
	InvalidParameterException(QString message) :
		Exception(message) {
	}

	/**
	 * Virtual destructor. Not used but perhaps by subclasses.?
	 */
	virtual ~InvalidParameterException() {
	}
};

}

#endif /* _EXCEPTIONS_H_ */
