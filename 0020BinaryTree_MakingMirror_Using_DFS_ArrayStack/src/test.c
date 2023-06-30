#include "test.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	MakeChild(testRoot, BOTH, 2, 3);
	if (testRoot->left->data != 2 || testRoot->right->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	MakeChild(testRoot->right, LEFT, 4, 4);
	if (testRoot->right->left->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->right->right){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(testRoot->left, RIGHT, 5, 5);
	if (testRoot->left->right->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->left->left){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	DeleteBintree(testRoot);

	return 0;
}

int UnitTest_Stack(void)
{
	BINTREE_NODE *testRoot = NULL;
	STACK *testStack = NULL;
	STACK_NODE popOutput;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;

	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);

	testStack = CreateStack();

	if (testStack->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, testRoot, TRIED_NONE);
	if (testStack->end != 0){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Push(testStack, testRoot->left, TRIED_NONE);
	if (testStack->end != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Push(testStack, testRoot->right, TRIED_NONE);
	if (testStack->end != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	Pop(testStack, &popOutput);
	if (testStack->end != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (popOutput.addressData->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Push(testStack, testRoot->left->left, TRIED_NONE);
	if (testStack->end != 2){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Push(testStack, testRoot->left->right, TRIED_NONE);
	if (testStack->end != 3){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	Pop(testStack, &popOutput);
	if (popOutput.addressData->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	Pop(testStack, &popOutput);
	if (popOutput.addressData->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	Pop(testStack, &popOutput);
	if (popOutput.addressData->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	Pop(testStack, &popOutput);
	if (popOutput.addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (Pop(testStack, &popOutput)){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (testStack->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	DeleteBintree(testRoot);
	DeleteStack(testStack);

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

	if (MakeMirror(testRoot) != testRoot){
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
		PRINTF("test->right->left->data: %d\n", testRoot->right->left->data);
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
