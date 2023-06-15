#include "test.h"

int UnitTest_Deque(void)
{
	DEQUE *testDeque = NULL;
	BINTREE_NODE *testRoot = NULL;
	WRAPPED_NODE *poppedData = NULL;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;

	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);
	MakeChild(testRoot->right, BOTH, 6, 7);

	testDeque = CreateDeque();
	poppedData = (WRAPPED_NODE *)malloc(sizeof(WRAPPED_NODE));
	
	
	//Left in Right out Test (Working like a queue)
	PushLeft(testDeque, testRoot, 0);
	PushLeft(testDeque, testRoot->left, 0);
	PushLeft(testDeque, testRoot->right, 0);
	PushLeft(testDeque, testRoot->left->left, 0);
	PushLeft(testDeque, testRoot->left->right, 0);
	PushLeft(testDeque, testRoot->right->left, 0);
	PushLeft(testDeque, testRoot->right->right, 0);

	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 1){
		PRINTF("UNIT TEST FAIL.\n");
		printf("poppedData: %d\n", poppedData->bintreeNode->data);
		return -1;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}

	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 4){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 5){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 6){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 7){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if(PopRight(testDeque, poppedData) != NULL){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}


	//Left in Left out Test (Working like a stack)
	PushLeft(testDeque, testRoot, 0);
	PushLeft(testDeque, testRoot->left, 0);
	PushLeft(testDeque, testRoot->right, 0);
	PushLeft(testDeque, testRoot->left->left, 0);
	PushLeft(testDeque, testRoot->left->right, 0);
	PushLeft(testDeque, testRoot->right->left, 0);
	PushLeft(testDeque, testRoot->right->right, 0);

	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 7){
		PRINTF("UNIT TEST FAIL.\n");
		printf("poppedData: %d\n", poppedData->bintreeNode->data);
		return -2;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 6){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 5){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}

	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 4){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 1){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}
	
	if(PopLeft(testDeque, poppedData) != NULL){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}

	
	//Right in Left out Test (Working like a queue)
	PushRight(testDeque, testRoot, 0);
	PushRight(testDeque, testRoot->left, 0);
	PushRight(testDeque, testRoot->right, 0);
	PushRight(testDeque, testRoot->left->left, 0);
	PushRight(testDeque, testRoot->left->right, 0);
	PushRight(testDeque, testRoot->right->left, 0);
	PushRight(testDeque, testRoot->right->right, 0);

	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 1){
		PRINTF("UNIT TEST FAIL.\n");
		printf("poppedData: %d\n", poppedData->bintreeNode->data);
		return -3;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}

	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 4){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 5){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 6){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}
	
	PopLeft(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 7){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}
	
	if(PopLeft(testDeque, poppedData) != NULL){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}


	//Right in Right out Test (Working like a stack)
	PushRight(testDeque, testRoot, 0);
	PushRight(testDeque, testRoot->left, 0);
	PushRight(testDeque, testRoot->right, 0);
	PushRight(testDeque, testRoot->left->left, 0);
	PushRight(testDeque, testRoot->left->right, 0);
	PushRight(testDeque, testRoot->right->left, 0);
	PushRight(testDeque, testRoot->right->right, 0);

	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 7){
		PRINTF("UNIT TEST FAIL.\n");
		printf("poppedData: %d\n", poppedData->bintreeNode->data);
		return -4;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 6){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 5){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}

	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 4){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}
	
	PopRight(testDeque, poppedData);
	if(poppedData->bintreeNode->data != 1){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}
	
	if(PopRight(testDeque, poppedData) != NULL){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}


	free(poppedData);
	if(DeleteDeque(testDeque)){
		PRINTF("UNIT TEST FAIL.\n");
		return -5;
	}

	return 0;
}

int UnitTest_FindHeightBFS(void)
{
	int ret = 0;

	return ret;
}
