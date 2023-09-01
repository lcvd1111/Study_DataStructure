#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG( x , ... ) printf("[%d %s]" x, __LINE__, __func__, ##__VA_ARGS__)
#define STRING_LEN 64

//Type Declarations and Definitions
typedef struct STABLE_MIN_HEAP_NODE HEAP_NODE;
typedef struct STABLE_MIN_HEAP HEAP;

struct STABLE_MIN_HEAP_NODE {
	int id;
	char data[STRING_LEN];
	long int enqOrder;
};

struct STABLE_MIN_HEAP {
	HEAP_NODE *heapArray;
	int level;
	unsigned int size;
	long int lastIndex;
	long int lastEnqOrder;

	//Method Members
	HEAP *(*Enqueue)(HEAP *self, int, const char *);
	HEAP *(*Dequeue_P)(HEAP *self, HEAP_NODE *);//_P = with Priority
};

//Function Declarations
HEAP *MallocHeap(int);
int FreeHeap(HEAP *);
HEAP *Constructotr_Heap(HEAP *, int);
HEAP *Destructor_Heap(HEAP *);
HEAP *METHOD_Enqueue(HEAP *self, int, const char *);
HEAP *METHOD_Dequeue_P(HEAP *self, HEAP_NODE *);
int SwapNode(HEAP_NODE *, HEAP_NODE *);
#endif
