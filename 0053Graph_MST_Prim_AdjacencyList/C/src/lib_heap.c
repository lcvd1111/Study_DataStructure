#include "lib_heap.h"

//Function Definitions
void HEAP_CONSTRUCTOR(HEAP *this)
{
	this->heapArray = NULL;
	this->size = -1;
	this->lastIndex = -1;

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
	if (this->heapArray == NULL){
		return ;
	}

	(*this).Destroy(this);
	return ;
}

HEAP *HEAP_METHOD_Create(HEAP *this, int levelArg)
{
	int size = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (levelArg < 1){
		DEBUG("ERROR: 'levelArg' is smaller than 1.\n");
		return NULL;
	}

	//Exception Handling3
	if (this->heapArray != NULL){
		DEBUG("ERROR: 'heapArray' is not NULL.\n");
		return NULL;
	}

	this->size = 1;
	for (int i=0 ; i<levelArg ; i++){
		this->size = 2*(this->size);
	}
	this->size -= 1;

	this->heapArray = (HEAP_NODE *)malloc(sizeof(HEAP_NODE)*(this->size));
	for (int i=0 ; i<this->size ; i++){
		((*this).heapArray)[i].key = 0;
		((*this).heapArray)[i].data = NULL;
	}
	this->lastIndex = -1;

	return this;
}

HEAP *HEAP_METHOD_Destroy(HEAP *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (this->heapArray == NULL){
		DEBUG("ERROR: 'heapArray' is NULL.\n");
		return NULL;
	}

	free(this->heapArray);
	this->size = -1;
	this->lastIndex = -1;
	this->heapArray = NULL;

	return this;
}

HEAP *HEAP_METHOD_Enqueue(HEAP *this, HEAP_NODE *inputArg)
{
	int currentIndex=0, parentIndex=0;
	HEAP_NODE *pHeapArray = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the heap is full.
	if (this->lastIndex == this->size - 1){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//Adding the inputArg to back of the current last element of the array.
	this->lastIndex += 1;
	(pHeapArray)[this->lastIndex].key = inputArg->key;
	(pHeapArray)[this->lastIndex].data = inputArg->data;

	//Swapping with parent if the element is smaller than than the parent.
	currentIndex = this->lastIndex;
	parentIndex = (currentIndex-1)/2;
	while(1){
		if (currentIndex == 0){
			//When the inputArg is the root of the heap.
			break;
		}

		if (pHeapArray[parentIndex].key <= pHeapArray[currentIndex].key){
			//When the swapping is not needed anymore.
			break;
		}

		//Swapping with parent node.
		(this->Swap)(this, currentIndex, parentIndex);
		currentIndex = parentIndex;
		parentIndex = (currentIndex-1)/2;
	}

	return this;
}

HEAP *HEAP_METHOD_Dequeue(HEAP *this, HEAP_NODE *outputStore)
{
	HEAP_NODE *pHeapArray = NULL;
	int currentIndex=0, lChildIndex=0, rChildIndex=0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (this->heapArray == NULL){
		DEBUG("ERROR: heapArray is NULL.\n");
		return NULL;
	}

	//When the Heap is empty.
	if (this->lastIndex == -1){
		return NULL;
	}

	pHeapArray = this->heapArray;

	//Copying the root node data to outputStore
	outputStore->data = pHeapArray[0].data;
	outputStore->key = pHeapArray[0].key;

	//When the heap becomes empty after the dequeueing.
	if (this->lastIndex == 0){
		this->lastIndex = -1;
		return this;
	}

	//Moving the current last element to root node.
	pHeapArray[0] = pHeapArray[this->lastIndex];
	pHeapArray[this->lastIndex].key = 0;
	pHeapArray[this->lastIndex].data = NULL;
	this->lastIndex -= 1;

	//Swapping with child if the currentNode is bigger than child.
	currentIndex = 0;
	lChildIndex = 1;
	rChildIndex = 2;

	while(1){
		//When it has no child.
		if (lChildIndex > this->lastIndex){
			break;
		}

		//When it has only a left child.
		if (lChildIndex == this->lastIndex){
			if (pHeapArray[currentIndex].key > pHeapArray[lChildIndex].key){
				(this->Swap)(this, currentIndex, lChildIndex);
			}
			break;
		}

		//When it has both left and right child.
		////When the swapping doesn't needed.
		if (pHeapArray[currentIndex].key <= pHeapArray[lChildIndex].key
			&& pHeapArray[currentIndex].key <= pHeapArray[rChildIndex].key)
		{
			break;
		}
		
		////When the swapping is needed.
		//////Swapping with left child node.
		if (pHeapArray[lChildIndex].key <= pHeapArray[rChildIndex].key){
			(this->Swap)(this, currentIndex, lChildIndex);
			currentIndex = lChildIndex;
			lChildIndex = 2*currentIndex + 1;
			rChildIndex = 2*currentIndex + 2;
			continue;
		}

		//////Swapping with right child node.
		(this->Swap)(this, currentIndex, rChildIndex);
		currentIndex = rChildIndex;
		lChildIndex = 2*currentIndex + 1;
		rChildIndex = 2*currentIndex + 2;
	}

	return this;
}

HEAP *HEAP_METHOD_Swap(HEAP *this, int indexA, int indexB)
{
	HEAP_NODE *pHeapArray = NULL;
	HEAP_NODE buffer;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->heapArray == NULL){
		DEBUG("ERROR: heapArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (indexA>=this->size){
		DEBUG("ERROR: indexA >= size\n");
		return NULL;
	}
	
	//Exception Handling4
	if (indexB>=this->size){
		DEBUG("ERROR: indexB >= size\n");
		return NULL;
	}

	pHeapArray = this->heapArray;

	buffer = pHeapArray[indexA];
	pHeapArray[indexA] = pHeapArray[indexB];
	pHeapArray[indexB] = buffer;

	return this;
}

int HEAP_METHOD_Empty(HEAP *this)
{
	//Exception Handling
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
