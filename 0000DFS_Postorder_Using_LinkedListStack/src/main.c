#include <stdio.h>
#include <stdlib.h>
#include "../include/mylib.h" 

int main(int argc, char **argv)
{
	BINTREE_NODE *root = NULL;
	
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	
#ifdef UNIT_TEST
	STACK myStack;
	STACK_NODE_DATA poppedData;
	myStack.begin = NULL;
	myStack.end = NULL;
#endif

	/* Making Binary Tree start */
	if (MakeChild(root, BOTH, 2, 3) == NULL){
		PRINTF("Error.\n");
		return -1;
	}

	if (MakeChild(root->left, BOTH, 4, 5) == NULL){
		PRINTF("Error.\n");
		return -1;
	}

	if (MakeChild(root->right, BOTH, 6, 7) == NULL){
		PRINTF("Error.\n");
		return -1;
	}

	if (MakeChild(root->left->right, LEFT, 8, 0) == NULL){
			PRINTF("Error.\n");
			return -1;
	}

	if (MakeChild(root->right->left, RIGHT, 0, 9) == NULL){
			PRINTF("Error.\n");
			return -1;
	}

	if (MakeChild(root->right->right, LEFT, 10, 0) == NULL){
			PRINTF("Error.\n");
			return -1;
	}
	//         1
	//       /   \
	//      2     3
	//     /\    /  \
	//    4  5  6    7
	//      /   \   /
	//     8    9  10

#ifdef UNIT_TEST
	Push(&myStack, root, TRIED_LEFT);
	Push(&myStack, root->left, TRIED_RIGHT);
	Push(&myStack, root->right, TRIED_RIGHT);
	Push(&myStack, root->left->left, TRIED_LEFT);
	Push(&myStack, root->left->right, TRIED_LEFT);
	
	if (&poppedData != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if ((poppedData.data_Address)->data != 5) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if (poppedData.data_Action != TRIED_LEFT) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if (&poppedData != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if ((poppedData.data_Address)->data != 4) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if (poppedData.data_Action != TRIED_LEFT) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if (&poppedData != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if ((poppedData.data_Address)->data != 3) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if (poppedData.data_Action != TRIED_RIGHT) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if (&poppedData != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if ((poppedData.data_Address)->data != 2) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if (poppedData.data_Action != TRIED_RIGHT) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if (&poppedData != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if ((poppedData.data_Address)->data != 1) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	if (poppedData.data_Action != TRIED_LEFT) {
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}
	
	if (NULL != Pop(&myStack, &poppedData)){
		PRINTF("UNIT TEST FAIL.\n");
		return -1;
	}	
#endif

	Post_order_Traversal(root);
	printf("\n\n\n\n<Recursive Method>\n");
	Post_order_Traversal_Recursive(root);
	CleanBintree(root);

	return 0;
}

