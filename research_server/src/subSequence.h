

#ifndef SUBSEQUENCE_H_
#define SUBSEQUENCE_H_

#include <string>
#include <fstream>
#include <iostream>
#include "listObject.h"
using namespace std;

class subSequence: public listObject
{
public:
	subSequence(ifstream&);
	~subSequence();

	string getSubSequence();
	string getReverseSubSequence();
	string getSubSequenceQuality();
	string getSubSequenceID();

	string getString();
	int getLength();

private:
	string reverseString( string theString );
	string sequence;
	string reverseSequence;
	string sequenceQuality;
	string sequenceID;
	string sequencePlus;
};

#endif
