#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE testNode01 = {1, "TEST", NULL, NULL};
	BINTREE_NODE testNode02 = {2, "TEST", NULL, NULL};
	BINTREE_NODE testNode03 = {3, "TEST", NULL, NULL};
	BINTREE_NODE testNode04 = {4, "TEST", NULL, NULL};
	BINTREE_NODE testNode05 = {5, "TeST", NULL, NULL};
	STACK *testStack = NULL;

	testStack = CreateStack();

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, &testNode01);
	Push(testStack, &testNode02);
	
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

	Push(testStack, &testNode03);
	Push(testStack, &testNode04);
	Push(testStack, &testNode05);

	if (Pop(testStack)->number != 5){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (Pop(testStack)->number != 4){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (Pop(testStack)->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (Pop(testStack)->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testStack->begin != NULL || testStack->end != NULL){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (DeleteStack(testStack)){
		PRINTF("ERROR: DeleteStack(testStack) failed.\n");
		return -1;
	}

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

	Insert(testRoot, 81, "Ellen");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 17, "Susan");
	Insert(testRoot, 31, "Poole");
	Insert(testRoot, 130, "Friedberg");
	Insert(testRoot, 95, "Lax");
	Insert(testRoot, 75, "Boyce");
	Insert(testRoot, 3, "Tanenbaum");
	Insert(testRoot, 42, "Hartman");
	Insert(testRoot, 100, "Zorich");

	if (testRoot->left->number != 35){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(testRoot->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (strcmp(testRoot->right->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(testRoot->left->left->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->left->right->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(testRoot->left->right->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (strcmp(testRoot->right->right->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (strcmp(testRoot->left->left->left->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (strcmp(testRoot->left->left->right->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (testRoot->left->right->left->number != 42){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	if (strcmp(testRoot->left->right->left->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if (strcmp(testRoot->right->right->left->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	if (strcmp(testRoot->right->right->left->right->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -20;
	}

	DeleteBintree(testRoot);
	return 0;
}

int UnitTest_Search(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 81, "Ellen");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 17, "Susan");
	Insert(testRoot, 31, "Poole");
	Insert(testRoot, 130, "Friedberg");
	Insert(testRoot, 95, "Lax");
	Insert(testRoot, 75, "Boyce");
	Insert(testRoot, 3, "Tanenbaum");
	Insert(testRoot, 42, "Hartman");
	Insert(testRoot, 100, "Zorich");

	if (strcmp(Search(testRoot, 100)->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(Search(testRoot, 42)->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (strcmp(Search(testRoot, 3)->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}
	
	if (strcmp(Search(testRoot, 75)->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (strcmp(Search(testRoot, 95)->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(Search(testRoot, 130)->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (strcmp(Search(testRoot, 31)->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(Search(testRoot, 17)->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (strcmp(Search(testRoot, 35)->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (strcmp(Search(testRoot, 81)->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (strcmp(Search(testRoot, 77)->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	DeleteBintree(testRoot);

	return 0;
}

int UnitTest_Delete(void)
{
	return 0;
}
