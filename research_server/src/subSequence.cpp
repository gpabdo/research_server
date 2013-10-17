#include "subSequence.h"

/******************************************************************
*
******************************************************************/
subSequence::subSequence(ifstream & theStream)
{
	if (theStream.is_open())
	{
		getline(theStream, sequenceID);
		getline(theStream, sequence);
		getline(theStream, sequencePlus);
		getline(theStream, sequenceQuality);
		reverseSequence = reverseString( sequence );
	}
}

/******************************************************************
*
******************************************************************/
subSequence::~subSequence()
{

}

/******************************************************************
*
******************************************************************/
string subSequence::getSubSequence()
{
	return sequence;
}

/******************************************************************
*
******************************************************************/
string subSequence::getSubSequenceID()
{
	return sequenceID;
}

/******************************************************************
*
******************************************************************/
string subSequence::getSubSequenceQuality()
{
	return sequenceQuality;
}

/******************************************************************
*
******************************************************************/
string subSequence::getString()
{
	string line;
	line += "Sequence ID: ";
	line += sequenceID;
	line += "\n\rSequence: ";
	line += sequence;
	line += "\n\r";
	return line;
}

/******************************************************************
*
******************************************************************/
int subSequence::getLength()
{
	return sequence.length();
}

/******************************************************************
*
******************************************************************/
string subSequence::getReverseSubSequence()
{
	return reverseSequence;
}

/******************************************************************
*
******************************************************************/
string subSequence::reverseString( string theString )
{
	string reverse;
	for( int i = 0; i < theString.length(); i++)
		reverse += theString[theString.length() - 1 - i];

	return reverse;
}
