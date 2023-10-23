#include "lib_heap.h"

void HEAP_CONSTRUCTOR(HEAP *this)
{
	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->heapArray = NULL;
	this->size = -1;
	this->lastIndex = -1;

	//Binding Method Functions
	this->Create = &HEAP_METHOD_Create;
	this->Destroy = &HEAP_METHOD_Destroy;
	this->Enqueue = &HEAP_METHOD_Enqueue;
	this->Dequeue = &HEAP_METHOD_Dequeue;
	this->Swap = &HEAP_METHOD_Swap;
	this->Empty = &HEAP_METHOD_Empty;

	return ;
}

void HEAP_DESTRUCTOR(HEAP *this)
{
	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->heapArray == NULL){
		return ;
	}

	(*this).Destroy(this);
	return ;
}

HEAP *HEAP_METHOD_Create(HEAP *this, int sizeArg)
{
	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray != NULL){
		DEBUG("ERROR: this->heapArray is not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg is smaller than 1.\n");
		return NULL;
	}

	this->heapArray = (HEAP_NODE *)calloc(sizeArg, sizeof(HEAP_NODE));
	this->size = sizeArg;
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Destroy(HEAP *this)
{
	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG("ERROR: this->heapArray is NULL.\n");
		return NULL;
	}

	free(this->heapArray);
	this->heapArray = NULL;
	this->size = -1;
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Enqueue(HEAP *this, HEAP_NODE *inputArg)
{
	HEAP_NODE *pHeapArray = NULL;
	int currentNodeIndex=0, parentNodeIndex=0;

	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG("ERROR: this->heapArray is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (inputArg == NULL){
		DEBUG("ERROR: inputArg is NULL.\n");
		return NULL;
	}

	pHeapArray = this->heapArray;

	//When the Heap is Full currently.
	if (this->lastIndex == this->size - 1){
		return NULL;
	}

	//Placing the input data to back of the current last element of the array
	this->lastIndex += 1;
	pHeapArray[this->lastIndex] = *(inputArg);

	//When heap was empty before enqueueing
	if (this->lastIndex == 0){
		return this;
	}

	//Swapping when the parent node's key value is higher than currentNode.
	currentNodeIndex = this->lastIndex;
	parentNodeIndex = (currentNodeIndex-1)/2;

	while(1){
		if (currentNodeIndex == 0){
			break;
		}

		if (pHeapArray[parentNodeIndex].key <= pHeapArray[currentNodeIndex].key){
			break;
		}

		(*this).Swap(this, parentNodeIndex, currentNodeIndex);
		currentNodeIndex = parentNodeIndex;
		parentNodeIndex = (currentNodeIndex-1)/2;
	}

	return this;
}

HEAP *HEAP_METHOD_Dequeue(HEAP *this, HEAP_NODE *outputStore)
{
	int currentNodeIndex=0, leftChildNodeIndex=0, rightChildNodeIndex=0;
	HEAP_NODE *pHeapArray = NULL;

	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG("ERROR: this->heapArray is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		DEBUG("ERROR: inputArg is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently.
	if ((*this).Empty(this) == 1){
		return NULL;
	}
	
	pHeapArray = this->heapArray;

	//Copying the root node data into outputStore
	outputStore->key = pHeapArray[0].key;
	outputStore->node_id = pHeapArray[0].node_id;
	outputStore->parent_node_id = pHeapArray[0].parent_node_id;

	//When the heap had only an element before the dequeueing.
	if (this->lastIndex == 0){
		memset((void *)(pHeapArray+0), 0, sizeof(HEAP_NODE));
		this->lastIndex = -1;
		return this;
	}

	//Moving the current last element to root node.
	memcpy((void *)(pHeapArray+0), (void *)(pHeapArray+(this->lastIndex)), sizeof(HEAP_NODE));
	this->lastIndex -= 1;

	//Swapping with child node if the child node has smaller value than current node.
	currentNodeIndex = 0;
	leftChildNodeIndex = 1;
	rightChildNodeIndex = 2;
	while(1){
		//When the current node doens't have any child.
		if (leftChildNodeIndex > (this->lastIndex)){
			break;
		}

		//When the current node has only a left child.
		if (leftChildNodeIndex == (this->lastIndex)){
			if (pHeapArray[currentNodeIndex].key > pHeapArray[leftChildNodeIndex].key){
				(*this).Swap(this, currentNodeIndex, leftChildNodeIndex);
			}
			break;
		}

		//When the current node has both left and right child.
		////When there is no need to swap.
		if (pHeapArray[currentNodeIndex].key <= pHeapArray[leftChildNodeIndex].key
			&& pHeapArray[currentNodeIndex].key <= pHeapArray[rightChildNodeIndex].key)
		{
			break;
		}

		////When there is a need to swap.
		if (pHeapArray[leftChildNodeIndex].key <= pHeapArray[rightChildNodeIndex].key){
			//Swap with left child.
			(*this).Swap(this, currentNodeIndex, leftChildNodeIndex);
			currentNodeIndex = leftChildNodeIndex;
			leftChildNodeIndex = (currentNodeIndex*2) + 1;
			rightChildNodeIndex = (currentNodeIndex*2) + 2;
			continue;
		}

		//////Swap with right child.
		(*this).Swap(this, currentNodeIndex, rightChildNodeIndex);
		currentNodeIndex = rightChildNodeIndex;
		leftChildNodeIndex = (currentNodeIndex * 2) + 1;
		rightChildNodeIndex = (currentNodeIndex * 2) + 2;
		continue;
	}

	return this;
}

HEAP *HEAP_METHOD_Swap(HEAP *this, int indexA, int indexB)
{
	HEAP_NODE buffer;

	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG("ERROR: this->heapArray is NULL.\n");
		return NULL;
	}

	buffer = (this->heapArray)[indexA];
	(this->heapArray)[indexA] = (this->heapArray)[indexB];
	(this->heapArray)[indexB] = buffer;

	return this;
}

int HEAP_METHOD_Empty(HEAP *this)
{
	//Exeption Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG("ERROR: this->heapArray is NULL.\n");
		return -2;
	}

	if (this->lastIndex == -1){
		return 1;
	}

	return 0;
}
