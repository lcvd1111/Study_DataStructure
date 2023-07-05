#include "test.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	if (testRoot == NULL){
		PRINTF("ERROR: malloc() failed.\n");
		return -1;
	}

	testRoot->number = 1;
	strncpy(testRoot->name, "Joon", 32);
	
	MakeChild(testRoot, BOTH, 2, "Ellen", 3, "Kim");
	if (testRoot->left->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (strcmp(testRoot->left->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(testRoot->left, RIGHT, 4, "Vincent", 4, "Vincent");
	if (testRoot->left->right->number != 4){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (strcmp(testRoot->left->right->name, "Vincent")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	MakeChild(testRoot->right, LEFT, 5, "Courant", 5, "Courant");
	if (testRoot->right->left->number != 5){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(testRoot->right->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testRoot->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}
	return 0;
}

int UnitTest_Search(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->number = 13;
	strncpy(root->name, "Joon", NAME_MAX);
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 7, "Ellen", 36, "Hartman");
	MakeChild(root->left, BOTH, 3, "Courant", 11, "Callahan");
	MakeChild(root->left->left, RIGHT, 5, "Stewart", 5, "Stewart");
	MakeChild(root->right, BOTH, 25, "Munkres", 74, "Zorich");
	MakeChild(root->right->left, BOTH, 14, "Maxwell",26, "Steinmetz");
	MakeChild(root->right->right, BOTH, 55, "Friedberg", 100, "Lax");

	if(strcmp(SearchBST(root, 55)->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if(strcmp(SearchBST(root, 100)->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}
	
	if(strcmp(SearchBST(root, 14)->name, "Maxwell")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}
	
	if(strcmp(SearchBST(root, 26)->name, "Steinmetz")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if(strcmp(SearchBST(root, 25)->name, "Munkres")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if(strcmp(SearchBST(root, 74)->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}
	
	if(strcmp(SearchBST(root, 5)->name, "Stewart")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if(strcmp(SearchBST(root, 3)->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if(strcmp(SearchBST(root, 11)->name, "Callahan")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if(strcmp(SearchBST(root, 7)->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if(strcmp(SearchBST(root, 36)->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if(SearchBST(root, 6) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	return 0;
}
