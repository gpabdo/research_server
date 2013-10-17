/*
 * taskTracker.h
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#ifndef TASKTRACKER_H_
#define TASKTRACKER_H_

#include "listObject.h"
#include "subSequence.h"
#include "worker.h"
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

class taskTracker : public listObject
{
public:
	taskTracker(int, subSequence *);
	~taskTracker();

	string getString();

private:
	int fd;
	subSequence *theSequence;

	timeval startTime;
	timeval endTime;

	int ancestor;
	bool reverse;
	double startLocation;
	double endLocation;
	int insertions;
	int deletions;

};


#endif /* TASKTRACKER_H_ */
