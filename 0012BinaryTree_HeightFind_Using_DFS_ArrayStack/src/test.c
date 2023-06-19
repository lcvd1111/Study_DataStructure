#include "test.h"

int UnitTest_Stack(void)
{
	STACK *testStack = NULL;
	BINTREE_NODE *testRoot = NULL;
	WRAPPED_NODE output;
	
	testStack = CreateStack();
	if (testStack == NULL){
		PRINTF("ERROR: CreateStack( ) failed.\n");
		return -1;
	}

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 1;
	testRoot->left = NULL;
	testRoot->right = NULL;
	testRoot->header = NULL;

	MakeChild(testRoot, BOTH, 2, 3);
	MakeChild(testRoot->left, BOTH, 4, 5);
	MakeChild(testRoot->right, BOTH, 6, 7);

	Push(testStack, testRoot, TRIED_LEFT);
	Push(testStack, testRoot->left, TRIED_RIGHT);
	Push(testStack, testRoot->right, TRIED_LEFT);
	Push(testStack, testRoot->left->left, TRIED_RIGHT);
	Push(testStack, testRoot->left->right, TRIED_LEFT);
	Push(testStack, testRoot->right->left, TRIED_RIGHT);
	Push(testStack, testRoot->right->right, TRIED_LEFT);

	if(testStack->end != 6){
		PRINTF("Unit Test failed.\n");
		return -2;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 7)||(output.lastTried != TRIED_LEFT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 6)||(output.lastTried != TRIED_RIGHT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 5)||(output.lastTried != TRIED_LEFT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 4)||(output.lastTried != TRIED_RIGHT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 3)||(output.lastTried != TRIED_LEFT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 2)||(output.lastTried != TRIED_RIGHT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Pop(testStack, &output);
	if (((output.addressData)->data != 1)||(output.lastTried != TRIED_LEFT)){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	if (Pop(testStack, &output) != NULL){
		PRINTF("Unit Test failed.\n");
		return -4;
	}

	if (testStack->end != -1){
		PRINTF("Unit Test failed.\n");
		return -5;
	}
	
	if (DeleteStack(testStack)){
		PRINTF("ERROR: DeleteStack( ) failed.\n");
		return -1;
	}

	if (DeleteBintree(testRoot)){
		PRINTF("ERROR: DeleteBintree( ) failed.\n");
		return -1;
	}

	return 0;
}

int UnitTest_HeightFind_DFS(void)
{
	BINTREE_NODE *root = NULL;

	if (FindHeight_DFS(root) != 0){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	root->header = NULL;

	if (FindHeight_DFS(root) != 1){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(root, BOTH, 2, 3);
	if (FindHeight_DFS(root) != 2){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->left, LEFT, 4, 4);
	if (FindHeight_DFS(root) != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->left, RIGHT, 5, 5);
	if (FindHeight_DFS(root) != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->right, BOTH, 6, 7);
	if (FindHeight_DFS(root) != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->left->left, BOTH, 8, 9);
	if (FindHeight_DFS(root) != 4){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (DeleteBintree(root)) {
		PRINTF("Error: DeleteBintree( ) failed.\n");
		return -1;
	}
	
	return 0;
}
