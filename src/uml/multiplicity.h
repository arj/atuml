/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * multiplicity.h
 *
 *  Created on: 20.07.2010
 *      Author: Robert Jakob
 */

#ifndef _MULTIPLICITY_H_
#define _MULTIPLICITY_H_

class Multiplicity {
public:
	Multiplicity(int min=1, int max=1) : minimum(min), maximum(max) {}

	int minimum;
	int maximum;
};

#endif /* _MULTIPLICITY_H_ */
