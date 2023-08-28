#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64
#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type definitions and Declarations
typedef struct _BINARY_MIN_HEAP_NODE {
	int id;
	char data[STRING_LEN];
} HEAP_NODE;

typedef struct _BINARY_MIN_HEAP {
	HEAP_NODE *heapArray;
	long int lastIndex;
	unsigned int level;
	unsigned int size;
	struct _BINARY_MIN_HEAP *(*Enqueue)
		(struct _BINARY_MIN_HEAP *, int idArg, const char *dataArg); 
	struct _BINARY_MIN_HEAP *(*Dequeue)
		(struct _BINARY_MIN_HEAP *, HEAP_NODE *);
} HEAP;

//Fucntion Declarations
HEAP *CreateHeap(unsigned int levelArg);
int DestroyHeap(HEAP *);
int SwapNode(HEAP_NODE *, HEAP_NODE *);
////Method Function Delcarations
HEAP *METHOD_Enqueue(HEAP *self, int idArg, const char *dataArg);
HEAP *METHOD_Dequeue(HEAP *self, HEAP_NODE *outputStore);

#endif
