#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE *testRoot = NULL;
	STACK *testStack = NULL;
	STACK_NODE outputStore;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	testRoot->header = NULL;
	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);
	MakeChild(testRoot->right, BOTH, 6, 7);

	testStack = CreateStack();
	Push(testStack, testRoot, TRIED_NONE);
	if(testStack->begin->addressData->data != 1 || testStack->begin != testStack->end) {
		PRINTF("UNIT TEST FAILED.\n");
		return -1;
	}

	Push(testStack, testRoot->left, TRIED_LEFT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 2) {
		PRINTF("UNIT TEST FAILED.\n");
		return -2;
	}

	Push(testStack, testRoot->right, TRIED_RIGHT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 3) {
		PRINTF("UNIT TEST FAILED.\n");
		return -3;
	}

	Push(testStack, testRoot->left->left, TRIED_LEFT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 4) {
		PRINTF("UNIT TEST FAILED.\n");
		return -4;
	}
	
	Push(testStack, testRoot->left->right, TRIED_RIGHT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 5) {
		PRINTF("UNIT TEST FAILED.\n");
		return -5;
	}
	
	Push(testStack, testRoot->right->left, TRIED_LEFT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 6) {
		PRINTF("UNIT TEST FAILED.\n");
		return -6;
	}
	
	Push(testStack, testRoot->right->right, TRIED_RIGHT);
	if(testStack->begin->addressData->data != 1 || testStack->end->addressData->data != 7) {
		PRINTF("UNIT TEST FAILED.\n");
		return -7;
	}
	
	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 7 || outputStore.lastAction != TRIED_RIGHT){
		PRINTF("UNIT TEST FAILED.\n");
		return -1;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 6 || outputStore.lastAction != TRIED_LEFT){
		PRINTF("UNIT TEST FAILED.\n");
		return -2;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 5 || outputStore.lastAction != TRIED_RIGHT){
		PRINTF("UNIT TEST FAILED.\n");
		return -3;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 4 || outputStore.lastAction != TRIED_LEFT){
		PRINTF("UNIT TEST FAILED.\n");
		return -4;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 3 || outputStore.lastAction != TRIED_RIGHT){
		PRINTF("UNIT TEST FAILED.\n");
		return -5;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 2 || outputStore.lastAction != TRIED_LEFT){
		PRINTF("UNIT TEST FAILED.\n");
		return -6;
	}

	Pop(testStack, &outputStore);
	if(outputStore.addressData->data != 1 || outputStore.lastAction != TRIED_NONE){
		PRINTF("UNIT TEST FAILED.\n");
		return -7;
	}

	if (Pop(testStack, &outputStore) != NULL){
		PRINTF("UNIT TEST FAILED.\n");
		return -8;
	}

	if (testStack->begin != NULL || testStack->end != NULL){
		PRINTF("UNIT TEST FAILED.\n");
		return -9;
	}

	if (DeleteStack(testStack) != 0){
		PRINTF("UNIT TEST FAILED.\n");
		return -10;
	}

	return 0;
}

int UnitTest_DFS(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	testRoot->header = NULL;

	if (FindInternalNodes(testRoot) != 0){
		PRINTF("UNIT TEST FAILED.\n");
		return -1;
	}
	
	MakeChild(testRoot, BOTH, 2, 3);
	if (FindInternalNodes(testRoot) != 1){
		PRINTF("UNIT TEST FAILED.\n");
		PRINTF("Ret: %d.\n", FindInternalNodes(testRoot));
		PRINTF("Ret: %d.\n", FindInternalNodes(testRoot));
		PRINTF("Ret: %d.\n", FindInternalNodes(testRoot));
		return -2;
	}

	MakeChild(testRoot->left, LEFT, 4, 4);
	if (FindInternalNodes(testRoot) != 2){
		PRINTF("UNIT TEST FAILED.\n");
		return -3;
	}


	MakeChild(testRoot->left, RIGHT, 5, 5);
	if (FindInternalNodes(testRoot) != 2){
		PRINTF("UNIT TEST FAILED.\n");
		return -3;
	}


	MakeChild(testRoot->right, BOTH, 6, 7);
	if (FindInternalNodes(testRoot) != 3){
		PRINTF("UNIT TEST FAILED.\n");
		return -3;
	}


	MakeChild(testRoot->right->left, RIGHT, 8, 8);
	if (FindInternalNodes(testRoot) != 4){
		PRINTF("UNIT TEST FAILED.\n");
		return -4;
	}


	MakeChild(testRoot->right->left, LEFT, 9, 9);
	if (FindInternalNodes(testRoot) != 4){
		PRINTF("UNIT TEST FAILED.\n");
		return -4;
	}


	MakeChild(testRoot->right->right, BOTH, 10, 11);
	if (FindInternalNodes(testRoot) != 5){
		PRINTF("UNIT TEST FAILED.\n");
		return -4;
	}

	MakeChild(testRoot->right->right->right, RIGHT, 12, 12);
	if (FindInternalNodes(testRoot) != 6){
		PRINTF("UNIT TEST FAILED.\n");
		return -5;
	}

	return 0;
}

