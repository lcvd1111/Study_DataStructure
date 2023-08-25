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
	self->lastIndex ++;

	//Iterative Swapping start
	while(1){
		if (currentIndex == 0){
			//PRINTF("Root node.\n");
			break;
		}

		if (tempArray[currentIndex].key <= tempArray[(currentIndex-1)/2].key){
			//PRINTF("Parent is bigger or equl.\n");
			break;
		}

		SwapNode(tempArray+currentIndex , tempArray+((currentIndex-1)/2));
		//printf("SWAP NODE. index: %ld -> ", currentIndex);
		currentIndex = (currentIndex-1)/2;
		//printf("%ld\n", currentIndex);
	}

	//printf("Enqueueing %d end.\n", keyArg);

	return self;
}

HEAP *Dequeue_METHOD(HEAP *self, HEAP_NODE *outputStore)
{
	HEAP_NODE *tempArray = NULL;
	long int currentIndex = 0;

	//Exception Handling
	if (self == NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		PRINTF("ERROR: noutputStore is NULL.\n");
		return NULL;
	}

	//When the Heap is empty.
	if (self->lastIndex == -1)
		return NULL;
	
	//Copying the data of root node to outputStore.
	tempArray = self->heapArray;
	outputStore->key = tempArray[0].key;
	strncpy(outputStore->data, tempArray[0].data, STRING_LEN);

	//When the Heap has only an element.
	if (self->lastIndex == 0){
		self->lastIndex -= 1;
		return self;
	}

	//Moving the last node to root node.
	tempArray[0].key = tempArray[self->lastIndex].key;
	strncpy(tempArray[0].data, tempArray[self->lastIndex].data, STRING_LEN);
	self->lastIndex -= 1;

	//Iterative Swapping
	//currentIndex is 0 currently.
	while(1)
	{
		//When the current node doesn't have any child.
		if (currentIndex*2 + 1 > self->lastIndex)
			return self;

		//When the current node only has a left child
		if (currentIndex*2 + 1 == self->lastIndex){
			if (tempArray[currentIndex].key >= tempArray[currentIndex*2 + 1].key) //No need to swap.
				return self;
			if (SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 1)) == 0){
				return self; //No need to iterate because it is a leaf node now.
			}
			else {
				PRINTF("ERROR: SwapNode() failed.\n");
				return NULL;
			}
		}

		//When the current node has both left and right two children
		//Exception Handling.
		if (!(currentIndex*2 + 1 < self->lastIndex)){
			PRINTF("ERROR: Unexpected situation occured.\n");
			return NULL;
		}

		//When the swap is not needed.
		if ((tempArray[currentIndex].key >= tempArray[currentIndex*2+1].key)
			&& (tempArray[currentIndex].key >= tempArray[currentIndex*2+2].key))
		{
			return self;
		}

		//When the Swap is needed.
		//When the key of left child is bigger than key of right child
		if (tempArray[currentIndex*2+1].key > tempArray[currentIndex*2+2].key){
			if(SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2+1))==0){
				currentIndex = currentIndex*2 + 1;
				continue;
			}
			PRINTF("ERROR: SwapNode( ) Failed.\n");
			return NULL;
		}
		
		SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2+2));
		currentIndex = currentIndex*2 + 2;
	}

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

	nodeA->key = nodeA->key ^ nodeB->key;
	nodeB->key = nodeA->key ^ nodeB->key;
	nodeA->key = nodeA->key ^ nodeB->key;

	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	return 0;
}



