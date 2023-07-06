#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE a,b,c,d,e;
	STACK *testStack = NULL;

	a.number = 1;
	strncpy(a.name, "TEST", NAME_MAX);

	b.number = 2;
	strncpy(b.name, "TEST", NAME_MAX);

	c.number = 3;
	strncpy(c.name, "TEST", NAME_MAX);

	d.number = 4;
	strncpy(d.name, "TEST", NAME_MAX);

	e.number = 5;
	strncpy(e.name, "TEST", NAME_MAX);
	
	testStack = CreateStack();

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, &a);
	Push(testStack, &b);

	if (testStack->end->data->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testStack->end->prev->data->number != 1){
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

	if (testStack->end->data->number != 5){
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

	if (testStack->begin != NULL || testStack->end != NULL){
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
	testRoot->number = 17;
	strncpy(testRoot->name, "Joon", NAME_MAX);

	Insert(testRoot, 36, "Ellen");
	Insert(testRoot, 9, "Friedberg");
	Insert(testRoot, 15, "Hartman");
	Insert(testRoot, 55, "Lax");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 45, "Tanenbaum");
	Insert(testRoot, 3, "Poole");
	Insert(testRoot, 14, "Boyce");
	Insert(testRoot, 38, "Colley");

	if(strcmp(testRoot->left->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if(strcmp(testRoot->right->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if(strcmp(testRoot->left->left->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if(strcmp(testRoot->left->right->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if(strcmp(testRoot->right->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if(strcmp(testRoot->right->right->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if(strcmp(testRoot->left->right->left->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if(strcmp(testRoot->right->right->left->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if(strcmp(testRoot->right->right->left->left->name, "Colley")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	DeleteBintree(testRoot);
	
	return 0;
}
