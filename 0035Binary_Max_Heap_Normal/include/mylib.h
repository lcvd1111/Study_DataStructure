#ifndef __MY_LIB_HEADER__
#define __MY_LIB_HEADER__

#include <iostream>
#include <cstring>

#define STRING_LEN 128

#define DEBUG "["<<__LINE__<<", "<<__func__<<"]"

//Type Definitions and Declarations
typedef struct _HEAP_NODE {
	int key;
	char data[STRING_LEN];
} HEAP_NODE;

typedef struct _MAX_BINARY_HEAP {
	HEAP_NODE *heapArray;
	unsigned int depth;
	unsigned int maxNum;
	int lastIndex;
} MAX_HEAP;

//Function Declarations
MAX_HEAP *CreateHeap(int);
int DeleteHeap(MAX_HEAP *);
int SwapNode(HEAP_NODE *, HEAP_NODE *);
MAX_HEAP *Insert(MAX_HEAP *, int, const char *);
MAX_HEAP *Delete(MAX_HEAP *, HEAP_NODE *outputStore);
#endif
