#ifndef __LIB_QUEUE_HEADER__
#define __LIB_QUEUE_HEADER__

//Type Definitions and Declarations
typedef struct _QUEUE QUEUE;
struct _QUEUE {
	int *queueArray;
	int queueSize;

	//Methods
	QUEUE *(*CreateQueue)(QUEUE *this, int sizeArg);
	QUEUE *(*DestroyQueue)(QUEUE *this);
	QUEUE *(*Enqueue)(QUEUE *this, int arg);
	QUEUE *(*Dequeue)(QUEUE *this, int *outputStore);
	QUEUE *(*Full)(QUEUE *this);
	QUEUE *(*Empty)(QUEUE *this);
};

//Function Declarations
void QUEUE_CONSTRUCTOR(QUEUE *);
void QUEUE_DESTRUCTOR(QUEUE *);
QUEUE *QUEUE_METHOD_CreateQueue(QUEUE *this, int sizeArg);
QUEUE *QUEUE_METHOD_DestroyQueue(QUEUE *this);
QUEUE *QUEUE_METHOD_Enqueue(QUEUE *this, int arg);
QUEUE *QUEUE_METHOD_Dequeue(QUEUE *this, int *outputStore);
QUEUE *QUEUE_METHOD_Full(QUEUE *this);
QUEUE *QUEUE_METHOD_Empty(QUEUE *this);

#endif
