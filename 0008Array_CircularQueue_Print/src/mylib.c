#include "mylib.h"

//Function Definitions
QUEUE *CreateQueue(int num)
{
	QUEUE *ret = NULL;
	ret = (QUEUE *)malloc(sizeof(QUEUE));

	//Set state to 'empty state'
	ret->begin = 0;
	ret->end = -1;

	ret->length = num;

	ret->queueArray = (int *)malloc(sizeof(int)*num);

	return ret;
}

QUEUE *EnQueue(QUEUE* queueArg, int intArg)
{
	//When queue is full
	if (
		((queueArg->end == (queueArg->length)-1) && (queueArg->begin == 0))
		||
		((queueArg->end == queueArg->begin-1) && (queueArg->begin != 0))
	   )
		return NULL;

	if (queueArg->end == (queueArg->length)-1)
		queueArg->end = 0;
	else
		queueArg->end += 1;

	(queueArg->queueArray)[queueArg->end] = intArg;

	return queueArg;
}

int DeQueue(QUEUE *queueArg, int *emptyErr)
{
	int ret = 0;

	//When queue is empty
	if (queueArg->end == -1){
		*emptyErr = 1;
		return 0;
	}

	*emptyErr = 0;
	ret = (queueArg->queueArray)[queueArg->end];
	
	if (queueArg->begin == queueArg->end){
		//Setting state to 'empty state'
		queueArg->end = -1;
		queueArg->begin = 0;
		return ret;
	}

	if (queueArg->begin == queueArg->length - 1)
		queueArg->begin = 0;
	else
		queueArg->begin += 1;

	return ret;
	
}

QUEUE *CleanQueue(QUEUE *queueArg)
{
	int emptyERR = 0;

	while(emptyERR == 0)
		DeQueue(queueArg, &emptyERR);

	return queueArg;
}

int DeleteQueue(QUEUE *queueArg)
{
	CleanQueue(queueArg);
	free(queueArg);

	return 0;
}
