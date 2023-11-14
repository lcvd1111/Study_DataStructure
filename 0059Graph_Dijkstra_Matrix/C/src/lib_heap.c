#include "lib_heap.h"

void HEAP_CONSTRUCTOR(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->heapArray = NULL;
	this->level = 0;
	this->entireSize = 0;
	this->lastIndex = -1;

	//Binding method functions
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
		PRINTF("ERROR: 'this' is NULL.\n");
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
	if (this==NULL){
		printf("ERROR: 'this' is null.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray != NULL){
		PRINTF("ERROR: 'this->heapArray' is already not NULL.\n");
		return NULL;
	}

	//Exception Handlng
	if (levelArg < 1){
		PRINTF("ERROR: levelArg < 1.\n");
		return NULL;
	}

	this->level = levelArg;
	this->entireSize = 1;
	for (int i=0 ; i<(this->level) ; i++){
		this->entireSize = (this->entireSize) * 2;
	}
	this->entireSize -= 1;
	this->heapArray = (HEAP_NODE *)calloc(this->entireSize, sizeof(HEAP_NODE));
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Destroy(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		printf("ERROR: 'this' is null.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF("ERROR: 'this->heapArray' is already NULL.\n");
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
	HEAP_NODE *pHeapArray = NULL;

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
		PRINTF_ERROR("ERROR: 'intputArg' is NULL.\n");
		return NULL;
	}

	//When the heap is full currently.
	if (this->lastIndex == this->entireSize-1){
		return NULL;
	}

	pHeapArray = this->heapArray;
	//Copying the input data to last node of the complete binary tree.
	this->lastIndex += 1;
	memcpy(pHeapArray +(this->lastIndex), inputArg, sizeof(HEAP_NODE));

	//Swapping with child node if it is needed.
	currentIndex = this->lastIndex;
	while(1){
		if (currentIndex == 0){
			break;
		}
		parentIndex = (currentIndex-1) / 2;
		if (pHeapArray[parentIndex].key > pHeapArray[currentIndex].key){
			HEAP_PRIVATE_Swap(this, currentIndex, parentIndex);
			currentIndex = parentIndex;
			continue;
		}
		break;
	}

	return this;
}

HEAP *HEAP_METHOD_Dequeue(HEAP *this)
{
	int currentIndex=0, leftChildIndex=0, rightChildIndex=0;
	HEAP_NODE *pHeapArray = NULL;

	//Exception Handlling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handlling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently.
	if (this->lastIndex == -1){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//When the heap has only an element currently.
	if (this->lastIndex == 0 ){
		memset(pHeapArray + 0, 0, sizeof(HEAP_NODE));
		this->lastIndex = -1;
		return this;
	}

	//Copying the last node data of the complete binary tree to root node.
	memcpy(pHeapArray + 0, pHeapArray + (this->lastIndex), sizeof(HEAP_NODE));
	memset(pHeapArray + (this->lastIndex), 0, sizeof(HEAP_NODE));
	this->lastIndex -= 1;

	/*Swapping with child node if there exsists a child node
	  whose data is smaller than current node.*/
	currentIndex = 0;
	while(1){
		leftChildIndex = 2*currentIndex + 1;
		rightChildIndex = 2*currentIndex + 2;

		//When there is no any child.
		if (leftChildIndex > (this->lastIndex)){
			break;
		}

		//When there exsists only a left child.
		if (leftChildIndex == (this->lastIndex)){
			if (pHeapArray[currentIndex].key > pHeapArray[leftChildIndex].key){
				//Swapping with left child.
				HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
				break;
			}
			else {
				break;
			}
		}

		//When there exists both left and right child.
		if (pHeapArray[currentIndex].key <= pHeapArray[leftChildIndex].key
			&& pHeapArray[currentIndex].key <= pHeapArray[rightChildIndex].key)
		{
			//When there is no need to swap anymore.
			break;
		}

		//When there exists at least one child node whose value is smaller than current node.
		if (pHeapArray[leftChildIndex].key < pHeapArray[rightChildIndex].key){
			//Swapping with left Child.
			HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
			currentIndex = leftChildIndex;
			continue;
		}

		if (pHeapArray[leftChildIndex].key >= pHeapArray[rightChildIndex].key){
			//Swapping with right Child.
			HEAP_PRIVATE_Swap(this, currentIndex, rightChildIndex);
			currentIndex = rightChildIndex;
			continue;
		}

		//Exception Handling
		PRINTF_ERROR("ERROR: Unexpected Situation Occured.\n");
		break;
	}

	return this;
}

HEAP *HEAP_METHOD_Peek(HEAP *this, HEAP_NODE *outputStore)
{
	//Exception Handlling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handlling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: 'outputStore' is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently.
	if (this->lastIndex == -1){
		return NULL;
	}

	memcpy(outputStore, (this->heapArray)+0, sizeof(HEAP_NODE));

	return this;
}

int HEAP_METHOD_Empty(HEAP *this)
{
	//Exception Handlling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handlling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return -2;
	}

	if (this->lastIndex == -1){
		return 1;
	}

	return 0;
}

HEAP *HEAP_PRIVATE_Swap(HEAP *this, int indexA, int indexB)
{
	HEAP_NODE buffer;
	memcpy(&buffer, (this->heapArray) + indexA, sizeof(HEAP_NODE));
	memcpy((this->heapArray) + indexA, (this->heapArray) + indexB, sizeof(HEAP_NODE));
	memcpy((this->heapArray) + indexB, &buffer, sizeof(HEAP_NODE));

	return this;
}
