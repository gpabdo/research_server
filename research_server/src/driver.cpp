//============================================================================
// Name        : research_server.cpp
// Author      : Greg Abdo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "research_server.h"
using namespace std;

int main() {

	research_server *server = new research_server();
	server->start();
	return 0;
}
