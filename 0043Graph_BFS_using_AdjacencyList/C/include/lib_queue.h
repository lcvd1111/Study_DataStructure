#ifndef __QUEUE_HEADER__
#define __QUEUE_HEADER__

#include "common.h"

//Type definitions and declarations
typedef struct _CIRCULAR_QUEUE QUEUE;

struct _CIRCULAR_QUEUE {
	void **queueArray;
	int length;
	int beginIndex;
	int endIndex;

	//Methods Declarations
	QUEUE *(*CreateQueue)(QUEUE *this, int);
	QUEUE *(*DestroyQueue)(QUEUE *this);
	int (*Full)(QUEUE *this);
	int (*Empty)(QUEUE *this);
	QUEUE *(*Enqueue)(QUEUE *this, void *);
	QUEUE *(*Dequeue)(QUEUE *this, void **);
};

//Function Declarations
void QUEUE_CONSTRUCTOR(QUEUE *);
void QUEUE_DESTRUCTOR(QUEUE *);
QUEUE *QUEUE_METHOD_CreateQueue(QUEUE *this, int);
QUEUE *QUEUE_METHOD_DestroyQueue(QUEUE *this);
int QUEUE_METHOD_Full(QUEUE *this);
int QUEUE_METHOD_Empty(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **);
#endif
