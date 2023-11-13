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

	//Binding the method functions
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

	this->lastIndex = -1;
	this->level = levelArg;
	this->entireSize = 1;
	for (int i=0 ; i<levelArg ; i++){
		(this->entireSize) = 2*(this->entireSize);
	}
	this->entireSize -= 1;
	this->heapArray = (HEAP_NODE *)calloc((this->entireSize), sizeof(HEAP_NODE));

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
	HEAP_NODE *pHeapArray = NULL;
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

	//When the Heap is full currently.
	if (this->lastIndex == this->entireSize - 1){
		return NULL;
	}

	pHeapArray = this->heapArray;
	this->lastIndex += 1;
	//Copying the input data to last node of the complete binary tree.
	memcpy(pHeapArray+(this->lastIndex), inputArg, sizeof(HEAP_NODE));

	currentIndex = this->lastIndex;
	//Swapping the value with parent if needed.
	while(1){
		if (currentIndex == 0){
			//When the current node is a root node of binary tree.
			break;
		}

		parentIndex = (currentIndex-1)/2;
		if (pHeapArray[parentIndex].key > pHeapArray[currentIndex].key){
			HEAP_PRIVATE_Swap(this, currentIndex, parentIndex);
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

	//Execption Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: 'this->heapArray' is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently.
	if (this->lastIndex == -1){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//Copying the last node's data of complete binary tree to root node.
	memcpy(pHeapArray+0, pHeapArray+(this->lastIndex), sizeof(HEAP_NODE));
	this->lastIndex -= 1;

	//Swapping with child node if there exists a child node whose value is smaller than currentNode.
	currentIndex = 0;
	while(1){
		leftChildIndex = currentIndex*2 + 1;
		rightChildIndex = currentIndex*2 + 2;

		//When the current node has no child at all.
		if (this->lastIndex < leftChildIndex){
			break;
		}

		//When the current node has only a left child.
		if (this->lastIndex == leftChildIndex){
			if (pHeapArray[currentIndex].key > pHeapArray[leftChildIndex].key){
				HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
				break;
			}
			else {
				break;
			}
		}

		//When the current node has both left and right child.
		if (pHeapArray[currentIndex].key <= pHeapArray[leftChildIndex].key
			&& pHeapArray[currentIndex].key <= pHeapArray[rightChildIndex].key)
		{
			//When there is no need to swap anymore.
			break;
		}

		//When there exists at least one child node whose value is smaller than current node.
		if (pHeapArray[leftChildIndex].key < pHeapArray[rightChildIndex].key){
			//Swapping with left child.
			HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
			currentIndex = leftChildIndex;
			continue;
		}

		else if (pHeapArray[leftChildIndex].key >= pHeapArray[rightChildIndex].key){
			//Swapping with right child.
			HEAP_PRIVATE_Swap(this, currentIndex, rightChildIndex);
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
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: 'outputStore' is NULL.\n");
		return NULL;
	}

	//When the heap is empty currently
	if (this->lastIndex == -1){
		return NULL;
	}

	memcpy(outputStore, (this->heapArray)+0, sizeof(HEAP_NODE));

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
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -2;
	}

	if (this->lastIndex == -1){
		return 1;
	}
	else {
		return 0;
	}
}

HEAP *HEAP_PRIVATE_Swap(HEAP *this, int indexA, int indexB)
{
	HEAP_NODE buffer;
	memcpy(&buffer, (this->heapArray)+indexA, sizeof(HEAP_NODE));
	memcpy((this->heapArray)+indexA, (this->heapArray)+indexB, sizeof(HEAP_NODE));
	memcpy((this->heapArray)+indexB, &buffer, sizeof(HEAP_NODE));

	return this;
}
