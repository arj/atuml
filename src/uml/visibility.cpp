/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * visibility.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include <QString>
#include <QApplication>
#include "../exceptions.h"
#include "visibility.h"

namespace atuml {

namespace uml {

Visibility makeVisibility(const QString& code) {
    if (code == "+") {
        return Visibility::PUBLIC;
    } else if (code == "#") {
        return Visibility::PROTECTED;
    } else if (code == "-") {
        return Visibility::PRIVATE;
    } else if (code == "~") {
        return Visibility::PACKAGE;
    }

    QString msg = QString("Unknown parameter for visibility construction \"%1\"").arg(code);
    throw atuml::InvalidParameterException(qApp->translate("Exception", qPrintable(msg)));
}

}

}
