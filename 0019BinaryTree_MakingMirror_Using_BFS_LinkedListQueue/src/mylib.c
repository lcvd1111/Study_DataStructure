#include "mylib.h"

//Function Definitions
QUEUE *CreateQueue(void)
{
	QUEUE *ret = (QUEUE *)malloc(sizeof(QUEUE));
	ret->begin = NULL;
	ret->end = NULL;

	return ret;
}

QUEUE *Enqueue(QUEUE *queueArg, BINTREE_NODE *binArg)
{
	if(queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	//When queue is empty.
	if(queueArg->begin == NULL && queueArg->end == NULL){
		queueArg->begin = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE));
		queueArg->end = queueArg->end;
		queueArg->end->prev = NULL;
		queueArg->end->next = NULL;
		queueArg->end->addressData = binArg;
		return queueArg;
	}

	if(queueArg->end->next != NULL){
		PRINTF("ERROR: Last element's next information is not NULL.\n");
		return NULL;
	}

	queueArg->end->next = (QUEUE_NODE *)malloc(sizeof(QUEUE_NODE *));
	queueArg->end->next->addressData = binArg;
	queueArg->end->next->prev = queueArg->end;
	queueArg->end->next->next = NULL;
	queueArg->end = queueArg->end->next;

	return queueArg;
}

BINTREE_NODE *Dequeue(QUEUE *queueArg)
{
	BINTREE_NODE *ret = NULL;

	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	
	//When queue is empty.
	if(queueArg->begin == NULL && queueArg->end == NULL){
		return NULL;
	}

	ret = queueArg->begin->addressData;
	
	//When queue has only an element.
	if(queueArg->begin == queueArg->end){	
		free(queueArg->begin);
		queueArg->begin = NULL;
		queueArg->end = NULL;
		return ret;
	}

	queueArg->begin = queueArg->begin->next;
	free(queueArg->begin->prev);
	queueArg->begin->prev = NULL;

	return ret;
}

QUEUE *EmptyQueue(QUEUE *queueArg)
{
	while(Dequeue(queueArg))
		;

	if (queueArg->begin != NULL || queueArg->end != NULL){
		PRINTF("ERROR: Emptying queue didn't work well.\n");
		return NULL;
	}

	return queueArg;
}

int DeleteQueue(QUEUE *queueArg)
{
	EmptyQueue(queueArg);
	free(queueArg);

	return 0;
}

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECT selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
		case LEFT:
			if (parent->left != NULL){
				PRINTF("ERROR: parent already has a left child.\n");
				return NULL;
			}

			parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			parent->left->data = lArg;
			parent->left->left = NULL;
			parent->left->right = NULL;
			break;
		case RIGHT:
			if (parent->right != NULL){
				PRINTF("ERROR: parent already has a right child.\n");
				return NULL;
			}

			parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			parent->right->data = rArg;
			parent->right->left = NULL;
			parent->right->right = NULL;
			break;
		case BOTH:
			if (parent->left != NULL){
				PRINTF("ERROR: parent already has a left child.\n");
				return NULL;
			}

			parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			parent->left->data = lArg;
			parent->left->left = NULL;
			parent->left->right = NULL;
		
			if (parent->right != NULL){
				PRINTF("ERROR: parent already has a right child.\n");
				return NULL;
			}

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

BINTREE_NODE *MakeMirror_BFS(BINTREE_NODE *root)
{
	return root;
}

int DeleteBintree(BINTREE_NODE *root)
{
	return 0;
}
