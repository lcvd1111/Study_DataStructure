#include "test.h"

int UnitTest(void){

	BINTREE_NODE *root = NULL;
	DEQUE myDeque = {.begin=NULL, .end=NULL};

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	MakeChild(root->left->left, BOTH, 8, 9);

	InsertRight(&myDeque, root);
	InsertRight(&myDeque, root->left);
	InsertRight(&myDeque, root->right);
	InsertRight(&myDeque, root->left->left);
	InsertRight(&myDeque, root->left->right);
	InsertRight(&myDeque, root->right->left);
	InsertRight(&myDeque, root->right->right);
	InsertRight(&myDeque, root->left->left->left);
	InsertRight(&myDeque, root->left->left->right);

	if (DeleteRight(&myDeque, NULL)->data != 9){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 8){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 7){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 6){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 5){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 4){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 3){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 2){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL)->data != 1){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteRight(&myDeque, NULL) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	InsertLeft(&myDeque, root);
	InsertLeft(&myDeque, root->left);
	InsertLeft(&myDeque, root->right);
	InsertLeft(&myDeque, root->left->left);
	InsertLeft(&myDeque, root->left->right);
	InsertLeft(&myDeque, root->right->left);
	InsertLeft(&myDeque, root->right->right);
	InsertLeft(&myDeque, root->left->left->left);
	InsertLeft(&myDeque, root->left->left->right);
	if (DeleteLeft(&myDeque, NULL)->data != 9){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 8){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 7){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 6){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 5){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 4){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 3){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 2){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL)->data != 1){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (DeleteLeft(&myDeque, NULL) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	printf("Unit Test Complete.\n");

	return 0;
}
