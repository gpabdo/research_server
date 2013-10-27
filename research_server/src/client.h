/*
 * client.h
 *
 *  Created on: Oct 20, 2013
 *      Author: greg
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "linkedList.h"
#include "listObject.h"
#include "message.h"
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include "Socket.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

class client : public listObject
{
public:
	client(int, linkedList *);
	~client();

	int getFd();
	string getString();

private:
	void rx();

	int fd;
	thread *rx_thread;
	linkedList * rx_queue;
};


#endif /* CLIENT_H_ */
