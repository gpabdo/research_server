//============================================================================
// Name        : research_server.cpp
// Author      : Greg Abdo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "research_server.h"

/******************************************************************
*
******************************************************************/
research_server::research_server()
{
	TX_queue = new linkedList();
	RX_queue = new linkedList();
	job_list = new linkedList();
	worker_list = new linkedList();
	worker_queue = new linkedList();
	current_job = NULL;
	to_do_queue = NULL;
	in_progress_queue = NULL;
	finished_queue = NULL;
	tx = new thread(&research_server::txThread, this);
	rx = new thread(&research_server::rxThread, this);
	runner = new thread(&research_server::runJob, this);
	ui();
}

/******************************************************************
*
******************************************************************/
void research_server::ui()
{
	while( true )
	{
		cout << "-- research_server loaded --" <<endl << endl;
		cout << "Welcome to research server, this software is meant " << endl;
		cout << "for DNA sequence analysis on distributed systems." << endl;
		cout << "Enjoy!" << endl << endl;

		// TODO get user input and load into queue

	}
}

/******************************************************************
*
******************************************************************/
void research_server::runJob()
{
	while( true )
	{
		if(!job_list->isEmpty())
				loadJob();

		if(!RX_queue->isEmpty())
			handleRxQueue();

		if(current_job != NULL)
		{
			if(!worker_queue->isEmpty())
			{
				subSequence *seq = to_do_queue->popFront();
				worker * needsWork = worker_queue->popFront();
				message * newMessage = message(needsWork->getFd(), 103);
				newMessage->setData(seq->getSubSequence());
				TX_queue->pushToBack( newMessage);
				in_progress_queue->pushToBack(new taskTracker( needsWork->getFd(), seq));
			}
		}
	}
}

/******************************************************************
*
******************************************************************/
void research_server::handleRxQueue()
{
	message *temp = RX_queue->popFront();

	// Register new worker.
	if(temp->getCommand() == 100)
		worker_list->pushToBack(new worker(temp->getFd()));

	// Worker requesting Ancestor One.
	if(temp->getCommand() == 101)
	{
		message * newMessage = message(temp->getFd(), 101);
		newMessage->setData(current_job->getAncestorOne()->getSequence());
		TX_queue->pushToBack( newMessage);
	}

	// Worker requesting Ancestor Two.
	if(temp->getCommand() == 102)
	{
		message * newMessage = message(temp->getFd(), 102);
		newMessage->setData(current_job->getAncestorTwo()->getSequence());
		TX_queue->pushToBack( newMessage);
	}

	// Worker available .
	if(temp->getCommand() == 103)
	{
		for( int i = 0; i < worker_list->getLength(); i++)
		{
			worker * check = worker_list->peekAt(i);
			if( check->getFd() == temp->getFd() )
			{
				worker_queue->pushToBack(check);
				return;
			}
		}
	}
}

/******************************************************************
*
******************************************************************/
void research_server::txThread()
{

}

/******************************************************************
*
******************************************************************/
void research_server::rxThread()
{

}

/******************************************************************
*
******************************************************************/
void research_server::addJob(char * array[])
{
	job_list->pushToBack(new job(array));	// Add a new job to the queue.
}

/******************************************************************
*
******************************************************************/
void research_server::loadJob()
{
	if(!job_list->isEmpty())
	{
		current_job = (job*)job_list->popFront();			// Load next job into temp.
		to_do_queue = current_job->getSequenceQueue();		// Point to jobs sequence queue.
		in_progress_queue = current_job->getProgessQueue();	// Point to jobs progress queue.
		finished_queue = current_job->getFinishedQueue();	// Point to jobs finished queue.
	}
}

/******************************************************************
*
******************************************************************/
int research_server::getStatus()
{
	return status;
}