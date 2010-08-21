/* 
 * This file is part of the Atuml project.
 * http://www.bitflipper.de/atuml
 *
 * sleeperthread.h
 *
 *  Created on: 20.08.2010
 *      Author: Robert Jakob
 */

#ifndef _SLEEPERTHREAD_H_
#define _SLEEPERTHREAD_H_

class SleeperThread: public QThread {
public:
	static void msleep(unsigned long msecs) {
		QThread::msleep(msecs);
	}
};

#endif /* _SLEEPERTHREAD_H_ */
