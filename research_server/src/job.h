/*
 * job.h
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#ifndef JOB_H_
#define JOB_H_

#include "linkedList.h"
#include "subSequence.h"
#include "ancestor.h"
#include "listObject.h"
#include <iostream>
#include <thread>
#include <string>
using namespace std;

class job : public listObject
{
public:
	job(char * args[]);
	~job();

	int getJobID();
	ancestor * getAncestorOne();
	ancestor * getAncestorTwo();
	subSequence * getSubSequence();
	string getString();
	int getStatus();
	linkedList * getSequenceQueue();
	linkedList * getProgessQueue();
	linkedList * getFinishedQueue();

private:
	void loadQueue(char *);

	int job_ID;
	int status;
	ancestor * ancestorOne;
	ancestor * ancestorTwo;

	thread *loadThrad;
	linkedList * sub_sequence_queue;
	linkedList * in_progress_queue;
	linkedList * finished_queue;
};

#endif /* JOB_H_ */
