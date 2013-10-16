#ifndef ANCESTOR_H_
#define ANCESTOR_H_

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class ancestor
{
public:
	ancestor(char *);
	~ancestor();

	string getSequence();
	int getLength();
	int getStatus();

private:
	int status;
	string ID;
	string sequence;
};

#endif
