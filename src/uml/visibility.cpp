/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * visibility.cpp
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#include "visibility.h"

namespace uml {

QString Public::string()
{
	return "+";
}

QString Protected::string()
{
	return "#";
}

QString Private::string()
{
	return "-";
}

QString Package::string()
{
	return "~";
}

}
