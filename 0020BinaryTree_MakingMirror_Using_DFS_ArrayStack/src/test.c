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
	BINTREE_NODE *popOutput = NULL;
	STACK *testStack = NULL;

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

	Push(testStack, testRoot);
	if (testStack->end != 0){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Push(testStack, testRoot->left);
	if (testStack->end != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Push(testStack, testRoot->right);
	if (testStack->end != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	popOutput = Pop(testStack);
	if (testStack->end != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (popOutput->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Push(testStack, testRoot->left->left);
	if (testStack->end != 2){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Push(testStack, testRoot->left->right);
	if (testStack->end != 3){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	popOutput = Pop(testStack);
	if (popOutput->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	popOutput = Pop(testStack);
	if (popOutput->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	popOutput = Pop(testStack);
	if (popOutput->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	popOutput = Pop(testStack);
	if (popOutput->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	popOutput = Pop(testStack);
	if (popOutput){
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
