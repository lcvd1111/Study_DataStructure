#ifndef __LIB_QUEUE_HEADER__
#define __LIB_QUEUE_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _QUEUE_NODE QUEUE_NODE;
typedef struct _QUEUE QUEUE;

struct _QUEUE_NODE{
	void *data;
	QUEUE_NODE *next, *prev;
};

struct _QUEUE {
	QUEUE_NODE *begin, *end;

	//Method
	QUEUE *(*Enqueue)(QUEUE *this, void *inputArg);
	QUEUE *(*Dequeue)(QUEUE *this, void **outputStore);
	void *(*Peek)(QUEUE *this);
	int (*Empty)(QUEUE *this);
};

//Method Function Declarations
void QUEUE_CONSTRUCTOR(QUEUE *this);
void QUEUE_DESTRUCTOR(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore);
void *QUEUE_METHOD_Peek(QUEUE *this);
int QUEUE_METHOD_Empty(QUEUE *this);

#endif
