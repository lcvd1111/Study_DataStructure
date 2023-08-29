#include "mylib.h"

//Function Definitions
HEAP *CreateHeap(int levelArg)
{
	HEAP *ret = NULL; 

	//Exception Handling1
	if (levelArg < 1){
		PRINTF("ERROR: levelArg is smaller than 1\n");
		return NULL;
	}

	//Exception Handling2
	if (ret==NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->level = levelArg;
	ret->size = 1;
	for (int i=0 ; i<levelArg; i++)
		ret->size = 2*(ret->size);

	ret->heapArray = (HEAP_NODE *)malloc(sizeof(HEAP_NODE) * (ret->size));
	ret->lastIndex = -1;
	ret->H_enqOrder = 0;

	//Methods assignment
	ret->Enqueue = &METHOD_Enqueue;
	ret->Dequeue_P = &METHOD_Dequeue_P;

	return ret;
}

int DestroyHeap(HEAP *heapArg)
{
	//Exception Handling
	if (heapArg == NULL){
		PRINTF("ERROR: heapArg is NULL.\n");
		return -1;
	}

	//Exception Hadling2
	if (heapArg->heapArray == NULL){
		PRINTF("ERROR: heapArg->heapArray is NULL.\n");
		return -2;
	}

	free(heapArg->heapArray);
	free(heapArg);

	return 0;
}

HEAP *METHOD_Enqueue(HEAP *self, int idArg, const char *dataArg)
{
	HEAP_NODE *tempArray = NULL;
	long int currentIndex = 0;

	//Exception Handling
	if (self == NULL){
		PRINTF("ERROR: 'self' is NULL.\n");
		return NULL;
	}

	//Exception Handling 2
	if (self->heapArray == NULL){
		PRINTF("ERROR: 'self->heapArray' is NULL.\n");
		return NULL;
	}

	//When the Heap is full currently.
	if (self->lastIndex == self->size - 1){
		return NULL;
	}

	//Filling the last node with input data.
	tempArray = self->heapArray;
	self->lastIndex += 1;
	tempArray[self->lastIndex].id = idArg;
	strncpy(tempArray[self->lastIndex].data, dataArg, STRING_LEN);
	
	//This is for making a Stable Priority queue.
	tempArray[self->lastIndex].enqOrder = self->H_enqOrder;
	self->H_enqOrder += 1;

	//When the number of nodes becomes 1 after the enqueueing.
	if (self->lastIndex == 0)
		return self;

	//Iterative Swapping Start.
	currentIndex = self->lastIndex;

	while(1){
		//When the current node is a root node
		if (currentIndex == 0)
			return self;

		//When the swapping is needed because the parent id is smamller than current node's id.
		if (tempArray[currentIndex].id > tempArray[(currentIndex-1)/2].id){
			SwapNode(tempArray+currentIndex, tempArray+((currentIndex-1)/2));
			currentIndex = ((currentIndex-1)/2);
			continue;
		}

		//When the current node's id and parent node's id is equivalent
		if (tempArray[currentIndex].id == tempArray[(currentIndex-1)/2].id){
			if (tempArray[currentIndex].enqOrder < tempArray[(currentIndex-1)/2].enqOrder){
				PRINTF("Ordering Stabilization occur.\n");
				SwapNode(tempArray+currentIndex, tempArray+(currentIndex-1)/2);
				currentIndex = (currentIndex - 1)/2;
				continue;
			}
			return self;
		}

		//When the swapping is not needed.
		////Exception Handling
		if (!(tempArray[currentIndex].id < tempArray[(currentIndex-1)/2].id)){
			PRINTF("ERROR: Unexpected situation occured.\n");
			return NULL;
		}
		return self;
	}

	//Exception Handling
	PRINTF("ERROR: Unexpected sitaution occured.\n");
	return NULL;
}

HEAP *METHOD_Dequeue_P(HEAP *self, HEAP_NODE *outputStore)
{
	long int currentIndex = 0;
	HEAP_NODE *tempArray = NULL;

	//Exception Handling1
	if (self == NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->heapArray == NULL){
		PRINTF("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the heap is empty.
	if (self->lastIndex == -1)
		return NULL;

	tempArray = self->heapArray;

	//Copying the root node's data to outputStorage.
	outputStore->id = tempArray[0].id;
	outputStore->enqOrder = 0;
	strncpy(outputStore->data, tempArray[0].data, STRING_LEN);

	//When the heap becomes empty after the dequeueing.
	if (self->lastIndex == 0){
		self->lastIndex = -1;
		self->H_enqOrder = 0; //Preventing the Exhaustion of 'Enqueueing order parameter'.
		return self;
	}

	//Copying the last node's data to root node of the heap.
	tempArray[0].id = tempArray[self->lastIndex].id;
	strncpy(tempArray[0].data, tempArray[self->lastIndex].data, STRING_LEN);
	tempArray[0].enqOrder = tempArray[self->lastIndex].enqOrder;
	self->lastIndex -= 1;

	//Iterative Swapping start. 
	////The variable 'currentIndex' is currently 0.
	while(1){
		//When the current node doesn't have any child.
		if (currentIndex*2+1 > self->lastIndex)
			return NULL;

		//When the current node only has a left child.(That left child must be a last node)
		if (currentIndex*2+1 == self->lastIndex){
			if (tempArray[currentIndex].id < tempArray[currentIndex*2+1].id){
				SwapNode(tempArray+currentIndex, tempArray+currentIndex*2+1);
				return self;
			}
			if (tempArray[currentIndex].id == tempArray[currentIndex*2+1].id
				&& tempArray[currentIndex].enqOrder > tempArray[currentIndex*2+1].enqOrder){
				SwapNode(tempArray+currentIndex, tempArray+currentIndex*2+1);
				return self;
			}
			//When the swap is not needed.
			return self;
		}

		//When the current node has both left and right children.
		////When any swap is not needed.
		if (tempArray[currentIndex].id > tempArray[currentIndex*2+1].id 
			&& tempArray[currentIndex].id > tempArray[currentIndex*2+2].id)
			return self;

		////When (current <= leftChild) or (current <= rightChild). In other words, there exists at least one child whose priority is bigger or equivalen to current node.
		/////When the leftChild's priority is bigger than the rightchild's one.
		if (tempArray[currentIndex*2+1].id > tempArray[currentIndex*2+2].id){
			if (tempArray[currentIndex].id == tempArray[currentIndex*2+1].id
				&& tempArray[currentIndex].enqOrder < tempArray[currentIndex*2+1].enqOrder)
			{	return self;	}
			SwapNode(tempArray+currentIndex, tempArray+(2*currentIndex+1));
			currentIndex = 2*currentIndex+1;
			continue;
		}

		//////When the rightChild's priority is bigger than the leftChild's one.
		if (tempArray[currentIndex*2+1].id < tempArray[currentIndex*2+2].id){ 
			if (tempArray[currentIndex].id == tempArray[currentIndex*2+2].id
				&& tempArray[currentIndex].enqOrder < tempArray[currentIndex*2+2].enqOrder)
			{	return self;	}
			SwapNode(tempArray+currentIndex, tempArray+(2*currentIndex+2));
			currentIndex = 2*currentIndex+2;
			continue;
		}

		//////When the leftChild's priority is equal to rightChild's one.
		if (tempArray[currentIndex*2+1].id != tempArray[currentIndex*2+2].id){ // Exception Handling.
			PRINTF("ERROR: Unexpected situation occured.\n");
			return NULL;
		}

		if (tempArray[currentIndex*2+1].enqOrder < tempArray[currentIndex*2+2].enqOrder){
			if (tempArray[currentIndex].id == tempArray[currentIndex*2+1].id && tempArray[currentIndex].enqOrder < tempArray[currentIndex*2+1].enqOrder){
				return self;
			}
			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2+1));
			currentIndex = currentIndex*2 + 1;
			continue;
		}
	
		if (tempArray[currentIndex*2+1].enqOrder > tempArray[currentIndex*2+2].enqOrder){
			if (tempArray[currentIndex].id == tempArray[currentIndex*2+2].id && tempArray[currentIndex].enqOrder < tempArray[currentIndex*2+2].enqOrder){
			return self;
			}
			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2+2));
			currentIndex = currentIndex*2 + 2;
			continue;
		}
	}

	PRINTF("ERROR: Unexpected situation occured.\n");
	return NULL;
}

int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuff[STRING_LEN] = {0,};

	//Exception Handling1
	if (nodeA == NULL){
		PRINTF("nodeA is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (nodeB == NULL){
		PRINTF("nodeB is NULL.\n");
		return -2;
	}

	//node id XOR wapping
	nodeA->id = (nodeA->id) ^ (nodeB->id);
	nodeB->id = (nodeA->id) ^ (nodeB->id);
	nodeA->id = (nodeA->id) ^ (nodeB->id);

	//node enqOrder XOR swapping
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeB->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);

	//node data swapping using temporal buffer
	strncpy(stringBuff, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuff, STRING_LEN);

	return 0;
}
