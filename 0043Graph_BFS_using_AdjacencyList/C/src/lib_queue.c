#include "common.h"
#include "lib_queue.h"

//Function Definitions
void QUEUE_CONSTRUCTOR(QUEUE *this)
{
	//Exception Hanlding
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return;
	}

	this->queueArray = NULL;
	this->length = -1;
	this->beginIndex = -1;
	this->endIndex = -1;

	this->CreateQueue = QUEUE_METHOD_CreateQueue;
	this->DestroyQueue = QUEUE_METHOD_DestroyQueue;
	this->Full = QUEUE_METHOD_Full;
	this->Empty = QUEUE_METHOD_Empty;
	this->Enqueue = QUEUE_METHOD_Enqueue;
	this->Dequeue = QUEUE_METHOD_Dequeue;

	return ;
}

void QUEUE_DESTRUCTOR(QUEUE *this)
{
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
	}

	if (this->queueArray == NULL)
		return ;

	(*this).DestroyQueue(this);

	return ;
}

QUEUE *QUEUE_METHOD_CreateQueue(QUEUE *this, int lenArg)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray != NULL){
		DEBUG("ERROR: this->queueArray is not NULL.\n");
		return NULL;
	}

	//Exception Handling3 
	if (lenArg<2){
		DEBUG("ERROR: lenArg < 2. lenArg must be at least 2.\n");
		return NULL;
	}

	this->length = lenArg;
	this->queueArray = (void **)malloc(sizeof(void *)*lenArg);
	this->beginIndex = -1;
	this->endIndex = -1;

	for (int i=0 ; i<lenArg ; i++){
		(this->queueArray)[i] = NULL;
	}

	return this;
}

QUEUE *QUEUE_METHOD_DestroyQueue(QUEUE *this)
{
	void *dequeueBuffer = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return NULL;
	}

	//Emptying the Queue.
	while((*this).Dequeue(this, &dequeueBuffer) != NULL){
		;
	}

	//Exception Handling
	if (this->beginIndex != -1 || this->endIndex != -1){
		DEBUG("ERROR: Unexpected situation occured.\n");
		return NULL;
	}

	//Disallocate the memory.
	free(this->queueArray);

	this->queueArray = NULL;
	this->length = -1;

	return this;
}

int QUEUE_METHOD_Full(QUEUE *this)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return -2;
	}

	//When the end node(=most recent node) of the queue is the last element of array.
	if (this->endIndex == this->length - 1){
		switch (this->beginIndex){
		case 0:
			return 1;
		default:
			return 0;
		}
	}

	//When the end node(=most recent node) of the queue is not the last element of array.
	if (this->endIndex + 1 ==this->beginIndex)
		return 1;

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
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return 02;
	}

	if (this->beginIndex == -1 && this->endIndex == -1)
		return 1;

	//Exception Handling3
	if (this->beginIndex == -1 || this->endIndex == -1){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return -3;
	}

	return 0;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->queueArray == NULL){
		DEBUG("ERROR: this->queueArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (inputArg == NULL){
		DEBUG("ERROR: inputArg is NULL. Only the valid value can be enqueued.\n");
		return NULL;
	}

	//When the Queue is Full currently.
	if (this->Full(this)){
		return NULL;
	}

	//When the Queue is empty currently.
	if (this->Empty(this)){
		this->beginIndex = 0;
		this->endIndex = 0;
		(this->queueArray)[this->endIndex] = inputArg;
		return this;
	}

	//When the end node of the queue is the last element of array.
	if (this->endIndex == this->length - 1){
		this->endIndex = 0;
		(this->queueArray)[this->endIndex] = inputArg;
		return this;
	}

	//The remaining, ordinary situations
	this->endIndex += 1;
	(this->queueArray)[this->endIndex] = inputArg;

	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL)
	{
		DEBUG("ERRO: 'outputStore' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (this->queueArray == NULL){
		DEBUG("ERROR: 'this->queueArray' is NULL.\n");
		return NULL;
	}

	//When the queue is empty currently.
	if (this->Empty(this)){
		return NULL;
	}

	*outputStore = (this->queueArray)[this->beginIndex];
	(this->queueArray)[this->beginIndex] = NULL;

	//When the queue has only an element.
	if (this->beginIndex == this->endIndex){
		this->beginIndex = -1;
		this->endIndex = -1;
		return this;
	}

	//When the begin node of the queue is the first element of an array.
	if (this->beginIndex == this->length - 1){
		this->beginIndex = 0;
		return this;
	}

	//Remaining ordinary situations
	this->beginIndex += 1;
	return this;
}

