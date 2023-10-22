#ifndef __LIB_HEAP_HEADER__
#define __LIB_HEAP_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _HEAP_NODE HEAP_NODE;
typedef struct _HEAP HEAP;

struct _HEAP_NODE {
	int key;
	void *data;
};

struct _HEAP {
	HEAP_NODE *heapArray;
	int size;
	int lastIndex;

	//Method Functions
	HEAP *(*Create)(HEAP *, int);
	HEAP *(*Destroy)(HEAP *);
	HEAP *(*Enqueue)(HEAP *, HEAP_NODE *);
	HEAP *(*Dequeue)(HEAP *, HEAP_NODE *);
	HEAP *(*Swap)(HEAP *, int, int);
	int (*Empty)(HEAP *);
};

//Function Declarations
void HEAP_CONSTRUCTOR(HEAP *);
void HEAP_DESTRUCTOR(HEAP *);
HEAP *HEAP_METHOD_Create(HEAP *, int);
HEAP *HEAP_METHOD_Destroy(HEAP *);
HEAP *HEAP_METHOD_Enqueue(HEAP *, HEAP_NODE *);
HEAP *HEAP_METHOD_Dequeue(HEAP *, HEAP_NODE *);
int HEAP_METHOD_Empty(HEAP *);
HEAP *HEAP_METHOD_Swap(HEAP *, int, int);
#endif
