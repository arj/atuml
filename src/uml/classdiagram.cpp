/*
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * classdiagram.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "classdiagram.h"

namespace uml {

void ClassDiagram::addClass(Class *theclass) {
	fClasses.append(theclass);
}

const QList<Class*> ClassDiagram::classes() const {
    return fClasses;
}

}
