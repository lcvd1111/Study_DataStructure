#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE a, b, c, d, e;
	STACK *testStack = NULL;

	testStack = CreateStack();
	a.number = 1;
	b.number = 2;
	c.number = 3;
	d.number = 4;
	e.number = 5;

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, &a);
	Push(testStack, &b);

	if (Pop(testStack)->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Push(testStack, &c);
	Push(testStack, &d);
	Push(testStack, &e);
	
	if (testStack->end != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (Pop(testStack)->number != 5){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (Pop(testStack)->number != 4){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (Pop(testStack)->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (Pop(testStack)->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	DeleteStack(testStack);

	return 0;
}

int UnitTest_Search(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));

	testRoot->left->number = 36;
	testRoot->right->number = 130;
	strncpy(testRoot->left->name, "Courant", NAME_MAX);
	strncpy(testRoot->right->name, "Ellen", NAME_MAX);

	testRoot->left->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->left->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->left->left->number = 31;
	testRoot->left->right->number = 75;
	strncpy(testRoot->left->left->name, "Boyce", NAME_MAX);
	strncpy(testRoot->left->right->name, "Susan", NAME_MAX);
	
	testRoot->right->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->right->right->number = 200;
	strncpy(testRoot->right->right->name, "Poole", NAME_MAX);

	testRoot->left->left->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->left->right->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->right->right->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));

	testRoot->left->left->left->number = 15;
	testRoot->left->right->left->number = 60;
	testRoot->right->right->left->number = 150;
	strncpy(testRoot->left->left->left->name, "Tanenbaum", NAME_MAX);
	strncpy(testRoot->left->right->left->name, "Zorich", NAME_MAX);
	strncpy(testRoot->right->right->left->name, "Friedberg", NAME_MAX);

	testRoot->right->left = NULL;
	testRoot->left->left->right = NULL;
	testRoot->left->right->right = NULL;
	testRoot->right->right->right = NULL;
	testRoot->left->left->left->left = testRoot->left->left->left->right = NULL;
	testRoot->left->right->left->left = testRoot->left->right->left->right = NULL;
	testRoot->right->right->left->left = testRoot->right->right->left->right = NULL;

	if (strcmp(Search_Recursive(testRoot, 77)->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(Search_Recursive(testRoot, 36)->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (strcmp(Search_Recursive(testRoot, 130)->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (strcmp(Search_Recursive(testRoot, 31)->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (strcmp(Search_Recursive(testRoot, 75)->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(Search_Recursive(testRoot, 200)->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (strcmp(Search_Recursive(testRoot, 15)->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(Search_Recursive(testRoot, 60)->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (strcmp(Search_Recursive(testRoot, 150)->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	DeleteBintree(testRoot);
	return 0;
}
