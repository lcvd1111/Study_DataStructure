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

	//Method Binding.
	(*this).CreateQueue = QUEUE_METHOD_CreateQueue;
	(*this).DestroyQueue = QUEUE_METHOD_DestroyQueue;
	(*this).Enqueue = QUEUE_METHOD_Enqueue;
	(*this).Dequeue = QUEUE_METHOD_Dequeue;

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

	return this;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, int arg)
{
	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, int *outputStore)
{
	return this;
}

QUEUE *QUEUE_METHOD_Full(QUEUE *this)
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

	return this;
}

QUEUE *QUEUE_METHOD_Empty(QUEUE *this)
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

	return this;
}
