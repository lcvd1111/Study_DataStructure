#include "mylib.h"

//Function Definitions
QUEUE *CreateQueue(uint32_t num)
{
	QUEUE *ret = NULL;

	ret = (QUEUE *)malloc(sizeof(QUEUE));
	if (ret==NULL){
		PRINTF("ERROR: malloc failed.\n");
		return NULL;
	}

	ret->begin = 0;
	ret->end = -1 ;
	ret->length = num;
	//Set to 'Empty State'

	ret->queueArray = (BINTREE_NODE **)malloc(num*sizeof(BINTREE_NODE *));

	for (int i=0 ; i<num ; i++){
		(ret->queueArray)[i] = NULL;
	}

	return ret;
}

QUEUE *Enqueue(QUEUE *queueArg, BINTREE_NODE *bintreeArg)
{
	//When queue is full
	if (
		( (queueArg->end == (queueArg->length)-1) && (queueArg->begin == 0) )
		||
		( ((queueArg->end)+1 == queueArg->begin) && (queueArg->end != -1) )
	   ){
		//PRINTF("ERROR: Queue Overflow occured.\n");
		return NULL;
	}

	if (queueArg->end == (queueArg->length - 1)){
		queueArg->end = 0;
	}
	else 
		queueArg->end += 1;

	(queueArg->queueArray)[queueArg->end] = bintreeArg;

	return queueArg;
}

BINTREE_NODE *Dequeue(QUEUE *queueArg)
{
	BINTREE_NODE *ret = NULL;

	//When queue is empty
	if ((queueArg->end == -1)&&(queueArg->begin == 0)){
		return NULL;
	}

	ret = (queueArg->queueArray)[queueArg->begin];
	queueArg->queueArray[queueArg->begin] = NULL;

	//When there is only an one single element in queue
	if (queueArg->end == queueArg->begin){
		queueArg->end = -1;
		queueArg->begin = 0;
		//Make queue array empty.
	}
	else
		queueArg->begin += 1;

	return ret;
}

QUEUE *CleanQueue(QUEUE *queueArg)
{
	while(Dequeue(queueArg) != NULL)
		;

	if (!((queueArg->begin == 0)&&(queueArg->end == -1)))
		return NULL;

	return queueArg;
}

int DeleteQueue(QUEUE *queueArg)
{
	if(CleanQueue(queueArg) != queueArg){
		PRINTF("ERROR: Cleaning Queue Error.\n");
		return -1;
	}
	free(queueArg);

	return 0;
}

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (selector){
	case NONE:
		break;
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if ((parent->left != NULL)||(parent->right != NULL)){
			PRINTF("ERROR: parent already has a child(or children).\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
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

BINTREE_NODE *LevelOrder(BINTREE_NODE *root)
{
	return root;
}

int CleanBintree(BINTREE_NODE *root)
{
	return 0;
}
