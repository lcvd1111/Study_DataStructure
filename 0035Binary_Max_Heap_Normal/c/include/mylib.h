#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define STRING_LEN 64

//Type Declarations and Definitions
typedef struct _BIN_MAX_HEAP_NODE {
	int key;
	char data[STRING_LEN];
} HEAP_NODE;

typedef struct _BIN_MAX_HEAP {
	HEAP_NODE *heapArray;
	unsigned int size;
	int level;
	long int lastIndex;
	struct _BIN_MAX_HEAP *(*Enqueue)
		(struct _BIN_MAX_HEAP *self, int keyArg, const char *dataArg);
	struct _BIN_MAX_HEAP *
		(*Dequeue)(struct _BIN_MAX_HEAP *self, HEAP_NODE *outputStore);
	HEAP_NODE *(*ParentNode)(struct _BIN_MAX_HEAP *self, HEAP_NODE *heapArg);
	HEAP_NODE *(*LeftChildNode)(struct _BIN_MAX_HEAP *self, HEAP_NODE *heapArg);
	HEAP_NODE *(*RightChildNode)(struct _BIN_MAX_HEAP *self, HEAP_NODE *heapArg);
} HEAP;

//Function Delcarations
HEAP *CreateHeap(int depthArg);
int RemoveHeap(HEAP *);
HEAP *Enqueue_METHOD(HEAP *self, int keyArg, const char *dataArg);
HEAP *Dequeue_METHOD(HEAP *self, HEAP_NODE *outputStore);
HEAP_NODE *ParentNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *LeftChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *RightChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
int SwapNode(HEAP_NODE *, HEAP_NODE *);

#endif
