/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * umldiagramprovider.h
 *
 *  Created on: 11.09.2010
 *      Author: Robert Jakob
 */

#ifndef _UMLDIAGRAMPROVIDER_H_
#define _UMLDIAGRAMPROVIDER_H_

#include <QString>
#include "../exceptions.h"

namespace atuml {

/**
 * An interface providing methods to store and load
 * a uml diagram.
 */
class UmlDiagramProvider {
public:

    /**
     * Reads a uml diagram from a given string.
     * An InvalidUmlDiagramException exception (or subclass) is thrown
     * if there occurs an error during the read.
     * @param xml The string containing an xml representing an uml diagram.
     */
    virtual void readFromXml(const QString& xml) = 0;

    /**
     * Writes a uml diagram to an xml string.
     *
     * @return Returns a xml string describing the uml diagram.
     */
    virtual QString writeToXml() = 0;
};

}

#endif /* _UMLDIAGRAMPROVIDER_H_ */
