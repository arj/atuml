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
#include <exception>
#include <cassert>

namespace atuml {

namespace uml {

QString visibilityToString(const Visibility &v) {
    switch (v) {
    case Visibility::PUBLIC: return "+";
    case Visibility::PROTECTED: return "#";
    case Visibility::PRIVATE: return "-";
    case Visibility::PACKAGE: return "~";
    default: Q_ASSERT_X(false, Q_FUNC_INFO, "Invalid enumeration value");
        throw std::logic_error("Invalid enumeration value for visibility");
    }
}

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
