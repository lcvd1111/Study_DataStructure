#include "test.h"
#include <stdlib.h>

int UnitTest(void)
{
	int ret = 0;
	STACK myStack = {.begin=NULL, .end=NULL};
	BINTREE_NODE *root = NULL;

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	
	if (root == NULL){
		PRINTF("ERROR. malloc( ) Failed.\n");
		return -1;
	}

	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	MakeChild(root->right->right, LEFT, 8, 8);

	Push(&myStack, root);
	Push(&myStack, root->left);
	Push(&myStack, root->right);
	Push(&myStack, root->left->left);
	Push(&myStack, root->left->right);
	Push(&myStack, root->right->left);
	Push(&myStack, root->right->right);
	Push(&myStack, root->right->right->left);

	if(Pop(&myStack)->data != 8)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 7)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 6)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 5)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 4)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 3)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 2)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Pop(&myStack)->data != 1)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	
	if(Pop(&myStack) != NULL)
	{
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	printf("Unit test Success!\n");

	return ret;
}
