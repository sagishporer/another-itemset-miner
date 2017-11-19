#ifndef __DATA
#define __DATA
/*----------------------------------------------------------------------
  File     : data.h
  Contents : data set management
----------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define READ_BUFFER_SIZE (16*1024)

class Transaction
{
public:
	
	Transaction(int l) : length(0), count(l) { t = new int[l];}
	~Transaction(){delete [] t;}
  
	void Init() { length = 0; };

	inline void Add(int i)
	{
		if (length == count)
		{
			int *newArr = new int[count * 2];
			::memcpy(newArr, t, count * sizeof(int));
			delete[] t;
			t = newArr;
			count *= 2;
		}

		t[length++] = i;
	}

	int length;
	int *t;
private:
	int count;
};

class Data
{
public:
	Data(char *filename);
	~Data();

	int isOpen();
	  
	bool getNextTransaction(Transaction &t);
private:
	char getNextCharFromFile();

	char *readBuffer;
	int readBufferLastRead;
	int readBufferNextPos;

	FILE *in;
};

#endif