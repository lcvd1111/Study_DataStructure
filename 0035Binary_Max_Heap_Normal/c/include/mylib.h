#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define STRING_LEN 64

//Type Declarations and Definitions
typedef struct _BIN_MAX_HEAP_NODE {
	int key;
	char data;
} HEAP_NODE;

typedef struct _BIN_MAX_HEAP {
	HEAP_NODE *heapArray;
	unsigned int size;
	int level;
	long int lastIndex;
	HEAP *(*Enqueue)(HEAP *self, int keyArg, const char *dataArg);
	HEAP *(*Dequeue)(HEAP *self, HEAP_NODE *outputStore);
	HEAP_NODE *(*ParentNode)(HEAP *self, HEAP_NODE *heapArg);
	HEAP_NODE *(*LeftChildNode)(HEAP *self, HEAP_NODE *heapArg);
	HEAP_NODE *(*RightChildNode)(HEAP *self, HEAP_NODE *heapArg);
} HEAP;

//Function Delcarations
HEAP *CreateHeap(int depthArg);
int RemoveHeap(HEAP *);
int InitHeap_METHOD(HEAP *self, int depthArg);
HEAP *Enqueue_METHOD(HEAP *self, int keyArg, const char *dataArg);
HEAP *Dequeue_METHOD(HEAP *self, HEAP_NODE *outputStore);
HEAP_NODE *ParentNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *LeftChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *RightChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
