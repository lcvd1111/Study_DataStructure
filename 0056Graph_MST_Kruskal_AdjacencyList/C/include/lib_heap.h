#ifndef __LIB_HEAP_HADER__
#define __LIB_HEAP_HADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _MIN_HEAP MIN_HEAP;
typedef MIN_HEAP HEAP;

struct _MIN_HEAP {
	int *heapArray;
	int level;
	int entireSize;
	int lastIndex;

	//Method Funcionts
	HEAP *(*Create)(HEAP *, int);
	HEAP *(*Destroy)(HEAP *);
	HEAP *(*Enqueue)(HEAP *, int);
	HEAP *(*Dequeue)(HEAP *);
	int (*Peek)(HEAP *);
};

//Function Declarations
void HEAP_CONSTRUCTOR(HEAP *);
void HEAP_DESTRUCTOR(HEAP *);
HEAP *HEAP_METHOD_Create(HEAP *, int);
HEAP *HEAP_METHOD_Destroy(HEAP *);
HEAP *HEAP_METHOD_Enqueue(HEAP *, int);
HEAP *HEAP_METHOD_Dequeue(HEAP *);
int HEAP_METHOD_Peek(HEAP *);
int HEAP_PRIVATE_Swap(HEAP *, int, int);

#endif
