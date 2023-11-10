#include "lib_heap.h"

//Function Definitions
void HEAP_CONSTRUCTOR(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return;
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

	return ;
}

void HEAP_DESTRUCTOR(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return;
	}

	if (this->heapArray != NULL){
		(*this).Destroy(this);
		return ;
	}

	return ;
}

HEAP *HEAP_METHOD_Create(HEAP *this, int levelArg)
{
	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray != NULL){
		PRINTF_ERROR("ERROR: The heap already exists currently.\n");
		return NULL;
	}

	//Exception Handling
	if (levelArg < 1){
		PRINTF_ERROR("ERROR: levelArg is smaller than 1.\n");
		return NULL;
	}

	this->level = levelArg;
	this->entireSize = 1;

	for (int i=0 ; i<levelArg ; i++){
		this->entireSize = (this->entireSize)*2;
	}

	this->entireSize -= 1;
	this->heapArray = (HEAP_NODE *)malloc(sizeof(int)*(this->entireSize));
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Destroy(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: The heap already doesn't exist currently.\n");
		return NULL;
	}

	free(this->heapArray);
	this->heapArray = NULL;
	this->level = 0;
	this->entireSize = 0;
	this->lastIndex = -1;

	return NULL;
}


HEAP *HEAP_METHOD_Enqueue(HEAP *this, HEAP_NODE *inputArg)
{
	int currentIndex=0, parentIndex=0;
	HEAP_NODE *pHeapArray = NULL;

	//Excpetion Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The First arguement(='this') is NULL.\n");
		return NULL;
	}

	//Excetption Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: The heap doesn't exist currently.\n");
		return NULL;
	}

	//When the heap is full currently
	if (this->lastIndex == (this->entireSize)-1){
		return NULL;
	}

	pHeapArray = this->heapArray;
	this->lastIndex += 1;
	(this->heapArray)[this->lastIndex].key = inputArg->key;
	(this->heapArray)[this->lastIndex].nodeA = inputArg->nodeA;
	(this->heapArray)[this->lastIndex].nodeB = inputArg->nodeB;

	currentIndex = (this->lastIndex);
	while(1){
		if (currentIndex == 0){
			//When the current node is a root node.
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
	int currentIndex=0, leftChildIndex=0, rightChildIndex=0;
	HEAP_NODE *pHeapArray = NULL;

	//Excpetion Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The First arguement(='this') is NULL.\n");
		return NULL;
	}

	//Excetption Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: The heap doesn't exist currently.\n");
		return NULL;
	}

	//When the heap is empty.
	if (this->lastIndex == -1){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//When the heap becomes empty after the dequeueing.
	if (this->lastIndex == 0){
		memset(pHeapArray+0, 0, sizeof(HEAP_NODE));
		this->lastIndex -= 1;
		return this;
	}

	memcpy(pHeapArray+0, pHeapArray+(this->lastIndex), sizeof(HEAP_NODE));
	memset(pHeapArray+(this->lastIndex), 0, sizeof(HEAP_NODE));
	this->lastIndex -= 1;

	//When the heap becomes having only an element after the dequeueing.
	if (this->lastIndex == 0){
		return this;
	}

	currentIndex = 0;

	while(1){
		leftChildIndex = currentIndex*2 + 1;
		rightChildIndex = currentIndex*2 + 2;

		//When the currentNode has no child.
		if (this->lastIndex < leftChildIndex){
			break;	
		}

		//When the currentNode has only a left child.
		if (this->lastIndex == leftChildIndex){
			if (pHeapArray[currentIndex].key > pHeapArray[leftChildIndex].key){
				HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
				break;
			}
			else {
				break;
			}
		}

		//When the currentNode has both left and right child.
		if (pHeapArray[currentIndex].key <= pHeapArray[leftChildIndex].key
			&& pHeapArray[currentIndex].key <= pHeapArray[rightChildIndex].key)
		{
			//When there is no need to swap anymore.
			break;
		}

		//when there exists at least one child node that is smaller than current node.
		if (pHeapArray[leftChildIndex].key < pHeapArray[rightChildIndex].key){
			HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
			currentIndex = leftChildIndex;
			continue;
		}

		if (pHeapArray[leftChildIndex].key >= pHeapArray[rightChildIndex].key){
			HEAP_PRIVATE_Swap(this, currentIndex, rightChildIndex);
			currentIndex = rightChildIndex;
			continue;
		}

		PRINTF_ERROR("ERROR: Something Unexpected Situation Occured.\n");
	}


	return this;
}

HEAP *HEAP_METHOD_Peek(HEAP *this, HEAP_NODE *outputStore)
{
	//Excpetion Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The First arguement(='this') is NULL.\n");
		return NULL;
	}

	//Excetption Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: The heap doesn't exist currently.\n");
		return NULL;
	}

	//Exception Handling
	if (this->lastIndex == -1){
		PRINTF_ERROR("ERROR: The heap is empty currently.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	memcpy((void *)outputStore,
			(void *)((this->heapArray)+0),
			sizeof(HEAP_NODE));

	return this;
}

int HEAP_PRIVATE_Swap(HEAP *this, int indexArgX, int indexArgY)
{
	HEAP_NODE buffer;

	//Excpetion Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The First arguement(='this') is NULL.\n");
		return -1;
	}

	//Excetption Handling
	if (this->heapArray == NULL){
		PRINTF_ERROR("ERROR: The heap doesn't exist currently.\n");
		return -2;
	}

	//Exception Handling
	if (indexArgX<0 || indexArgX>(this->lastIndex)){
		PRINTF_ERROR("ERROR: indexArgX is out of a proper range.\n");
		return -3;
	}

	//Exception Handling
	if (indexArgY<0 || indexArgY>(this->lastIndex)){
		PRINTF_ERROR("ERROR: indexArgY is out of a proper range.\n");
		return -4;
	}

	memcpy(&buffer,
			this->heapArray + indexArgX,
			sizeof(HEAP_NODE));

	memcpy(this->heapArray + indexArgX,
			this->heapArray + indexArgY,
			sizeof(HEAP_NODE));

	memcpy(this->heapArray + indexArgY,
			&buffer,
			sizeof(HEAP_NODE));

	return 0;
}
