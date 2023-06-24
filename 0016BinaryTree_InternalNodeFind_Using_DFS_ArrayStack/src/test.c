#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	STACK *testStack = NULL;
	STACK_NODE output;
	testStack = CreateStack();
	STACK *ret;

	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	root->header = NULL;

	MakeChild(root, BOTH, 2, 3);
	
	if (root->left->data != 2){
		PRINTF("Unit Test failed.\n");
		return -1;
	}
	
	if (root->right->data != 3){
		PRINTF("Unit Test failed.\n");
		return -2;
	}

	MakeChild(root->left, BOTH, 4, 5);
	
	if (root->left->left->data != 4){
		PRINTF("Unit Test failed.\n");
		return -3;
	}
	
	if (root->left->right->data != 5){
		PRINTF("Unit Test failed.\n");
		return -4;
	}
	
	MakeChild(root->right, BOTH, 6, 7);

	if (root->right->left->data != 6){
		PRINTF("Unit Test failed.\n");
		return -5;
	}
	
	if (root->right->right->data != 7){
		PRINTF("Unit Test failed.\n");
		return -6;
	}

	if (Pop(testStack, &output) != 1){
		PRINTF("Unit Test failed.\n");
		PRINTF("testStack->end: %d\n", testStack->end);
		return -7;
	}

	Push(testStack, root, TRIED_LEFT);
	Push(testStack, root->left, TRIED_RIGHT);
	Push(testStack, root->right, TRIED_NONE);
	Push(testStack, root->left->left, TRIED_LEFT);
	Push(testStack, root->left->right, TRIED_RIGHT);
	Push(testStack, root->right->left, TRIED_NONE);
	Push(testStack, root->right->right, TRIED_LEFT);

	Pop(testStack, &output);
	if (output.addressData->data != 7 || output.triedAction != TRIED_LEFT){
		PRINTF("Unit Test failed.\n");
		return -8;
	}

	Pop(testStack, &output);
	if (output.addressData->data != 6 || output.triedAction != TRIED_NONE){
		PRINTF("Unit Test failed.\n");
		return -9;
	}


	Pop(testStack, &output);
	if (output.addressData->data != 5 || output.triedAction != TRIED_RIGHT){
		PRINTF("Unit Test failed.\n");
		return -10;
	}


	Pop(testStack, &output);
	if (output.addressData->data != 4 || output.triedAction != TRIED_LEFT){
		PRINTF("Unit Test failed.\n");
		return -11;
	}


	Pop(testStack, &output);
	if (output.addressData->data != 3 || output.triedAction != TRIED_NONE){
		PRINTF("Unit Test failed.\n");
		return -12;
	}


	Pop(testStack, &output);
	if (output.addressData->data != 2 || output.triedAction != TRIED_RIGHT){
		PRINTF("Unit Test failed.\n");
		return -13;
	}


	Pop(testStack, &output);
	if (output.addressData->data != 1 || output.triedAction != TRIED_LEFT){
		PRINTF("Unit Test failed.\n");
		return -14;
	}

	if (Pop(testStack, &output) != 1){
		PRINTF("Unit Test failed.\n");
		return -15;
	}

	if (DeleteStack(testStack)){
		PRINTF("Unit Test failed.\n");
		return -16;
	}

	if (DeleteBintree(root) !=0){
		PRINTF("Unit Test failed.\n");
		return -17;
	}

	return 0;
}

int UnitTest_DFS(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	if (FindInternalNodes_DFS(root)!=0)
		return -1;

	MakeChild(root, LEFT, 2, 2);
	if (FindInternalNodes_DFS(root)!=1)
		return -2;

	MakeChild(root, RIGHT, 3, 3);
	if (FindInternalNodes_DFS(root)!=1)
		return -3;

	MakeChild(root->left, BOTH, 4, 5);
	if (FindInternalNodes_DFS(root)!=2)
		return -4;


	MakeChild(root->right, BOTH, 6, 7);
	if (FindInternalNodes_DFS(root)!=3)
		return -5;

	MakeChild(root->left->left, LEFT, 8, 8);
	if (FindInternalNodes_DFS(root)!=4)
		return -6;

	MakeChild(root->right->left, BOTH, 9, 10);
	if (FindInternalNodes_DFS(root)!=5)
		return -7;

	DeleteBintree(root);

	return 0;
}


