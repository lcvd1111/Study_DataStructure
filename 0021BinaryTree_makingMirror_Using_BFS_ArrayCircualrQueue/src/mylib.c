#include "mylib.h"

//Function Definitions
QUEUE *CreateQueue(void)
{
	QUEUE *ret = (QUEUE *)malloc(sizeof(QUEUE));
	ret->begin = -1;
	ret->end = -1;

	return ret;
}

QUEUE *Enqueue(QUEUE *queueArg, BINTREE_NODE *binArg)
{
	if (queueArg==NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	if (binArg==NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	//When the queue is empty.
	if (queueArg->begin == -1 && queueArg->end == -1){
		queueArg->begin = 0;
		queueArg->end = 0;
		(queueArg->queueArray)[queueArg->end] = binArg;

		return queueArg;
	}

	//When the queue is full.
	if ((queueArg->end==QUEUE_MAX-1 && queueArg->begin==0) ||
		(queueArg->begin - 1 == queueArg->end)){
		PRINTF("ERROR: Queue is currently full.\n");
		return NULL;
	}

	queueArg->end += 1;
	if (queueArg->end == QUEUE_MAX)
		queueArg->end = 0;

	(queueArg->queueAddress)[queueArg->end] = binArg;

	return queueArg;
}

BINTREE_NODE *Dequeue(QUEUE *queueArg)
{
	BINTREE_NODE *ret = NULL;

	if (queueArg==NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	//When the queue is empty.
	if (queueArg->begin == -1 && queueArg->end == -1)
		return NULL;
	
	ret = (queueArg->queueArray)[queueArg->begin];

	//When the queue has only an one element.
	if (queueArg->begin == queueArg->end){
		queueArg->end = -1;
		queueArg->begin = -1;
		return ret;
	}

	queueArg->begin += 1;
	
	return ret;
}

int DeleteQueue(QUEUE *queueArg)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		reutrn -1;
	}

	free(queueArg);
	
	return 0;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR select, int lArg, int rArg)
{

	return parent;
}

BINTREE_NODE *MakeMirror(BINTREE_NODE *root)
{
	return NULL;
}

int DeleteBintree(BINTREE_NODE *root)
{
	return 0;
}
