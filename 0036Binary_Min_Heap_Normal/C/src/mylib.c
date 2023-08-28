#include "mylib.h"

//Fucntion Declarations
HEAP *CreateHeap(unsigned int levelArg)
{
	HEAP *ret = NULL;
	ret = (HEAP *)malloc(sizeof(HEAP));
	ret->level = levelArg;
	ret->size = 1;
	for (int i=0 ; i<levelArg ; i++)
		ret->size = (ret->size)*2;
	ret->size -= 1;

	ret->heapArray = (HEAP_NODE *)malloc((ret->size)*sizeof(HEAP_NODE));
	ret->lastIndex = -1;
	ret->Enqueue = &METHOD_Enqueue;
	ret->Dequeue = &METHOD_Dequeue;

	return ret;
}

int DestroyHeap(HEAP *heapArg)
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

int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[STRING_LEN] = {0,};

	//Exception Handling
	if (nodeA == NULL){
		PRINTF("ERROR: nodeA is NULL.\n");
		return -1;
	}

	if (nodeB == NULL){
		PRINTF("ERROR: nodeB is NULL.\n");
		return -2;
	}

	//Swapping the id
	nodeA->id = nodeA->id ^ nodeB->id;
	nodeB->id = nodeA->id ^ nodeB->id;
	nodeA->id = nodeA->id ^ nodeB->id;

	//Swapping the data
	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	return 0;
}

////Method Function Delcarations
HEAP *METHOD_Enqueue(HEAP *self,int idArg, const char *dataArg) 
{
	HEAP_NODE *tempArray = NULL;
	long int currentIndex = 0;
	long int parentIndex = 0;

	//Exception Handling
	if (self == NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//When the heap is full
	if (self->lastIndex == self->size - 1)
		return NULL;

	//Feeling the last node of heap with inputted arguments
	tempArray = self->heapArray;
	self->lastIndex += 1;
	tempArray[self->lastIndex].id = idArg;
	strncpy(tempArray[self->lastIndex].data, dataArg, STRING_LEN);

	//Iterative Swapping
	currentIndex = self->lastIndex;

	while(1){
		if (currentIndex == 0) //When the current node is a root node of heap.
			break;
		
		parentIndex = (currentIndex-1)/2;

		if ((tempArray[parentIndex]).id <= (tempArray[currentIndex]).id) //When the swapping is not needed anymore.
			break;

		//When the Swapping is needed.
		SwapNode(tempArray+parentIndex, tempArray+currentIndex);
		currentIndex = parentIndex;
	}
	
	return self;
}

HEAP *METHOD_Dequeue(HEAP *self, HEAP_NODE *outputStore)
{
	HEAP_NODE *tempArray = NULL;
	long int currentIndex = 0;

	//Exception Handling1
	if (self==NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}
	
	//When the heap is empty.
	if (self->lastIndex == -1)
		return NULL;

	//Copying the value from the root node to outputStorage.
	tempArray = self->heapArray;
	outputStore->id = tempArray[0].id;
	strncpy(outputStore->data, tempArray[0].data, STRING_LEN);

	//Copying the last node data to root node and deleting the last node.
	tempArray[0].id = tempArray[self->lastIndex].id;
	strncpy(tempArray[0].data, tempArray[self->lastIndex].data, STRING_LEN);
	self->lastIndex -= 1;
	if (self->lastIndex == -1) //When the heap becomes empty after deleting the last node.
		return self;

	//Iterative Swapping
	currentIndex = 0;
	while(1){
		//whent the current node has no child at all.(When the current ndoe is a leaf node.)
		if (currentIndex*2 + 1 > self->lastIndex){
			break;
		}

		//When the current node has only a left child.
		if (currentIndex*2 + 1 == self->lastIndex){
			//When the swapping is needed
			if (tempArray[currentIndex].id > tempArray[currentIndex*2 + 1].id){
				SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 1));
				break;
			}
			//When the swapping id not needed
			break; //It is okay to stop iterative swapping because the left child is currently a last node of the heap.
		}

		//When the current node has both left and right child.

		////when the swapping is not needed.
		if (tempArray[currentIndex].id <= tempArray[currentIndex*2 + 1].id
			&& tempArray[currentIndex].id <= tempArray[currentIndex*2 + 2].id){
			break;
		}

		////when the swapping is needed.
		//////When the left child is bigger smaller than right child.
		if (tempArray[currentIndex*2 + 1].id < tempArray[currentIndex*2 + 2].id){
			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 1));
			currentIndex = currentIndex*2 + 1;
			continue;
		}

		//////When the right child is equal to or smaller than the left child
		if (!(tempArray[currentIndex*2 + 1].id >= tempArray[currentIndex*2 + 2].id))//Exception Handling
		{
			PRINTF("ERROR: Unexpected situation occurs.\n");
			return NULL;
		}
		SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 2));
		currentIndex = currentIndex*2 + 2;
		continue;
	}

	return self;
}
