#ifndef __MY_LIB_HEADER__
#define __MY_LIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64
#define PRINTF( x , ... ) printf("[%s %d]" x , __func__, __LINE__, ##__VA_ARGS__)

//Type Declarations and Definitions
typedef struct _STABLE_PQ_MAX_HEAP_NODE {
	int id;
	char data[STRING_LEN];
	unsigned int enqOrder; //Value that shows the order of being enqueued
} HEAP_NODE;

typedef struct _STABLE_PQ_MAX_HEAP HEAP;

struct _STABLE_PQ_MAX_HEAP {
	HEAP_NODE *heapArray;
	int level;
	unsigned int size;
	long int lastIndex;
	unsigned int H_enqOrder;

	//Methods
	HEAP *(*Enqueue)(HEAP *, int, const char *);
	HEAP *(*Dequeue_P)(HEAP *, HEAP_NODE *); //"P_Dequeue" means "Dequeueing with Priority"
};

//Function Declarations
HEAP *CreateHeap(int levelArg);
int DestroyHeap(HEAP *heapArg);
HEAP *METHOD_Enqueue(HEAP *self, int idArg, const char *dataArg);
HEAP *METHOD_Dequeue_P(HEAP *self, HEAP_NODE *outputStore); 
int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB);
#endif
