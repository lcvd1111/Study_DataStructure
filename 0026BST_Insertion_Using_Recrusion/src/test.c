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
	if ((testStack->stackArray)[testStack->end]->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Push(testStack, &b);
	if (testStack->end != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (Pop(testStack)->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	Push(testStack, &c);
	Push(testStack, &d);
	Push(testStack, &e);

	if (testStack->end != 3){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (Pop(testStack)->number != 5){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (Pop(testStack)->number != 4){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (Pop(testStack)->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (Pop(testStack)->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testStack->end != -1){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	DeleteStack(testStack);
	
	return 0;
}

int UnitTest_Insert(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert_Recursive(testRoot, 300, "Ellen");
	Insert_Recursive(testRoot, 50, "Courant");
	Insert_Recursive(testRoot, 85, "Poole");
	Insert_Recursive(testRoot, 17, "Susan");
	Insert_Recursive(testRoot, 60, "Friedberg");
	Insert_Recursive(testRoot, 55, "Boyce");
	Insert_Recursive(testRoot, 900, "Tanenbaum");
	Insert_Recursive(testRoot, 11, "Zorich");

	if (testRoot->number != 77){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(testRoot->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->left->number != 50){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (strcmp(testRoot->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->right->number != 300){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(testRoot->right->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(testRoot->left->left->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->left->right->number != 60){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (strcmp(testRoot->left->right->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->right->left->number != 85){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (strcmp(testRoot->right->left->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (testRoot->right->right->number != 900){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (strcmp(testRoot->right->right->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (testRoot->left->left->left->number != 11){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	if (strcmp(testRoot->left->left->left->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	if (testRoot->left->right->left->number != 55){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if (strcmp(testRoot->left->right->left->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	return 0;
}
