#include "mylib.h"

//Function Definitions
HEAP *CreateHeap(int levelArg)
{
	HEAP_NODE *test = NULL;
	test = (HEAP_NODE *)malloc(sizeof(HEAP_NODE));
	HEAP *ret = (HEAP *)malloc(sizeof(HEAP));
	if (ret == NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->level = levelArg;
	ret->size = 1;

	for (int i=0 ; i<ret->level ; i++)
		ret->size *= 2;

	ret->size -= 1;
	ret->heapArray = (HEAP_NODE *)malloc(ret->size * sizeof(HEAP_NODE));
	ret->lastIndex = -1; //set the last index to empty state.

	ret->Enqueue = &Enqueue_METHOD;
	ret->Dequeue = &Dequeue_METHOD;
	ret->ParentNode = &ParentNode_METHOD;
	ret->LeftChildNode = &LeftChildNode_METHOD;
	ret->RightChildNode = &RightChildNode_METHOD;

	return ret;
}

int RemoveHeap(HEAP *heapArg)
{
	//Exception Handling
	if (heapArg == NULL){
		PRINTF("ERROR: heapArg is NULL.\n");
		return -1;
	}

	free(heapArg->heapArray);
	free(heapArg);
	return 0;
}

HEAP *Enqueue_METHOD(HEAP *self, int keyArg, const char *dataArg)
{
	long int currentIndex = 0;
	HEAP_NODE *tempArray = NULL;

	//Exception Handling
	if (self == NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//When the heap is full
	if (self->lastIndex == self->size-1)
		return NULL;

	//Fill the last node
	tempArray = self->heapArray;
	currentIndex = self->lastIndex + 1;
	tempArray[currentIndex].key = keyArg;
	strncpy(tempArray[currentIndex].data, dataArg, STRING_LEN);
	
	//Iterative Swapping start
	while(1){
		if (currentIndex == 0)
			break;

		if (tempArray[currentIndex].key <= tempArray[(currentIndex-1)/2].key)
			break;

		SwapNode(tempArray+currentIndex , tempArray+((currentIndex-1)/2));
		currentIndex = (currentIndex-1)/2;
	}

	return self;
}

HEAP *Dequeue_METHOD(HEAP *self, HEAP_NODE *outputStore)
{
	return NULL;
}

HEAP_NODE *ParentNode_METHOD(HEAP *self, HEAP_NODE *heapArg)
{
	return NULL;
}

HEAP_NODE *LeftChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg)
{
	return NULL;
}

HEAP_NODE *RightChildNode_METHOD(HEAP *self, HEAP_NODE *heapArg)
{
	return NULL;
}

int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[64] = {0,};
	
	//Exception Handling
	if (nodeA == NULL){
		PRINTF("ERROR: nodeA is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (nodeB == NULL){
		PRINTF("ERROR: nodeB is NULL.\n");
		return -2;
	}

	nodeA->key = nodeA->key | nodeB->key;
	nodeB->key = nodeA->key | nodeB->key;
	nodeA->key = nodeA->key | nodeB->key;

	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	return 0;
}



