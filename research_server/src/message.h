/*
 * message.h
 *
 *  Created on: Oct 15, 2013
 *      Author: greg
 */

#ifndef MESSAGE_H_
#define MESSAGE_H_

#include "listObject.h"

class message : public listObject
{
public:
	message(int, int);		// Pass in fd and command;

	void setFd();
	void setStatus();
	void setCommand();
	void setData(string);

	int getFd();
	int getCommand();
	int getStatus();
	string getString();

private:
	int fd;
	int command;
	int status;
	string data;
};


#endif /* MESSAGE_H_ */
