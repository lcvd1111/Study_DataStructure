#ifndef __LIB_UNION_FIND_HEADER__
#define __LIB_UNION_FIND_HEADER__

#include "common.hh"

//Type Defintions and Declarations
typedef class _UNION_FIND UNION_FIND;

class _UNION_FIND {
private:
	int size;
	std::vector<int> predecessorArray;
	std::vector<int> setSizeArray;

public:
	_UNION_FIND(void);
	~_UNION_FIND(void);
	UNION_FIND *Create(int);
	UNION_FIND *Destroy(void);
	int Find(int);
	UNION_FIND *Unite(int, int);
	int Same(int, int);
	int CollectionSize(void);
	int SetSize(int);
};

#endif
