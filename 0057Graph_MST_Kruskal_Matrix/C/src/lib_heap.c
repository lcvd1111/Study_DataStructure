#include "lib_heap.h"

//Function Definitions
void HEAP_CONSTRUCTOR(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->heapArray = NULL;
	this->level = 0;
	this->entireSize = 0;
	this->lastIndex = -1;

	//Binding Method Functions
	this->Create = &HEAP_METHOD_Create;
	this->Destroy = &HEAP_METHOD_Destroy;
	this->Enqueue = &HEAP_METHOD_Enqueue;
	this->Dequeue = &HEAP_METHOD_Dequeue;
	this->Peek = &HEAP_METHOD_Peek;
	this->Empty = &HEAP_METHOD_Empty;

	return ;
}

void HEAP_DESTRUCTOR(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->heapArray == NULL){
		return ;
	}

	(*this).Destroy(this);

	return ;
}

HEAP *HEAP_METHOD_Create(HEAP *this, int levelArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray != NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is already not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (levelArg < 1){
		PRINTF_ERROR("ERROR: levelArg < 1.\n");
		return NULL;
	}

	this->level = levelArg;
	this->entireSize = 1;
	for (int i=0 ; i<levelArg ; i++){
		(this->entireSize) = (this->entireSize)*2;
	}
	this->entireSize -= 1;
	this->lastIndex = -1;
	this->heapArray = (HEAP_NODE *)calloc(sizeof(HEAP_NODE), this->entireSize);

	return this;
}

HEAP *HEAP_METHOD_Destroy(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is already NULL.\n");
		return NULL;
	}

	free(this->heapArray);
	this->heapArray = NULL;
	this->level = 0;
	this->entireSize = 0;
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Enqueue(HEAP *this, HEAP_NODE *inputArg)
{
	int currentIndex=0, parentIndex=0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}
	
	//Exception Handling
	if (inputArg == NULL){
		PRINTF_ERROR("ERROR: 'inputArg' is NULL.\n");
		return NULL;
	}

	//When the heap is full currently.
	if (this->lastIndex == this->entireSize - 1){
		return NULL;
	}

	this->lastIndex += 1;
	memcpy((this->heapArray)+(this->lastIndex), inputArg, sizeof(HEAP_NODE));
	
	currentIndex = this->lastIndex;
	while (1){
		if (currentIndex == 0){
			break;
		}

		parentIndex = (currentIndex-1)/2;
		
		if ((this->heapArray)[parentIndex].key > (this->heapArray)[currentIndex].key)
		{
			HEAP_PRIVATE_SWAP(this, parentIndex, currentIndex);
			currentIndex = parentIndex;
			continue;
		}
		else {
			break;
		}
	}

	return this;
}

HEAP *HEAP_METHOD_Dequeue(HEAP *this)
{
	HEAP_NODE *pHeapArray = NULL;
	int currentIndex=0, leftChildIndex=0, rightChildIndex=0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently
	if ((*this).Empty(this)){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//When the heap has only an element.
	if (this->lastIndex == 0){
		memset(pHeapArray+0, 0, sizeof(HEAP_NODE));
		this->lastIndex = -1;
		return this;
	}

	//Copying the last element to root node.
	memcpy(pHeapArray+0, pHeapArray+(this->lastIndex), sizeof(HEAP_NODE));
	memset(pHeapArray+(this->lastIndex), 0, sizeof(HEAP_NODE));
	this->lastIndex -= 1;

	//Swapping the root node with smaller child node.
	currentIndex = 0;
	while(1){
		leftChildIndex = currentIndex*2 + 1;
		rightChildIndex = currentIndex*2 + 2;

		//When there is no child.
		if (leftChildIndex > this->lastIndex){
			break;
		}

		//When there exists only a left child.
		if (leftChildIndex == this->lastIndex){
			if (pHeapArray[leftChildIndex].key < pHeapArray[currentIndex].key)
			{
				HEAP_PRIVATE_SWAP(this, currentIndex, leftChildIndex);
				break;
			}
			else {
				break;
			}
		}

		//When there exists both left and right child.
		if (pHeapArray[leftChildIndex].key >= pHeapArray[currentIndex].key
			&& pHeapArray[rightChildIndex].key >= pHeapArray[currentIndex].key)
		{
			//When there is no need to swap.
			break;
		}

		//When there exists at least on smaller child node.
		if (pHeapArray[leftChildIndex].key < pHeapArray[rightChildIndex].key){
			HEAP_PRIVATE_SWAP(this, currentIndex, leftChildIndex);
			currentIndex = leftChildIndex;
			continue;
		}

		if (pHeapArray[leftChildIndex].key >= pHeapArray[rightChildIndex].key){
			HEAP_PRIVATE_SWAP(this, currentIndex, rightChildIndex);
			currentIndex = rightChildIndex;
			continue;
		}

		PRINTF_ERROR("ERROR: Unexpected situation occured.\n");
	}

	return this;
}

HEAP *HEAP_METHOD_Peek(HEAP *this, HEAP_NODE *outputStore)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}
	
	//Exception Handling
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently.
	if ((*this).Empty(this)){
		return NULL;
	}

	memcpy(outputStore, (this->heapArray) + 0, sizeof(HEAP_NODE));

	return this;
}

int HEAP_METHOD_Empty(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return -2;
	}

	if (this->lastIndex == -1){
		return 1;
	}

	return 0;
}

int HEAP_PRIVATE_SWAP(HEAP *this, int indexA, int indexB)
{
	HEAP_NODE buffer;
	HEAP_NODE *pHeapArray = this->heapArray;

	memcpy(&buffer, pHeapArray + indexA, sizeof(HEAP_NODE));
	memcpy(pHeapArray + indexA, pHeapArray + indexB, sizeof(HEAP_NODE));
	memcpy(pHeapArray + indexB, &buffer, sizeof(HEAP_NODE));

	return 0;
}
