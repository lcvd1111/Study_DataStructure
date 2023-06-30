#include "test.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	if (root->left->data != 2 || root->right->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	MakeChild(root->left, RIGHT, 4, 4);
	if (root->left->left != NULL || root->left->right->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(root->right, LEFT, 5, 5);
	if (root->right->left->data != 5 || root->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	DeleteBintree(root);
	return 0;
}

int UnitTest_Queue(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	QUEUE *testQueue = NULL;

	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	
	testQueue = CreateQueue();

	if (testQueue->begin != -1 || testQueue->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (Dequeue(testQueue) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Enqueue(testQueue, root);

	if ((testQueue->queueArray)[testQueue->end]->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testQueue->begin != 0 || testQueue->end != 0){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Enqueue(testQueue, root->left);

	if ((testQueue->queueArray)[testQueue->end]->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (Dequeue(testQueue)->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testQueue->begin != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	Enqueue(testQueue, root->right);

	if ((testQueue->queueArray)[testQueue->end]->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Enqueue(testQueue, root->left->left);

	if ((testQueue->queueArray)[testQueue->end]->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Enqueue(testQueue, root->left->right);

	if ((testQueue->queueArray)[testQueue->end]->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (Dequeue(testQueue)->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (Dequeue(testQueue)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (Dequeue(testQueue)->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (Dequeue(testQueue)->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (Dequeue(testQueue) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (testQueue->begin != -1 || testQueue->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}
	
	DeleteQueue(testQueue);
	DeleteBintree(root);
	return 0;
}

int UnitTest_MakeMirror(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, RIGHT, 4, 4);
	MakeChild(root->right, BOTH, 5, 6);
	MakeChild(root->right->left, BOTH, 7, 8);
	MakeChild(root->right->right, LEFT, 9, 9);

	if (MakeMirror(root) == NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (root->left->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (root->right->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (root->left->left->data != 6){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (root->left->right->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (root->right->left->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (root->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (root->left->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (root->left->left->right->data != 9){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (root->left->right->left->data != 8){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (root->left->right->right->data != 7){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}
	
	DeleteBintree(root);
	return 0;
}
