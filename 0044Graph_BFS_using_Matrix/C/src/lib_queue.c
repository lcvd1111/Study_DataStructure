#include "common.h"
#include "lib_queue.h"

void QUEUE_CONSTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return;
	}

	(*this).queueArray = NULL;
	(*this).queueSize = -1;
	(*this).beginIndex = -1;
	(*this).endIndex = -1;

	//Method Binding.
	(*this).CreateQueue = QUEUE_METHOD_CreateQueue;
	(*this).DestroyQueue = QUEUE_METHOD_DestroyQueue;
	(*this).Enqueue = QUEUE_METHOD_Enqueue;
	(*this).Dequeue = QUEUE_METHOD_Dequeue;
	(*this).Full = QUEUE_METHOD_Full;
	(*this).Empty = QUEUE_METHOD_Empty;

	return ;
}

void QUEUE_DESTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->queueArray == NULL){
		return ;
	}

	(*this).DestroyQueue(this);
	return ;
}

QUEUE *QUEUE_METHOD_CreateQueue(QUEUE *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg<1. It must be at least 1.\n");
		return NULL;
	}

	//Exception Handling
	if ((*this).queueArray != NULL){
		return NULL;
	}

	(*this).queueSize = sizeArg;
	(*this).queueArray = (int *)malloc(sizeof(int)*sizeArg);
	memset((*this).queueArray, 0, sizeof(int)*sizeArg);
	(*this).beginIndex = -1;
	(*this).endIndex = -1;

	return this;
}

QUEUE *QUEUE_METHOD_DestroyQueue(QUEUE *this)
{
	//Exception Handling 
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->queueArray==NULL){
		return NULL;
	}

	free(this->queueArray);
	this->queueArray = NULL;
	this->queueSize = -1;
	(*this).beginIndex = -1;
	(*this).endIndex = -1;

	return this;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, int arg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return NULL;
	}

	//When the Queue is full.
	if ((*this).Full(this)){
		return NULL;
	}

	//When the Queue is empty.
	if ((*this).Empty(this)){
		(*this).beginIndex = 0;
		(*this).endIndex = 0;
		(*this).queueArray[(*this).beginIndex] = arg;
		return this;
	}

	//When the last node is in last element of the array.
	if (this->endIndex + 1 == this->queueSize){
		this->endIndex = 0;
		(*this).queueArray[(*this).endIndex] = arg;
		return this;
	}

	(*this).endIndex += 1;
	(*this).queueArray[(*this).endIndex] = arg;

	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, int *outputStore)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		DEBUG("ERROR: outptuStore is NULL.\n");
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this)){
		return NULL;
	}

	//Save the dequeued element.
	*outputStore = (*this).queueArray[(*this).beginIndex];
	(*this).queueArray[(*this).beginIndex] = 0;

	//When the queue has only an element.
	if ((*this).beginIndex == (*this).endIndex){
		(*this).beginIndex = -1;
		(*this).endIndex = -1;
		return this;
	}

	//When the beginIndex is the last element of the array.
	if ((*this).beginIndex + 1 == (*this).queueSize){
		(*this).beginIndex = 0;
		return this;
	}

	(*this).beginIndex += 1;
	return this;
}

int QUEUE_METHOD_Full(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return -2;
	}

	//When the queue is empty.
	if (this->beginIndex == -1 && this->endIndex == -1){
		return 0;
	}

	//Exception Handling3.
	if (this->beginIndex == -1 || this->endIndex == -1){
		DEBUG("ERROR: Unexpected Situation occrued.\n");
		return -3;
	}

	//When the last node of the queue is stored in the last element of the array.
	if (this->endIndex +1 == (*this).queueSize){
		if (this->beginIndex == 0){
			return 1;
		}
		return 0;
	}

	if (this->endIndex+1 == this->beginIndex){
		return 1;
	}

	return 0;
}

int QUEUE_METHOD_Empty(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return -2;
	}

	if (this->beginIndex == -1 && this->endIndex == -1){
		return 1;
	}
	
	//Exception Handling3.
	if (this->beginIndex == -1 || this->endIndex == -1){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return -3;
	}

	return 0;
}
