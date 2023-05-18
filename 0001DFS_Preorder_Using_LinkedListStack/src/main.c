#include <stdio.h>
#include <stdlib.h>
#include "../include/mylib.h"

int UnitTest(void);

int main(int argc, char **argv)
{
	if (UnitTest()){
		PRINTF("UNIT TEST ERROR.\n");
		return -1;
	}

	printf("Unit test completed.\n");

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
