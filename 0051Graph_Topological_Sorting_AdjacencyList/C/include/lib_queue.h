#ifndef __LIB_QUEUE_HEADER__
#define __LIB_QUEUE_HEADER__

//#include "common.h"

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
	void (*QUEUE_CONSTRUCTOR)(QUEUE *this);
	void (*QUEUE_DESTRUCTOR)(QUEUE *this);
	QUEUE *(*Enqueue)(QUEUE *this, void *inputArg);
	QUEUE *(*Dequeue)(QUEUE *this, void **outputStore);
	int (*Empty)(QUEUE *this);
	int (*Full)(QUEUE *this);
};

//Method Function Declarations
void QUEUE_METHOD_QUEUE_CONSTRUCTOR(QUEUE *this);
void QUEUE_METHOD_QUEUE_DESTRUCTOR(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore);
int QUEUE_METHOD_Empty(QUEUE *this);
int QUEUE_METHOD_Full(QUEUE *this);

#endif
