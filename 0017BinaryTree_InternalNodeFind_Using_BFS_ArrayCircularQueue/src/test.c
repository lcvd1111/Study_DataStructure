#include "test.h"

int UnitTest_ChildMake(void)
{
	BINTREE_NODE *root = NULL;
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, LEFT_CHILD, 2, 2);
	if (root->left->data != 2 || root->right != NULL){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -1;
	}

	MakeChild(root, RIGHT_CHILD, 3, 3);
	if (root->right->data != 3){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -2;
	}

	MakeChild(root->left, BOTH_CHILD, 4, 5);
	if (root->left->left->data != 4 ||
		root->left->right->data != 5){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -3;
	}

	if(root->right->left != NULL || root->right->right != NULL){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -4;
	}

	if (DeleteBintree(root)){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -5;
	}

	return 0;
}

int UnitTest_Queue(void)
{
	BINTREE_NODE *root = NULL;
	BINTREE_NODE *output = NULL;
	QUEUE *testQueue = NULL;
	
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	testQueue = CreateQueue();

	MakeChild(root, BOTH_CHILD, 2, 3);
	MakeChild(root->left, BOTH_CHILD, 4, 5);
	MakeChild(root->right, BOTH_CHILD, 6, 7);

	if (testQueue->begin != -1 || testQueue->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (Dequeue(testQueue)){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Enqueue(testQueue, root);
	if (((testQueue->queueArray)[testQueue->end])->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Enqueue(testQueue, root->left);
	if (((testQueue->queueArray)[testQueue->end])->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	Enqueue(testQueue, root->right);
	if (((testQueue->queueArray)[testQueue->end])->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	output = Dequeue(testQueue);
	if (output->data != 1){
		PRINTF("Unit Test Failed.\n");
		PRINTF("output->data: %d\n", output->data);
		return -6;
	}

	output = Dequeue(testQueue);
	if (output->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Enqueue(testQueue, root->left->left);
	if (((testQueue->queueArray)[testQueue->end])->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	output = Dequeue(testQueue);
	if (output->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	output = Dequeue(testQueue);
	if (output->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	DeleteBintree(root);
	DeleteQueue(testQueue);
	return 0;
}

int UnitTest_BFS(void)
{
	BINTREE_NODE *root = NULL;
	QUEUE *BFS_Queue = NULL;

	BFS_Queue = CreateQueue();

	if (FindInternal_BFS(root)){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	if (FindInternal_BFS(root)){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(root, LEFT_CHILD, 1, 1);
	if (FindInternal_BFS(root) != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root, RIGHT_CHILD, 2, 2);
	if (FindInternal_BFS(root) != 1){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	MakeChild(root->left, BOTH_CHILD, 3, 4);
	if (FindInternal_BFS(root) != 2){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	MakeChild(root->right, RIGHT_CHILD, 5, 5);
	if (FindInternal_BFS(root) != 3){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	MakeChild(root->right, LEFT_CHILD, 6, 6);
	if (FindInternal_BFS(root) != 3){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	MakeChild(root->right->left, RIGHT_CHILD, 7, 7);
	if (FindInternal_BFS(root) != 4){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	return 0;
}
