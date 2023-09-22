#include "test.h"

int UnitTest(void)
{
	BINTREE_NODE *root = NULL;
	STACK *myStack = NULL;
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	
	myStack = CreateStack(8);
	
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	MakeChild(root->left->left, LEFT, 8, 8);	
	if (Pop(myStack, NULL) != NULL){
		PRINTF("Unit Test fail.\n");
		return -1;
	}

	printf("Test 1 success.\n");

	Push(myStack, root, NULL);
	Push(myStack, root->left, NULL);
	Push(myStack, root->right, NULL);
	Push(myStack, root->left->left, NULL);
	Push(myStack, root->left->right, NULL);
	Push(myStack, root->right->left, NULL);
	Push(myStack, root->right->right, NULL);
	Push(myStack, root->left->left->left, NULL);

	if (Push(myStack, root, NULL) != NULL){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 2 success.\n");

	if (Pop(myStack, NULL)->data != 8){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 3 success.\n");
	
	if (Pop(myStack, NULL)->data != 7){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 4 success.\n");
	
	if (Pop(myStack, NULL)->data != 6){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 5 success.\n");

	if (Pop(myStack, NULL)->data != 5){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 6 success.\n");
	
	if (Pop(myStack, NULL)->data != 4){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 7 success.\n");

	if (Pop(myStack, NULL)->data != 3){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 8 success.\n");

	if (Pop(myStack, NULL)->data != 2){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 9 success.\n");

	if (Pop(myStack, NULL)->data != 1){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 10 success.\n");

	if (Pop(myStack, NULL) != NULL){
		PRINTF("Unit Test fail.\n");
		return -1;
	}
	printf("Test 11 success.\n");

	printf("Unit Test Success.\n");
	return 0;
}
