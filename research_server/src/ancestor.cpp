#include "ancestor.h"

ancestor::ancestor( char * source )
{
	ifstream fs;
	fs.open(source);

	string temp;
	if(fs.is_open())
	{
		status = 1;
		getline(fs, ID );
		while(!fs.eof())
		{
			getline(fs, sequence);
			temp += sequence;
		}

		for( int i = 0; i < temp.length(); i++)
			if (temp[i] != '\n')
				sequence[i] = temp[i];

		fs.close();
		status = 2;
		return;
	}
	status = -1;
}

ancestor::~ancestor()
{

}

string ancestor::getSequence()
{
	return sequence;
}

int ancestor::getLength()
{
	return sequence.length();
}

int ancestor::getStatus()
{
	return status;
}
