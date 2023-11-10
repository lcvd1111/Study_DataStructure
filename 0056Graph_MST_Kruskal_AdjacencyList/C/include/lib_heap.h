#ifndef __LIB_HEAP_HADER__
#define __LIB_HEAP_HADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _MIN_HEAP_NODE MIN_HEAP_NODE;
typedef MIN_HEAP_NODE HEAP_NODE;
typedef struct _MIN_HEAP MIN_HEAP;
typedef MIN_HEAP HEAP;

struct _MIN_HEAP_NODE {
	int key;
	int nodeA,nodeB;
};

struct _MIN_HEAP {
	HEAP_NODE *heapArray;
	int level;
	int entireSize;
	int lastIndex;

	//Method Funcionts
	HEAP *(*Create)(HEAP *, int);
	HEAP *(*Destroy)(HEAP *);
	HEAP *(*Enqueue)(HEAP *, HEAP_NODE *);
	HEAP *(*Dequeue)(HEAP *);
	HEAP *(*Peek)(HEAP *, HEAP_NODE *);
};

//Function Declarations
void HEAP_CONSTRUCTOR(HEAP *);
void HEAP_DESTRUCTOR(HEAP *);
HEAP *HEAP_METHOD_Create(HEAP *, int);
HEAP *HEAP_METHOD_Destroy(HEAP *);
HEAP *HEAP_METHOD_Enqueue(HEAP *, HEAP_NODE *);
HEAP *HEAP_METHOD_Dequeue(HEAP *);
HEAP *HEAP_METHOD_Peek(HEAP *, HEAP_NODE *);
int HEAP_PRIVATE_Swap(HEAP *, int, int);

#endif
