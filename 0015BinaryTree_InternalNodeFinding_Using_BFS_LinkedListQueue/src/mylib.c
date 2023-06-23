#include "mylib.h"

//FUNCTION DEFINITIONS
QUEUE *CreateQueue(void)
{
	QUEUE *ret = NULL;
	ret = (QUEUE *)malloc(sizeof(QUEUE));
	ret->begin = NULL;
	ret->end = NULL;
}

QUEUE *Push(QUEUE *queueArg, BINTREE_NODE *bintreeNode)
{
	if (queueArg==NULL){
		PRINTF("ERROR: queueuArg is NULL.\n");
		return NULL;
	}
	
	if (queueArg->begin == NULL && queueArg->end == NULL){
		//When the queue is empty.
		queueArg->begin = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
		queueArg->end = queueArg->begin;
		queueArg->begin->addressData = bintreeNode;
		queueArg->begin->prev = NULL;
		queueArg->begin->next = NULL;
		
		return queueArg;
	}

	queueArg->begin->prev = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
	queueArg->begin->prev->addressData = bintreeNode;
	queueArg->begin->prev->prev = NULL;
	queueArg->begin->prev->next = queueArg->begin;
	queueArg->begin = queueArg->begin->prev;
	
	return queueArg;
}

BINTREE_NODE *Pop(QUEUE *queueArg)
{
	BINTREE_NODE *ret = NULL;

	if (queueArg==NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	if (queueArg->begin == NULL && queueArg->end == NULL){
		//When the queue is empty.
		return NULL;
	}

	ret = queueArg->end->addressData;
	
	if (queueArg->begin == queueArg->end){
		//When the queue has only one element.
		free(queueArg->end);
		queueArg->begin = NULL;
		queueArg->end = NULL;
		return ret;
	}

	queueArg->end = queueArg->end->prev;
	free(queueArg->end->next);
	queueArg->end = NULL;

	return ret;
}

QUEUE *EmptyQueue(QUEUE *queueArg)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	while(Pop(queueArg) != NULL)
		;

	return queueArg;
}

int DeleteQueue(QUEUE *queueArg)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return -1;
	}

	if (EmptyQueue(queueArg) != queueArg){
		PRINTF("ERROR: EmptyQueue( ) failed.\n");
		return -2;
	}

	if (queueArg->begin != NULL || queueArg->end != NULL){
		PRINTF("ERROR: EmptyQueue( ) didn't work well.\n");
		return -3;
	}

	return 0;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
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
		if (parent->left!=NULL || parent->right!=NULL){
			PRINTF("ERROR: parent already has a child.\n");
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
		PRINTF("ERROR: Wrong selector Value.\n");
		return NULL;
		break;
	}
	return parent;
}

int FindInternalNodes(BINTREE_NODE *root)
{
	return 0;
}

int DeleteBintree(BINTREE_NODE *root)
{
	return 0;
}
