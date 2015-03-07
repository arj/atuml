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

class QString;

namespace atuml {

namespace uml {

enum class Visibility {
    PUBLIC,
    PROTECTED,
    PRIVATE,
    PACKAGE
};

/**
 * @brief makeVisibility creates a Visibility value from the UML string symbols "+#-~".
 * @param code The string describing the symbol.
 * @return Returns the newly created symbol or throws an exception atuml::InvalidParameterException.
 */
Visibility makeVisibility(const QString& code);

}

}

#endif /* _VISIBILITY_H_ */
