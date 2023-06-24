#include "test.h"

int UnitTest_Queue(void)
{
	BINTREE_NODE *testRoot = NULL;
	QUEUE *testQueue = NULL;
	QUEUE_NODE outputData;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testQueue = CreateQueue();

	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;

	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);
	MakeChild(testRoot->right, BOTH, 6, 7);
	MakeChild(testRoot->left->left, RIGHT, 8, 8);

	Push(testQueue, testRoot);
	if (testQueue->begin != testQueue->end){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -1;
	}
	if (testQueue->begin == NULL){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -1;
	}

	if (testQueue->end->addressData->data != 1){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -1;
	}

	Push(testQueue, testRoot->left);
	if (testQueue->begin->addressData->data != 2){
		PRINTF("ERROR: Unit Test Failed.\n");
		PRINTF("testRoot->left->data: %d\n", testRoot->left->data);
		PRINTF("testQue->end->addressData->data: %d\n", testQueue->end->addressData->data);
		return -2;
	}

	Push(testQueue, testRoot->right);
	if (testQueue->begin->addressData->data != 3){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -3;
	}

	Push(testQueue, testRoot->left->left);
	if (testQueue->begin->addressData->data != 4){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -4;
	}

	Push(testQueue, testRoot->left->right);
	if (testQueue->begin->addressData->data != 5){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -5;
	}

	Push(testQueue, testRoot->right->left);
	if (testQueue->begin->addressData->data != 6){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -6;
	}

	Push(testQueue, testRoot->right->right);
	if (testQueue->begin->addressData->data != 7){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -7;
	}

	Push(testQueue, testRoot->left->left->right);
	if (testQueue->begin->addressData->data != 8){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -8;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 1){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -18;
	}

	Pop(testQueue, &outputData);

	if (outputData.addressData->data != 2){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -17;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 3){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -16;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 4){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -15;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 5){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -14;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 6){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -13;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 7){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -12;
	}

	Pop(testQueue, &outputData);
	if (outputData.addressData->data != 8){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -11;
	}

	if (Pop(testQueue, &outputData) != NULL){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -10;
	}

	if (testQueue->begin != NULL || testQueue->end != NULL){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -20;
	}

	if(DeleteQueue(testQueue) != 0){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -30;
	}

	if(DeleteBintree(testRoot)){
		PRINTF("ERROR: DeleteBintree Failed.\n");
		return -9;
	}
	
	return 0;
}


int UnitTest_BFS(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	if (FindInternalNodes(root) != 0){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -1;
	}

	MakeChild(root, RIGHT, 3, 3);
	if (FindInternalNodes(root) != 1){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -2;
	}
	
	MakeChild(root, LEFT, 2, 2);
	if (FindInternalNodes(root) != 1){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->left, BOTH, 4, 5);
	if (FindInternalNodes(root) != 2){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -4;
	}

	MakeChild(root->left->right, BOTH, 6, 7);
	if (FindInternalNodes(root) != 3){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -5;
	}

	MakeChild(root->left->left, LEFT, 8, 8);
	if (FindInternalNodes(root) != 4){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -6;
	}

	MakeChild(root->right, LEFT, 1, 1);
	if (FindInternalNodes(root) != 5){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -7;
	}

	MakeChild(root->right, RIGHT, 2, 2);
	if (FindInternalNodes(root) != 5){
		PRINTF("ERROR: Unit Test Failed.\n");
		return -8;
	}

	if(DeleteBintree(root)){
		PRINTF("ERROR: DeleteBintree Failed.\n");
		return -9;
	}

	return 0;
}
