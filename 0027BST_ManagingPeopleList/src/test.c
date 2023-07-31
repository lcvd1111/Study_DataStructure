#include "test.h"

int UnitTest_BST(void)
{
	BST *testBST = NULL;
	testBST = CreateBST();
	if (testBST == NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}
PRINTF("DEBUG\n");

	Add(testBST, "Joon", "Me");
	if (strcmp(testBST->root->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}
PRINTF("DEBUG\n");

	Add(testBST, "Ellen", "Love");
	if (strcmp(testBST->root->left->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}
PRINTF("DEBUG\n");

	Add(testBST, "Courant", "SVC");
	if (strcmp(testBST->root->left->left->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}
PRINTF("DEBUG\n");
	
	Add(testBST, "Susan", "MVC");
	if (strcmp(testBST->root->right->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}
PRINTF("DEBUG\n");

	return 0;
}

int UnitTest_Deque(void)
{
	return 0;
}

int UnitTest_Traversal(void)
{
	return 0;
}

