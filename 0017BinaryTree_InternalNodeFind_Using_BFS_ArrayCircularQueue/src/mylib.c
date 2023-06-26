#include "mylib.h"

//Function Definitions
QUEUE *CreateQueue(void)
{
	QUEUE *ret = NULL;
	ret = (QUEUE *)malloc(sizeof(QUEUE));
	if (!ret){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->begin = -1;
	ret->end = -1;

	return ret;
}

QUEUE *Enqueue(QUEUE *queueArg, BINTREE_NODE *binArg)
{
	if (queueArg == NULL){
		PRINTF("ERROR: queueArg is NULL.\n");
		return NULL;
	}

	//When the Queue is empty.
	if (queueArg->begin == -1 && queueArg->end == -1){
		queueArg->end = 0;
		queueArg->begin = 0;
		(queueArg->queueArray)[queueArg->end] = binArg;
		return queueArg;
	}

	//When the Queue is Full.
	if (((queueArg->begin)-1==queueArg->end) || 
		(queueArg->end==QUEUE_MAX-1 && queueArg->begin==0)){
		PRINTF("ERROR: Queue is full currently.\n");
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

	//When the Queue is empty.
	if (queueArg->begin == -1 && queueArg->end == -1){
		return NULL;
	}

	ret = (queueArg->queueArray)[queueArg->begin];

	//When the Queue has only an element.
	if (queueArg->begin == queueArg->end){
		queueArg->begin = -1;
		queueArg->end = -1;
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

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
	case LEFT_CHILD:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT_CHILD:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH_CHILD:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong Selector Value.\n");
		return NULL;
		break;
	}

	return parent;
}

int CheckExternal(BINTREE_NODE *binArg)
{
	if (binArg == NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return -1;
	}

	if (binArg->left==NULL && binArg->right==NULL)
		return 1;

	return 0;
}

int FindInternal_BFS(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	QUEUE *BFS_Queue = NULL;
	int ret = 0;

	BFS_Queue = CreateQueue();

	if (root == NULL)
		return 0;

	if (CheckExternal(root))
		return 0;

	current = root;
	Enqueue(BFS_Queue, current);

	while(1){
		current = Dequeue(BFS_Queue);
		
		if (current == NULL)
			break;

		if (CheckExternal(current))
			continue;
		
		ret++;

		if (current->left)
			Enqueue(BFS_Queue, current->left);

		if (current->right)
			Enqueue(BFS_Queue, current->right);
	}

	DeleteQueue(BFS_Queue);
	return ret;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	QUEUE *BFS_Queue = NULL;
	QUEUE *result_Queue = NULL;

	if (root == NULL)
		return 0;

	if (CheckExternal(root)){
		free(root);
		return 0;
	}

	BFS_Queue = CreateQueue();
	result_Queue = CreateQueue();

	//Traversing every node.
	current = root;
	Enqueue(BFS_Queue, current);
	while(1){
		current = Dequeue(BFS_Queue);
		if (current==NULL)
			break;

		if (CheckExternal(current))
			continue;

		Enqueue(result_Queue, current);

		if (current->left)
			Enqueue(BFS_Queue, current->left);

		if (current->right)
			Enqueue(BFS_Queue, current->right);
	}


	//Freeing every node.
	while(current=Dequeue(result_Queue))
		free(current);

	DeleteQueue(BFS_Queue);
	DeleteQueue(result_Queue);

	return 0;
}
