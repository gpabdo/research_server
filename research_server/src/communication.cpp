/*
 * communication.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: greg
 */

#include "communication.h"

/******************************************************************
*
******************************************************************/
communication::communication(linkedList * tx, linkedList * rx, linkedList * log)
{
	clients = new linkedList();
	tx_queue = tx;
	rx_queue = rx;
	log_list = log;
	theServer = new thread(&communication::runServer, this);
	theRouter = new thread(&communication::router, this);
}

/******************************************************************
*
******************************************************************/
communication::~communication()
{
	delete clients;
}

/******************************************************************
*
******************************************************************/
void communication::runServer()
{
	int sd, newSd;
	sd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in server;
	bzero( (char *)&server, sizeof( server ) );
	server.sin_family =AF_INET;
	server.sin_addr.s_addr = htonl( INADDR_ANY );
	server.sin_port = htons( 12345 );

	bind( sd, (sockaddr *)&server, sizeof( server ) );

	sockaddr_in clientSoc;
	socklen_t len=sizeof(clientSoc);

	while( true )
	{
		newSd = accept(sd, (sockaddr *)&clientSoc, &len);
		clients->pushToBack( new client(newSd, rx_queue) );
		close(sd);
		//read( newSd, buf2, sizeof( buf2 ) );
	 }

}

/******************************************************************
*
******************************************************************/
void communication::router()
{
	while(true)
	{
		if(!tx_queue->isEmpty())
		{
			message * nextMessage = (message*)tx_queue->popFront();

			for(int i = 0; i < clients->getLength(); i++)
			{
				client * theClient = (client*)clients->peekAt(i);
				if( theClient->getFd() == nextMessage->getFd() )
				{
					//theClient->send(nextMessage);
				}
			}
		}

	}
}
