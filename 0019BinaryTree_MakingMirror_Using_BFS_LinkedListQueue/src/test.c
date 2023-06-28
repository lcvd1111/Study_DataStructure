#include "test.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	MakeChild(testRoot, BOTH, 2, 3);

	if (testRoot->left->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (testRoot->right->data !=3){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(testRoot->left, RIGHT, 4, 4);

	if (testRoot->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->left->right->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->right->left != NULL || testRoot->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	MakeChild(testRoot->right, LEFT, 5, 5);

	if (testRoot->right->left->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	DeleteBintree(testRoot);
	
	return 0;
}

int UnitTest_Queue(void)
{
	BINTREE_NODE *testRoot = NULL;
	BINTREE_NODE *dequeueOutput = NULL;
	QUEUE *testQueue = NULL;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;

	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);

	testQueue = CreateQueue();
	
	if (Dequeue(testQueue)){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Enqueue(testQueue, testRoot);

	if (testQueue->begin->addressData->data != 1 || testQueue->end->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Enqueue(testQueue, testRoot->left);

	if (testQueue->begin->addressData->data != 1 || testQueue->end->addressData->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Enqueue(testQueue, testRoot->right);

	if (testQueue->begin->addressData->data != 1 || testQueue->end->addressData->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	dequeueOutput = Dequeue(testQueue);
	
	if (dequeueOutput->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testQueue->begin->addressData->data != 1 || testQueue->end->addressData->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Enqueue(testQueue, testRoot->left->left);

	if (testQueue->begin->addressData->data != 1 || testQueue->end->addressData->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	dequeueOutput = Dequeue(testQueue);
	if (dequeueOutput->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	dequeueOutput = Dequeue(testQueue);
	if (dequeueOutput->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	dequeueOutput = Dequeue(testQueue);
	if (dequeueOutput->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	dequeueOutput = Dequeue(testQueue);
	if (dequeueOutput){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (testQueue->end != NULL || testQueue->begin != NULL){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	DeleteBintree(testRoot);
	DeleteQueue(testQueue);
	return 0;
}

int UnitTest_MakeMirror(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	
	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);
	MakeChild(testRoot->right, BOTH, 6, 7);
	MakeChild(testRoot->right->left, RIGHT, 8, 8);
	MakeChild(testRoot->right->right, LEFT, 9, 9);
	MakeChild(testRoot->right->left->right, RIGHT, 10, 10);

	if (MakeMirror_BFS(testRoot) != testRoot){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (testRoot->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->left->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->right->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->left->left->data != 7){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testRoot->left->right->data != 6){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->right->left->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (testRoot->right->right->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->left->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testRoot->left->left->right->data != 9){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->left->right->left->data != 8){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (testRoot->left->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (testRoot->right->left->left != NULL || testRoot->right->left->right != NULL ||
		testRoot->right->right->left != NULL || testRoot->right->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (testRoot->left->right->left->left->data != 10){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (testRoot->left->right->left->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	DeleteBintree(testRoot);
	return 0;
}
