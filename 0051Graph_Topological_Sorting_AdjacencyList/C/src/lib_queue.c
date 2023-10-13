#include "lib_queue.h"

//Method Function Definitinos

void QUEUE_CONSTRUCTOR(QUEUE *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	(*this).begin = NULL;
	(*this).end = NULL;

	//Binding Method functions
	this->Enqueue = &QUEUE_METHOD_Enqueue;
	this->Dequeue = &QUEUE_METHOD_Dequeue;
	this->Empty = &QUEUE_METHOD_Empty;
	this->Peek = &QUEUE_METHOD_Peek;

	return ;
}

void QUEUE_DESTRUCTOR(QUEUE *this)
{
	void *dequeueBuffer = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if ((*this).Empty(this) == 1){
		return ;
	}

	while((*this).Empty(this) == 0){
		(*this).Dequeue(this, &dequeueBuffer);
	}

	return ;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (inputArg == NULL){
		DEBUG("ERROR: 'inputArg' is NULL. Only the valid address value can be enqueued.\n");
		return NULL;
	}

	//When the queue is empty.
	if ((*this).Empty(this) == 1){
		this->begin = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
		this->end = this->begin;
		this->begin->data = inputArg;
		this->begin->prev = NULL;
		this->end->prev = NULL;
		return this;
	}

	//General Case
	if (this->end->next != NULL){
		DEBUG("ERROR: 'end->next' is not NULL.\n");
		return this;
	}

	this->end->next = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
	this->end->next->prev = this->end;
	this->end->next->next = NULL;
	this->end->next->data = inputArg;
	this->end = this->end->next;

	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exceptino Handling2
	if (outputStore == NULL){
		DEBUG("ERROR: 'outputStore' is NULL.\n");
		return NULL;
	}

	//When the queue is empty currently.
	if ((*this).Empty(this) == 1){
		return NULL;
	}

	*outputStore = this->begin->data;

	//When the queue has only an element currently.
	if (this->begin == this->end){
		free(this->begin);
		this->begin = NULL;
		this->end = NULL;
		return this;
	}

	//Other general cases
	this->begin = this->begin->next;
	free(this->begin->prev);
	this->begin->prev = NULL;

	return this;
}

void *QUEUE_METHOD_Peek(QUEUE *this)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the queue is empty currently.
	if ((*this).Empty(this) == 1){
		return NULL;
	}

	return (this->begin->data);
}

int QUEUE_METHOD_Empty(QUEUE *this)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	if (this->begin == NULL && this->end == NULL){
		return 1;
	}

	return 0;
}

