#include "mylib.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	if (root->left->data!=2 || root->right->data!=3){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	MakeChild(root->left, RIGHT, 4, 4);
	if (root->left->left != NULL || root->left->right->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	MakeChild(root->left, LEFT, 5, 5);
	if (root->left->left->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	MakeChild(root->right, LEFT, 6, 6);
	if (root->right->left->data != 6 || root->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	MakeChild(root->right->right, RIGHT, 7, 7);
	if (root->right->right->data != 7){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	DeleteBintree(root);
	return 0;
}

int UnitTest_Stack(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	STACK *testStack = NULL;

	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);

	testStack = CreateStack();
	if (Pop(testStack)){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, root);
	if (testStack->end->addressData->data != 1 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Push(testStack, root->left);
	if (testStack->end->addressData->data != 2 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Push(testStack, root->right);
	if (testStack->end->addressData->data != 3 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (Pop(testStack)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testStack->end->addressData->data != 2 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Push(testStack, root->left->left);
	if (testStack->end->addressData->data != 4 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Push(testStack, root->left->right);
	if (testStack->end->addressData->data != 5 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (Pop(testStack)->data != 5 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (Pop(testStack)->data != 4 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (Pop(testStack)->data != 2 || testStack->begin->addressData->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (Pop(testStack)->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (Pop(testStack)){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (testStack->begin != NULL || testStack->end != NULL){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	DeleteBintree(root);
	DeleteStack(testStack);

	return 0;	
}

int UnitTest_MakeMirror(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->right, LEFT, 4, 4);
	MakeChild(root->right->left, BOTH, 5, 6);
	MakeChild(root->right->left->right, RIGHT, 7, 7);
	MakeChild(root->right->left->right->right, LEFT, 8, 8);
	MakeChild(root->right->left->right->right->left, BOTH, 9, 10);

	MakeMirror_DFS(root);

	if (root->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (root->left->data !=3){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (root->right->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (root->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (root->left->right->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (root->right->left != NULL || root->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (root->left->right->left->data != 6){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}
	
	if (root->left->right->right->data != 5){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}


	if (root->left->right->left->left->data != 7){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (root->left->right->left->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (root->left->right->right->right != NULL){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (root->left->right->left->left->left != NULL){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (root->left->right->left->left->right->data != 8){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (root->left->right->left->left->right->left->data != 10){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (root->left->right->left->left->right->right->data != 9){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	DeleteBintree(root);
	return 0;
}

