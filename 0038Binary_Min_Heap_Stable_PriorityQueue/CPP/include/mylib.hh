#ifndef __MY_LIB_HEADER__
#define __MY_LIB_HEADER__

#include <iostream>
#include <cstdlib>
#include <cstring>

#define STRING_LEN 64
#define DEBUG std::cout<<"["<<__LINE__<<" "<<__func__<<"]"

//Type Declarations and Definitions including Methods Declarations
typedef class _STABLE_MIN_HEAP_NODE HEAP_NODE;
typedef class _STABLE_MIN_HEAP HEAP;

class _STABLE_MIN_HEAP_NODE {
public:
	int id;
	char data[STRING_LEN];
	int enqOrder;
};

class _STABLE_MIN_HEAP{
public:
	HEAP_NODE *heapArray;
	int level;
	unsigned int size;
	long int lastIndex;
	long int lastEnqOrder;

	//Methods Declarations
	_STABLE_MIN_HEAP(void);
	_STABLE_MIN_HEAP(int);
	~_STABLE_MIN_HEAP(void);
	HEAP *Enqueue(int, const char *);
	HEAP *Dequeue(HEAP_NODE *);
};

int SwapNode(HEAP_NODE *, HEAP_NODE *);
#endif
