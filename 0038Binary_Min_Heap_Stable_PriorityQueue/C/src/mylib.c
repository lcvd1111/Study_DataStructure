#include "mylib.h"

HEAP *MallocHeap(int levelArg)
{
	HEAP *ret = NULL;

	//Exception Handling
	if (levelArg<1){
		DEBUG("ERROR: levelArg is smaller than 1.\n");
		return NULL;
	}

	ret = (HEAP *)malloc(sizeof(HEAP));

	//Exception Handling2
	if (ret == NULL){
		DEBUG("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->level = levelArg;
	ret->size = 1;

	for (int i=0 ; i<levelArg ; i++){
		ret->size = 2*(ret->size);
	}

	ret->size -= 1;

	ret->lastIndex = -1;
	ret->lastEnqOrder = 0;

	ret->heapArray = (HEAP_NODE *)malloc(sizeof(HEAP_NODE)*(ret->size));

	ret->Enqueue = &METHOD_Enqueue;
	ret->Dequeue_P = &METHOD_Dequeue_P;

	return ret;
}

int FreeHeap(HEAP *heapArg)
{
	//Exception Handling
	if (heapArg == NULL){
		DEBUG("ERROR: heapArg is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (heapArg->heapArray == NULL){
		DEBUG("ERROR: heapArg->heapArray is NULL.\n");
		return -1;
	}

	free(heapArg->heapArray);
	free(heapArg);

	return 0;
}

HEAP *Constructor_Heap(HEAP *heapArg, int levelArg)
{
	//Exception Handling
	if (heapArg == NULL){
		DEBUG("ERROR: heapArg is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (levelArg<1){
		DEBUG("levelArg is smaller than 1\n");
		return NULL;
	}

	HEAP *tmp = MallocHeap(levelArg);
	if (tmp == NULL){
		DEBUG("ERROR: CreatHeap_Pointer( ) failed.\n");
		return NULL;
	}

	heapArg->heapArray = tmp->heapArray;
	heapArg->level = tmp->level;
	heapArg->lastIndex = tmp->lastIndex;
	heapArg->lastEnqOrder = tmp->lastEnqOrder;
	heapArg->Enqueue = tmp->Enqueue;
	heapArg->Dequeue_P = tmp->Dequeue_P;
	free(tmp);

	return heapArg;
}

HEAP *Destructor_Heap(HEAP *heapArg)
{
	//Execption Handling
	if (heapArg == NULL){
		DEBUG("ERROR: heapArg is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (heapArg->heapArray == NULL){
		DEBUG("ERROR: heapArg->heapArray is NULL.\n");
		return NULL;
	}

	free(heapArg->heapArray);

	return heapArg;
}

HEAP *METHOD_Enqueue(HEAP *self, int idArg, const char *dataArg)
{
	long int currentIndex = 0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->heapArray == NULL){
		DEBUG("ERROR: self->heapArray is NULL.\n");
		return NULL;
	}

	//When the heap is full currently.
	if (self->lastIndex+1 == self->size){
		return NULL;
	}

	//Filling the last node with inputted data
	self->lastIndex += 1;
	(self->heapArray)[self->lastIndex].id = idArg;
	strncpy((self->heapArray)[self->lastIndex].data, dataArg, STRING_LEN);
	self->heapArray[self->lastIndex].enqOrder = self->lastEnqOrder;
	self->lastEnqOrder += 1;

	//Iterative Swapping
	currentIndex = self->lastIndex;

	while(1){
		//When the current Node is a root node
		if (currentIndex == 0)
			return self;

		//When the Swapping is not needed1: parent of current node has lower id value than current node.
		if (self->heapArray[currentIndex].id > self->heapArray[(currentIndex-1)/2].id)
			return self;

		//When the Swapping is not needed1: parent of current node has equivalent id value to current node and enqorder is lower. 
		if (self->heapArray[currentIndex].id == self->heapArray[(currentIndex-1)/2].id
			&& self->heapArray[currentIndex].enqOrder > self->heapArray[(currentIndex-1)/2].enqOrder){
			return self;
		}

		//When the Swapping is needed.
		if (SwapNode(self->heapArray + currentIndex, self->heapArray + (currentIndex-1)/2)){
			DEBUG("ERROR: SwapNode( ) failed.\n");
			return NULL;
		}

		currentIndex = (currentIndex-1)/2;
		continue;
	}

	//Exception Handling
	DEBUG("ERROR: Unexpected Situation occured.\n");

	return self;
}

HEAP *METHOD_Dequeue_P(HEAP *self, HEAP_NODE *outputStore)
{
	HEAP_NODE *tempArray = NULL;
	long int currentIndex = 0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->heapArray == NULL){
		DEBUG("ERROR: self->heapArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the heap is empty.
	if (self->lastIndex == -1){
		return NULL;
	}

	//Filling the outputStorage with the root node's value
	tempArray = self->heapArray;
	outputStore->id = tempArray[0].id;
	strncpy(outputStore->data, tempArray[0].data, STRING_LEN);
	outputStore->enqOrder = tempArray[0].enqOrder;

	//When the heap becomes empty after the dequeueing
	if (self->lastIndex == 0){
		self->lastIndex = -1;
		return self;
	}

	//Copying the last node's data into root node.
	tempArray[0].id = tempArray[self->lastIndex].id;
	strncpy(tempArray[0].data, tempArray[self->lastIndex].data, STRING_LEN);
	tempArray[0].enqOrder = tempArray[self->lastIndex].enqOrder;
	self->lastIndex -= 1;

	//Iterative Swapping
	//currentIndex is 0 currently.
	while(1){
	}

	return self;
}


int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[STRING_LEN] = {0,};

	//Exception Handling1
	if (nodeA == NULL){
		DEBUG("ERROR: nodeA is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (nodeB == NULL){
		DEBUG("ERROR: nodeB is NULL.\n");
		return -2;
	}

	//Swapping the id value using XOR
	nodeA->id = (nodeA->id) ^ (nodeB->id);
	nodeB->id = (nodeA->id) ^ (nodeB->id);
	nodeA->id = (nodeA->id) ^ (nodeB->id);

	//Swapping the data value
	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	//Swapping the enqOrder value using XOR
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeB->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);

	return 0;
}
