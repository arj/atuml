/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * visibility.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _VISIBILITY_H_
#define _VISIBILITY_H_

#include <QString>

class Visibility {
public:
	virtual QString string() = 0;
};


class Public : public Visibility {
public:
	virtual QString string();
};

class Protected : public Visibility {
public:
	virtual QString string();
};

class Private : public Visibility {
public:
	virtual QString string();
};

class Package : public Visibility {
public:
	virtual QString string();
};

#endif /* _VISIBILITY_H_ */
