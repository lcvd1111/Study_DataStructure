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
	BINTREE_NODE *testRoot = NULL;

	if (LevelFindBFS(testRoot) != 0){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}

PRINTF("---DEBUG---\n");

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;

PRINTF("---DEBUG---\n");


	if (LevelFindBFS(testRoot) != 1){
		PRINTF("UNIT TEST FAIL.\n");
		return -2;
	}

PRINTF("---DEBUG---\n");


	MakeChild(testRoot, LEFT, 2, 2);
	if (LevelFindBFS(testRoot) != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -3;
	}

PRINTF("---DEBUG---\n");


	MakeChild(testRoot, RIGHT, 3, 3);
	if (LevelFindBFS(testRoot) != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -4;
	}

PRINTF("---DEBUG---\n");


	free(testRoot->left);
	testRoot->left = NULL;
	if (LevelFindBFS(testRoot) != 2){
		PRINTF("UNIT TEST FAIL.\n");
		return -5;
	}

PRINTF("---DEBUG---\n");


	MakeChild(testRoot, LEFT, 2, 2);
	MakeChild(testRoot->left, LEFT, 4, 4);
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -6;
	}

PRINTF("---DEBUG---\n");


	MakeChild(testRoot->left, RIGHT, 5, 5); 
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -7;
	}

PRINTF("---DEBUG---\n");


	free(testRoot->left->left);
	testRoot->left->left = NULL;
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -8;
	}

PRINTF("---DEBUG---\n");


	free(testRoot->left->right);
	testRoot->left->right = NULL;
	MakeChild(testRoot->right, LEFT, 6, 6);
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -9;
	}

PRINTF("---DEBUG---\n");


	MakeChild(testRoot->right, RIGHT, 7, 7);
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -10;
	}

PRINTF("---DEBUG---\n");


	free(testRoot->right->left);
	testRoot->right->left = NULL;
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -11;
	}


PRINTF("---DEBUG---\n");


	MakeChild(testRoot->right, LEFT, 8, 8);
	MakeChild(testRoot->left, BOTH, 9, 10);
	if (LevelFindBFS(testRoot) != 3){
		PRINTF("UNIT TEST FAIL.\n");
		return -12;
	}


PRINTF("---DEBUG---\n");


	MakeChild(testRoot->left->right, BOTH, 11, 12);
	MakeChild(testRoot->left->right->left, RIGHT, 13, 13);
	MakeChild(testRoot->left->right->left->right, LEFT, 14, 14);
	MakeChild(testRoot->right->right, LEFT, 15, 15);
	MakeChild(testRoot->right->right->left, BOTH, 16, 17);
	if (LevelFindBFS(testRoot) != 6){
		PRINTF("UNIT TEST FAIL.\n");
		return -13;
	}

PRINTF("---DEBUG---\n");


	DeleteBintree(testRoot);

PRINTF("---DEBUG---\n");


	return 0;
}
