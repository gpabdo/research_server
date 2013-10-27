/*
 * communication.h
 *
 *  Created on: Oct 20, 2013
 *      Author: greg
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include "Socket.h"
#include "client.h"
#include "linkedList.h"
#include "listObject.h"
#include "message.h"

class communication
{
public:
	communication(linkedList*,linkedList*,linkedList*);
	~communication();

private:
	void runServer();
	void router();

	thread * theServer;			// Thread for receving new clients.
	thread * theRouter;			// Thread for routing packets to clients.

	linkedList * clients;		// List of clients.
	linkedList * tx_queue;		// Passed in list of packets to send
	linkedList * rx_queue;		// Passed in list to place pacets in.
	linkedList * log_list;		// Passed in list for the log file.
};

#endif /* COMMUNICATION_H_ */
