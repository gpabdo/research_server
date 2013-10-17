/*
 * research_server.h
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#ifndef RESEARCH_SERVER_H_
#define RESEARCH_SERVER_H_

#include "linkedList.h"
#include "job.h"
#include "message.h"
#include "worker.h"
#include "subSequence.h"
#include "taskTracker.h"
#include <iostream>
#include <thread>
using namespace std;

class research_server
{
public:
	research_server();
	~research_server();
	void start();

private:
	void ui();
	int getStatus();
	void addJob(char * array[]);
	void runJob();
	void handleRxQueue();
	void registerWorker();
	void deregisterWorker();
	void loadJob();
	void txThread();
	void rxThread();

	int status;

	thread *tx;
	thread *rx;
	thread *runner;

	linkedList *TX_queue;
	linkedList *RX_queue;

	linkedList *job_list;
	linkedList *worker_list;
	linkedList *worker_queue;

	job *current_job;
	linkedList *to_do_queue;
	linkedList *in_progress_queue;
	linkedList *finished_queue;
};


#endif /* RESEARCH_SERVER_H_ */
