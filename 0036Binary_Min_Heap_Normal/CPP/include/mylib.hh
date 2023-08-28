#ifndef __MY_LIB_HEADER__
#define __MY_LIB_HEADER__

#include <iostream>
#include <cstring>
#include <cstdlib>

#define STRING_LEN 64
#define DEBUG "["<<__func__<<" "<<__LINE__<<"]"

//Type declarations and definitions
class _BINARY_MIN_HEAP_NODE {
public:
	int id;
	char data[STRING_LEN];
};

typedef class _BINARY_MIN_HEAP_NODE HEAP_NODE;

class _BINARY_MIN_HEAP {
public:
	HEAP_NODE *heapArray;
	int level;
	unsigned int size;
	long int lastIndex;

	//Method Declarations
	class _BINARY_MIN_HEAP *Enqueue(int, const char *);
	class _BINARY_MIN_HEAP *Dequeue(HEAP_NODE *);
};

typedef class _BINARY_MIN_HEAP HEAP;

//Function Declarations
HEAP *CreateHeap(int);
int DestroyHeap(HEAP *);
int SwapNode(HEAP_NODE *, HEAP_NODE *);

#endif 
