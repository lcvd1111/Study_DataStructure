#include "test.h"
#include "mylib.h"

int UnitTest(void){
	BINTREE_NODE *root = NULL;
	STACK *myStack = NULL;

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	
	myStack = CreateStack();

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);

	if (Pop(myStack, NULL) != NULL){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	Push(myStack, root, NULL);
	Push(myStack, root->left, NULL);
	Push(myStack, root->right, NULL);
	Push(myStack, root->left->left, NULL);
	Push(myStack, root->left->right, NULL);
	Push(myStack, root->right->left, NULL);
	Push(myStack, root->right->right, NULL);

	if (Pop(myStack, NULL)->data != 7){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 1 passed.\n");

	if (Pop(myStack, NULL)->data != 6){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 2 passed.\n");
	
	if (Pop(myStack, NULL)->data != 5){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 3 passed.\n");
	
	if (Pop(myStack, NULL)->data != 4){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 4 passed.\n");
	
	if (Pop(myStack, NULL)->data != 3){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 5 passed.\n");
	
	if (Pop(myStack, NULL)->data != 2){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 6 passed.\n");
	if (Pop(myStack, NULL)->data != 1){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	PRINTF("Test 7 passed.\n");
	if (Pop(myStack, NULL) != NULL){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	CleanStack(myStack);
	
	PRINTF("Unit Test Success.\n");

	return 0;
}
