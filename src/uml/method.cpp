/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * method.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "method.h"

namespace uml {

Method::Method(const QString name) : fName(name) {
	fVisibility = new Public();
}

Method::~Method() {
	// TODO Auto-generated constructor stub
}

}
