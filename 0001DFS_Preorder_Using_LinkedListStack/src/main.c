#include <stdio.h>
#include <stdlib.h>
#include "../include/mylib.h"

int UnitTest(void);
BINTREE_NODE *MakeTree
(int, int, int, int, int, int, int, int, int, int);

int main(int argc, char **argv)
{
	BINTREE_NODE *root = NULL;
	
	if (UnitTest()){
		PRINTF("UNIT TEST ERROR.\n");
		return -1;
	}

	printf("Unit test completed.\n");

	root = MakeTree(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

	PreorderTraverse(root);

	CleanBintree(root);

	return 0;
}

int UnitTest(void)
{
	BINTREE_NODE *root_unittest = NULL;
	STACK stack_unittest;

	stack_unittest.begin = NULL;
	stack_unittest.end = NULL;
	root_unittest = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	
	if (root_unittest == NULL){
		PRINTF("Error. Malloc Fail.\n");
		return -1;
	}

	root_unittest->data = 1;
	root_unittest->left = NULL;
	root_unittest->right = NULL;
	MakeChild(root_unittest, BOTH, 2, 3);
	MakeChild(root_unittest->left, BOTH, 4, 5);

	Push(&stack_unittest, root_unittest);
	Push(&stack_unittest, root_unittest->left);
	Push(&stack_unittest, root_unittest->right);
	Push(&stack_unittest, root_unittest->left->left);
	Push(&stack_unittest, root_unittest->left->right);

	if (Pop(&stack_unittest)->data != 5){
		PRINTF("Error. 1st Pop makes an error.\n");
		return -1;
	}	
	if (Pop(&stack_unittest)->data != 4){
		PRINTF("Error. 2nd Pop makes an error.\n");
		return -1;
	}
	if (Pop(&stack_unittest)->data != 3){
		PRINTF("Error. 3rd Pop makes an error.\n");
		return -1;
	}
	if (Pop(&stack_unittest)->data != 2){
		PRINTF("Error. 4th Pop makes an error.\n");
		return -1;
	}
	if (Pop(&stack_unittest)->data != 1){
		PRINTF("Error. 5th Pop makes an error.\n");
		return -1;
	}
	if (Pop(&stack_unittest) != NULL){
		PRINTF("Error. 6th Pop makes an error.\n");
		return -1;
	}

	free(root_unittest->left->right);
	free(root_unittest->left->left);
	free(root_unittest->right);
	free(root_unittest->left);
	free(root_unittest);

	return 0;
}

BINTREE_NODE *MakeTree
(int arg_a, int arg_b, int arg_c, int arg_d, int arg_e,
int arg_f, int arg_g, int arg_h, int arg_i, int arg_j)
{
	BINTREE_NODE *root_ret = NULL;

	root_ret = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	
	if (root_ret == NULL){
		PRINTF("Error. Malloc Fail.\n");
		return NULL;
	}

	root_ret->data = arg_a;
	root_ret->left = NULL;
	root_ret->right = NULL;
	MakeChild(root_ret, BOTH, arg_b, arg_c);
	MakeChild(root_ret->left, BOTH, arg_d, arg_e);
	MakeChild(root_ret->right, BOTH, arg_f, arg_g);
	MakeChild(root_ret->left->right, LEFT, arg_h, arg_h);
	MakeChild(root_ret->right->left, RIGHT, arg_i, arg_i);
	MakeChild(root_ret->right->right, LEFT, arg_j, arg_j);

	return root_ret;
}
