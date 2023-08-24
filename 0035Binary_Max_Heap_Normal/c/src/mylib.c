#include "mylib.h"

//Function Definitions
HEAP *CreateHeap(int levelArg)
{
	HEAP *ret = (HEAP *)malloc(sizeof(HEAP));
	if (ret == NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->level = levelArg;
	ret->size = 1;

	for (int i=0 ; i<level ; i++)
		ret->size *= 2;

	ret->size -= 1;
	ret->heapArray = (HEAP_NODE *)malloc(ret->size * sizeof(HEAP_NODE));
	ret->lastIndex = -1; //set the last index to empty state.

	ret->Enqueue = &Enqueue_METHOD;
	ret->Dequeue = &Dequeue_METHOD;
	ret->ParentNode = &ParentNode_METHOD;
	ret->LeftChildNode = &LeftChildNode_METHOD;
	ret->rightChildNode = &RightChildNode_METHOD;

	return ret;
}

int RemoveHeap(HEAP *heapArg);
int InitHeap_METHOD(HEAP *self, int depthArg);
HEAP *Enqueue_METHOD(HEAP *self, int keyArg, const char *dataArg);
HEAP *Dequeue_METHOD(HEAP *self, HEAP_NODE *outputStore);
HEAP_NODE *ParentNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *LeftChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
HEAP_NODE *RightChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg);
