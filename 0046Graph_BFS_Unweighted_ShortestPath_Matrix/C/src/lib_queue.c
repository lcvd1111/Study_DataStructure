#include "lib_queue.h"

void QUEUE_CONSTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return;
	}

	(*this).queueArray = NULL;
	(*this).size = -1;
	(*this).beginIndex = -1;
	(*this).endIndex = -1;

	//Method Binding
	(*this).Create = &QUEUE_METHOD_Create;
	(*this).Destroy = &QUEUE_METHOD_Destroy;
	(*this).Enqueue = &QUEUE_METHOD_Enqueue;
	(*this).Dequeue = &QUEUE_METHOD_Dequeue;
	(*this).Full = &QUEUE_METHOD_Full;
	(*this).Empty = &QUEUE_METHOD_Empty;

	return ;
}

void QUEUE_DESTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return;
	}

	if (this->queueArray == NULL){
		return ;
	}

	(*this).Destroy(this);
	return ;
}

QUEUE *QUEUE_METHOD_Create(QUEUE *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->queueArray != NULL){
		DEBUG("ERROR: 'this->queueArray' is not NULL.\n");
		return NULL;
	}

	(*this).size = sizeArg;
	(*this).queueArray = (int *)malloc(sizeof(int)*sizeArg);
	for (int i=0;i<sizeArg;i++){(*this).queueArray[i]=-1;}
	(*this).beginIndex = -1;
	(*this).endIndex = -1;

	return this;
}

QUEUE *QUEUE_METHOD_Destroy(QUEUE *this)
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
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return NULL;
	}

	//When the queue is full.
	if ((*this).Full(this)){
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this)){
		(*this).beginIndex = 0;
		(*this).endIndex = 0;
		(*this).queueArray[(*this).endIndex] = inputArg;
		return this;
	}

	//When the current endIndex is the last element of the array.
	if ((*this).endIndex == (*this).size - 1){
		(*this).endIndex = 0;
		(*this).queueArray[(*this).endIndex] = inputArg;
		return this;
	}

	//When the current endIndex is not the last element of the array.
	(*this).endIndex += 1;
	(*this).queueArray[(*this).endIndex] = inputArg;

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

	//Exception Hadnling3
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this)){
		return NULL;
	}

	*outputStore = (*this).queueArray[(*this).beginIndex];
	(*this).queueArray[(*this).beginIndex] = -1;

	//When the queue has only an element.
	if ((*this).beginIndex == (*this).endIndex){
		(*this).beginIndex = -1;
		(*this).endIndex = -1;
		return this;
	}

	//When the beginIndex was the last element of the array.
	if ((*this).beginIndex == (*this).size - 1){
		(*this).beginIndex = 0;
		return this;
	}

	//When the beginIndex was not the last element of the array.
	(*this).beginIndex += 1;

	return this;
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

	//Exception Handling3
	if (this->beginIndex == -1 || this->endIndex == -1){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return -3;
	}

	return 0;
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
	if ((*this).Empty(this)){
		return 0;
	}

	//When the last node of the queue is in last element of the array.
	if ((*this).endIndex == (*this).size - 1){
		if ((*this).beginIndex == 0){
			return 1;
		}
		return 0;
	}

	//When the last node of the queue is not in last element of the array.
	if ((*this).endIndex + 1 == (*this).beginIndex){
		return 1;
	}

	return 0;
}
