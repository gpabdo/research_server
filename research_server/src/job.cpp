/*
 * job.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#include "job.h"

/******************************************************************
*
******************************************************************/
job::job(char * args[])
{
	sub_sequence_queue = new linkedList();

	ancestorOne  = new ancestor(args[0]);
	if( ancestorOne->getStatus() == -1)
	{
		status = -1;
		return;
	}

	ancestorTwo  = new ancestor(args[1]);
	if(ancestorTwo->getStatus() == -1)
	{
		status = -2;
		return;
	}

	loadThrad = new thread(&job::loadQueue, this, args[2]);
}

/******************************************************************
*
******************************************************************/
void job::loadQueue(char * source)
{
	ifstream fd;
	fd.open(source);

	if (fd.is_open())
	{
		status = 1;		// Loading.
		while(!fd.eof() )
			sub_sequence_queue->pushToBack(new subSequence(fd));
		fd.close();
		status = 2; 	// Loaded.
	}
	else
		status = -3; 	// Load Error.
}

/******************************************************************
*
******************************************************************/
int job::getJobID()
{
	return job_ID;
}

/******************************************************************
*
******************************************************************/
ancestor * job::getAncestorOne()
{
	return ancestorOne;
}

/******************************************************************
*
******************************************************************/
ancestor * job::getAncestorTwo()
{
	return ancestorTwo;
}

/******************************************************************
*
******************************************************************/
subSequence * job::getSubSequence()
{
	return (subSequence*)sub_sequence_queue->popFront();
}

/******************************************************************
*
******************************************************************/
string job::getString()
{
	return "Job ID: " + job_ID;
}

/******************************************************************
*
******************************************************************/
int job::getStatus()
{
	return status;
}

/******************************************************************
*
******************************************************************/
linkedList * job::getSequenceQueue()
{
	return sub_sequence_queue;
}

/******************************************************************
*
******************************************************************/
linkedList * job::getProgessQueue()
{
	return in_progress_queue;
}

/******************************************************************
*
******************************************************************/
linkedList * job::getFinishedQueue()
{
	return finished_queue;
}
