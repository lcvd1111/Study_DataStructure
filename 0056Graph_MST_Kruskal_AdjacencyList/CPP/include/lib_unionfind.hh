#ifndef __LIB_UNION_FIND_HEADER__
#define __LIB_UNION_FIND_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef struct _UNION_FIND UNION_FIND;

class _UNION_FIND {
public:
	std::vector<int> successorVector;
	std::vector<int> sizeVector;
	int collectionSize;

	//Method Functions
	_UNION_FIND(void);
	~_UNION_FIND(void);
	UNION_FIND *Create(int);
	UNION_FIND *Destroy(void);
	UNION_FIND *Unite(int, int);
	int Find(int);
	int Size(int);
	int Same(int, int);
};

#endif
