#include "mylib.h"

//Function Definitions
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is null.\n");
		return NULL;
	}

	switch (selector){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if ((parent->left != NULL)||(parent->right != NULL)){
			PRINTF("ERROR: parent already has achild.\n");
			return NULL;
		}
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return NULL;
		break;
	}
	return parent;
}

QUEUE *CreateQueue(void)
{
	QUEUE *ret = NULL;
	ret = (QUEUE *)malloc(sizeof(QUEUE));
	ret->queueArray = (QUEUE_NODE*)malloc(QUEUE_MAX * sizeof(QUEUE_NODE));
	ret->begin = -1;
	ret->end = -1;
	//Intial state of circular queue is set to be empty by default.

	return ret;
}

QUEUE *Enqueue(QUEUE *queueArg, BINTREE_NODE *binArg, int level)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	if(((queueArg->begin==0)&&(queueArg->end==QUEUE_MAX-1))
		||(queueArg->begin-1==queueArg->end)){
		//When the Queue is full.
		return NULL;
	}

	if((queueArg->begin==-1)&&(queueArg->end==-1)){
		//When the Queue is empty.
		queueArg->begin = 0;
		queueArg->end = 0;
		((queueArg->queueArray)[queueArg->begin]).addressData = binArg;
		((queueArg->queueArray)[queueArg->begin]).levelData = level;
		return queueArg;
	}

	(queueArg->end)++;
	if(queueArg->end == QUEUE_MAX)
		queueArg->end = 0;
	((queueArg->queueArray)[queueArg->end]).addressData = binArg;
	((queueArg->queueArray)[queueArg->end]).levelData = level;

	return queueArg;
}

QUEUE *Dequeue(QUEUE *queueArg, QUEUE_NODE *outputStorage)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	if((queueArg->begin==-1)&&(queueArg->end==-1)){
		//When the Queue is empty.
		return NULL;
	}

	outputStorage->addressData = ((queueArg->queueArray)[queueArg->begin]).addressData;
	outputStorage->levelData = ((queueArg->queueArray)[queueArg->begin]).levelData;

	if(queueArg->begin == queueArg->end){
		//When the Queue has only an element.
		queueArg->begin = -1;
		queueArg->end = -1;
		return queueArg;
	}
	
	queueArg->begin++;
	if(queueArg->begin == QUEUE_MAX)
		queueArg->begin = 0;

	return queueArg;
}

QUEUE *EmptyQueue(QUEUE *queueArg)
{
	QUEUE_NODE temp;

	while(Dequeue(queueArg, &temp) != NULL)
		;
	
	if (queueArg->end==-1 && queueArg->begin==-1){
		return queueArg;
	}
	else {
		PRINTF("ERROR: Something wrong during the emptying the queue.\n");
		return NULL;
	}
}

int DeleteQueue(QUEUE *queueArg)
{
	if(EmptyQueue(queueArg)==NULL){
		PRINTF("ERROR. EmptyQueue( ) failed.\n");
		return -1;
	}
	
	free(queueArg->queueArray);
	free(queueArg);
	return 0;
}

int FindHeightBFS(BINTREE_NODE *root);
int DeleteBintree(BINTREE_NODE *root);
