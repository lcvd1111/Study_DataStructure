#include "lib_queue.h"

//Function Definitions
void QUEUE_CONSTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return ;
	}

	this->queueArray = NULL;
	this->size = -1;
	this->beginIndex = -1;
	this->endIndex = -1;

	//Binding Method Functions
	(*this).Enqueue = &QUEUE_METHOD_Enqueue;
	(*this).Dequeue = &QUEUE_METHOD_Dequeue;
	(*this).Create = &QUEUE_METHOD_Create;
	(*this).Destroy = &QUEUE_METHOD_Destroy;
	(*this).Peek = &QUEUE_METHOD_Peek;
	(*this).Empty = &QUEUE_METHOD_Empty;
	(*this).Full = &QUEUE_METHOD_Full;

	return ;
}

void QUEUE_DESTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return ;
	}

	if (this->queueArray == NULL){
		return ;
	}

	(*this).Destroy(this);

	return ;
}

QUEUE *QUEUE_METHOD_Create(QUEUE *this, int sizeArg)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray != NULL){
		DEBUG("ERROR: queueArray is not NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg is smaller than 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->queueArray = (int *)malloc(sizeof(int)*(sizeArg));
	memset(this->queueArray, 0, sizeof(int)*(sizeArg));
	this->beginIndex = -1;
	this->endIndex = -1;

	return this;
}

QUEUE *QUEUE_METHOD_Destroy(QUEUE *this)
{
	int dequeueBuffer = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return NULL;
	}

	free(this->queueArray);
	this->queueArray = NULL;
	this->size = -1;
	this->beginIndex = -1;
	this->endIndex = -1;

	return this;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, int inputArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return NULL;
	}

	//When the queue is full.
	if ((*this).Full(this) == 1){
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this) == 1){
		this->beginIndex = 0;
		this->endIndex = 0;
		(this->queueArray)[this->endIndex] = inputArg;
		return this;
	}

	//When the current most recent node of the queue is in the last index of the array.
	if (this->endIndex == (this->size) - 1){
		this->endIndex = 0;
		(this->queueArray)[this->endIndex] = inputArg;
		return this;
	}

	//When the current most recent node of the queue is not in the last index of the array.
	this->endIndex += 1;
	(this->queueArray)[this->endIndex] = inputArg;

	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, int *outputStore)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this) == 1){
		return NULL;
	}

	*outputStore = ((*this).queueArray)[(*this).beginIndex];
	((*this).queueArray)[(*this).beginIndex] = 0;
	
	//When the queue has only an element.
	if ((*this).beginIndex == (*this).endIndex){
		this->beginIndex = -1;
		this->endIndex = -1;
		return this;
	}

	//When the current oldest node of the queue is in the last index of the array.
	if ((*this).beginIndex == (*this).size - 1){
		this->beginIndex = 0;
		return this;
	}

	//When the current oldest node of the queue is not in the last index of the array.
	this->beginIndex += 1;

	return this;
}

int QUEUE_METHOD_Peek(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return -1;
	}

	//When the queue is empty.
	if ((*this).Empty(this) == 1){
		return -1;
	}

	return (((*this).queueArray)[(*this).beginIndex]);
}

int QUEUE_METHOD_Empty(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->queueArray == NULL){
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return -1;
	}

	if ((*this).beginIndex == -1 && (*this).endIndex == -1){
		return 1;
	}

	return 0;
}

int QUEUE_METHOD_Full(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR:'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->queueArray == NULL){
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return -1;
	}

	//When the most recent node of the queue is in the last index of the array.
	if (this->endIndex == this->size - 1){
		if (this->beginIndex == 0){
			return 1;
		}
		return 0;
	}

	//When the most recent node of the queue is not in the last index of the array.
	if (this->endIndex + 1 == this->beginIndex){
		return 1;
	}

	return 0;
}
