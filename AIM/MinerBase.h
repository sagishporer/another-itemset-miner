#ifndef __MINERBASE
#define __MINERBASE

#include <vector>
#include <string>
#include <set>
#include "data.h"
#include "Items.h"
#include "IntToString.h"

#define SEPERATOR ' '

typedef int* pInt;

class CMinerBase
{
public:
	CMinerBase(void);
	~CMinerBase(void);

	void Init(char *fileName, int minSupport, bool sort = false);
	void LoadDatabase(char *fileName);
	int GetDBCount();
	void Build2ItemsetMatrix(char *fileName);

	// vertical database
	CItems items;

protected:
		// 2 Items upper matrix
	int **p2ItemsMatrix;

		// pure database
	unsigned int transactionCount;
	unsigned int dbItemsCount;
};

#endif