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
	this->heapArray = (int *)malloc(sizeof(int)*(this->entireSize));
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


HEAP *HEAP_METHOD_Enqueue(HEAP *this, int inputArg)
{
	int currentIndex=0, parentIndex=0;
	int *pHeapArray = NULL;

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
	(this->heapArray)[this->lastIndex] = inputArg;

	currentIndex = (this->lastIndex);
	while(1){
		if (currentIndex == 0){
			break;
		}

		parentIndex = (currentIndex-1)/2;
		
		if (pHeapArray[parentIndex] > pHeapArray[currentIndex]){
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
	int *pHeapArray = NULL;

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
		pHeapArray[0] = 0;
		this->lastIndex -= 1;
		return this;
	}

	pHeapArray[0] = pHeapArray[this->lastIndex];
	pHeapArray[this->lastIndex] = 0;
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
			if (pHeapArray[currentIndex] > pHeapArray[leftChildIndex]){
				HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
				break;
			}
			else {
				break;
			}
		}

		//When the currentNode has both left and right child.
		if (pHeapArray[currentIndex] <= pHeapArray[leftChildIndex]
			&& pHeapArray[currentIndex] <= pHeapArray[rightChildIndex])
		{
			//When there is no need to swap anymore.
			break;
		}

		//when there exists at least one child node that is smaller than current node.
		if (pHeapArray[leftChildIndex] < pHeapArray[rightChildIndex]){
			HEAP_PRIVATE_Swap(this, currentIndex, leftChildIndex);
			currentIndex = leftChildIndex;
			continue;
		}

		if (pHeapArray[leftChildIndex] >= pHeapArray[rightChildIndex]){
			HEAP_PRIVATE_Swap(this, currentIndex, rightChildIndex);
			currentIndex = rightChildIndex;
			continue;
		}

		PRINTF_ERROR("ERROR: Something Unexpected Situation Occured.\n");
	}


	return this;
}

int HEAP_METHOD_Peek(HEAP *this)
{
	int ret = 0;

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
	if (this->lastIndex == -1){
		PRINTF_ERROR("ERROR: The heap is empty currently.\n");
		return -3;
	}

	ret = (this->heapArray)[0];

	return ret;
}

int HEAP_PRIVATE_Swap(HEAP *this, int indexArgX, int indexArgY)
{
	int buffer = 0;

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

	buffer = (this->heapArray)[indexArgX];
	(this->heapArray)[indexArgX] = (this->heapArray)[indexArgY];
	(this->heapArray)[indexArgY] = buffer;

	return 0;
}
