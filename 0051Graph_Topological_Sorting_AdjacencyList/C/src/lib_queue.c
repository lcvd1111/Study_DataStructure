#include "lib_queue.h"

//Method Function Definitinos

void QUEUE_METHOD_QUEUE_CONSTRUCTOR(QUEUE *this)
{
	if (this == NULL){

	return ;
}

void QUEUE_METHOD_QUEUE_DESTRUCTOR(QUEUE *this)
{
	return ;
}

QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg)
{
	return this;
}

QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore)
{
	return this;
}

int QUEUE_METHOD_Empty(QUEUE *this)
{
	return 0;
}

int QUEUE_METHOD_Full(QUEUE *this)
{
	return 0;
}
