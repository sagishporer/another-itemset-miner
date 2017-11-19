/*----------------------------------
File     : data.cpp
Contents : data set management
----------------------------------*/

#include "StdAfx.h"
#include <vector>
#include <algorithm>
using namespace std;
#include "data.h"

Data::Data(char *filename)
{
	in = fopen(filename,"rt");

	// Init buffered reading members
	readBuffer = (char*)malloc (sizeof(char)*READ_BUFFER_SIZE);
	readBufferLastRead = 0;
	readBufferNextPos = 0;
}

Data::~Data()
{
  if(in) fclose(in);

  if (readBuffer != NULL)
	  free(readBuffer);
}

int Data::isOpen()
{
  if(in) return 1;
  else return 0;
}

char Data::getNextCharFromFile()
{
	if (readBufferNextPos >= readBufferLastRead)
	{
		if (feof(in))
			return NULL;

		readBufferLastRead = fread(readBuffer, 1, READ_BUFFER_SIZE, in);
		readBufferNextPos = 0;

		if (readBufferLastRead <= 0)
			return NULL;
	}

	return readBuffer[readBufferNextPos++];
}

bool Data::getNextTransaction(Transaction &t)
{
	char c;

	t.Init();

	// read list of items
	do 
	{
		unsigned int item=0, pos=0;
		c = getNextCharFromFile();

		while((c >= '0') && (c <= '9')) {
			item *=10;
			item += c - '0';

			c = getNextCharFromFile();
			pos++;
		}
		if(pos)       
			t.Add(item);
	}
	while(c != '\n' && c != NULL);

	// if end of file is reached, rewind to beginning for next pass
	if (c == NULL)
		return false;

	return true;
}


/*
// Read from file - one char at a time
bool Data::getNextTransaction(Transaction &t)
{
	char c;

	t.Init();

	// read list of items
	do 
	{		
		unsigned int item=0, pos=0;
		c = getc(in);
		while((c >= '0') && (c <= '9')) {
			item *=10;
			item += c - '0';

			c = getc(in);
			pos++;
		}
		if(pos)       
			t.Add(item);
	}
	while(c != '\n' && !feof(in));
  
	// if end of file is reached, rewind to beginning for next pass
	if(feof(in))
		return false;

	return true;
}
*/