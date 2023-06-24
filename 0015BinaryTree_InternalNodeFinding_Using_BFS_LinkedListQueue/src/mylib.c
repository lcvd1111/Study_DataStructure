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

QUEUE *Pop(QUEUE *queueArg, QUEUE_NODE *output)
{
	if (queueArg==NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	if (queueArg->begin == NULL && queueArg->end == NULL){
		//When the queue is empty.
		return NULL;
	}

	output->addressData = queueArg->end->addressData;
	
	if (queueArg->begin == queueArg->end){
		//When the queue has only one element.
		free(queueArg->end);
		queueArg->begin = NULL;
		queueArg->end = NULL;
		return queueArg;
	}

	queueArg->end = queueArg->end->prev;
	free(queueArg->end->next);
	queueArg->end->next = NULL;

	return queueArg;
}

QUEUE *EmptyQueue(QUEUE *queueArg)
{
	QUEUE_NODE temp;

	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	while(Pop(queueArg, &temp) != NULL)
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

int CheckExternalNode(BINTREE_NODE *bintree_node)
{
	if (bintree_node == NULL){
		PRINTF("ERROR: Bintree Node is NULL.\n");
		return -1;
	}

	if (bintree_node->left == NULL && bintree_node->right == NULL)
		return 1;

	return 0;
}


int FindInternalNodes(BINTREE_NODE *root)
{
	int ret = 0;
	QUEUE *myQueue = NULL;
	QUEUE_NODE outputData;
	BINTREE_NODE *current = NULL;

	myQueue = CreateQueue();

	if (root == NULL){
		return ret;
	}

	if (CheckExternalNode(root)){
		return ret;
	}

	Push(myQueue, root);

	while(1){
		if (Pop(myQueue, &outputData) == NULL)
			return ret;

		current = outputData.addressData;

		if (CheckExternalNode(current))
			continue;
		
		ret++;

		if ((current->left)){
			Push(myQueue, current->left);
		}

		if ((current->right)){
			Push(myQueue, current->right);
		}
	}

	DeleteQueue(myQueue);

	return ret;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	QUEUE *BFSQueue = NULL;
	QUEUE *resultQueue = NULL;
	QUEUE_NODE outputData;

	if (root==NULL){
		return 0;
	}

	if (CheckExternalNode(root)){
		free(root);
		return 0;
	}

	BFSQueue = CreateQueue();
	resultQueue = CreateQueue();

	Push(BFSQueue, root);

	while (1){
		if (!Pop(BFSQueue, &outputData))
			break;

		current = outputData.addressData;

		Push(resultQueue, current);

		if (!(current->left))
			Push(BFSQueue, current->left);

		if (!(current->right))
			Push(BFSQueue, current->right);
	}

	while(Pop(resultQueue, &outputData))
		free(outputData.addressData);

	DeleteQueue(BFSQueue);
	DeleteQueue(resultQueue);

	return 0;
}
