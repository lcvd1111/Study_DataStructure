#ifndef __LIB_QUEUE_HEADER__
#define __LIB_QUEUE_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _QUEUE QUEUE;

struct _QUEUE {
	int *queueArray;
	int size;
	int beginIndex;
	int endIndex;

	//Method
	QUEUE *(*Enqueue)(QUEUE *this, int inputArg);
	QUEUE *(*Dequeue)(QUEUE *this, int *outputStore);
	QUEUE *(*Create)(QUEUE *this, int sizeArg);
	QUEUE *(*Destroy)(QUEUE *this);
	int (*Peek)(QUEUE *this);
	int (*Empty)(QUEUE *this);
	int (*Full)(QUEUE *this);
};

//Function Declarations
void QUEUE_CONSTRUCTOR(QUEUE *this);
void QUEUE_DESTRUCTOR(QUEUE *this);
QUEUE *QUEUE_METHOD_Create(QUEUE *this, int sizeArg);
QUEUE *QUEUE_METHOD_Destroy(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, int inputArg);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, int *outputStore);
int QUEUE_METHOD_Peek(QUEUE *this);
int QUEUE_METHOD_Empty(QUEUE *this);
int QUEUE_METHOD_Full(QUEUE *this);

#endif
