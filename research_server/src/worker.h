/*
 * worker.h
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#ifndef WORKER_H_
#define WORKER_H_

#include "listObject.h"

class worker : public listObject
{
public:
	worker(int);
	string getString();
	int getAddress();
	int getStatus();
	int getFd();

private:
	int fd;
	int address;
	int status;
};

#endif /* WORKER_H_ */
