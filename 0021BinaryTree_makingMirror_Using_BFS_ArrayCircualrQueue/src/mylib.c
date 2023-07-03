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

	(queueArg->queueArray)[queueArg->end] = binArg;

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
	if (queueArg->begin == QUEUE_MAX)
		queueArg->begin = 0;
	
	return ret;
}

int DeleteQueue(QUEUE *queueArg)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return -1;
	}

	free(queueArg);
	
	return 0;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR select, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(select){
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
	}

	return parent;
}

BINTREE_NODE *MakeMirror(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	BINTREE_NODE *swapBuffer = NULL;

	QUEUE *BFS_Queue = NULL;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->left==NULL && root->right==NULL){
		return root;
	}

	current = root;
	BFS_Queue = CreateQueue();

	Enqueue(BFS_Queue, current);

	while(1){
		current = Dequeue(BFS_Queue);
		
		if (current == NULL)
			break;

		if (current->left)
			Enqueue(BFS_Queue, current->left);

		if (current->right)
			Enqueue(BFS_Queue, current->right);

		swapBuffer = current->left;
		current->left = current->right;
		current->right = swapBuffer;
	}

	DeleteQueue(BFS_Queue);
	return root;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	QUEUE *BFS_Queue = NULL;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return -1;
	}

	if (root->left==NULL && root->right==NULL){
		free(root);
	}

	current = root;
	BFS_Queue = CreateQueue();

	Enqueue(BFS_Queue, current);

	while(1){
		current = Dequeue(BFS_Queue);
		
		if (current==NULL)
			break;

		if (current->left)
			Enqueue(BFS_Queue, current->left);

		if (current->right)
			Enqueue(BFS_Queue, current->right);

		free(current);
	}
	
	DeleteQueue(BFS_Queue);
	return 0;
}
