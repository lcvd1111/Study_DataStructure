#ifndef __LIB_QUEUE_HEADER__
#define __LIB_QUEUE_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _QUEUE QUEUE;

struct _QUEUE {
	void **queueArray;
	int size;
	int beginIndex, endIndex;

	//Methods
	QUEUE *(*Create)(QUEUE *this, int size);
	QUEUE *(*Destroy)(QUEUE *this);
	QUEUE *(*Enqueue)(QUEUE *this, void *inputArg);
	QUEUE *(*Dequeue)(QUEUE *this, void **outputStore);
	int (*Full)(QUEUE *this);
	int (*Empty)(QUEUE *this);
};

void QUEUE_CONSTRUCTOR(QUEUE *);
void QUEUE_DESTRUCTOR(QUEUE *);
QUEUE *QUEUE_METHOD_Create(QUEUE *this, int size);
QUEUE *QUEUE_METHOD_Destroy(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, void *inputArg);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, void **outputStore);
int QUEUE_METHOD_Full(QUEUE *this);
int QUEUE_METHOD_Empty(QUEUE *this);

#endif
