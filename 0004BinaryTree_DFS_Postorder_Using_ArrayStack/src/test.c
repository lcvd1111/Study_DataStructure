#include "test.h"

int test(void)
{
	BINTREE_NODE *root;
	STACK myStack;
	STACK_DATA *popBuff = NULL;
	int fullFlag;
	int emptyFlag;

	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	
	for (int i=0 ; i<STACK_MAX ; i++){
		myStack.stack_Array[i] = NULL;
	}
	myStack.end = -1;

	popBuff = (STACK_DATA *)malloc(sizeof(STACK_DATA));

	//Test Popping when the stack is empty
	if (Pop(&myStack, popBuff, &emptyFlag) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if (emptyFlag != 1){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	Push(&myStack, root, TRIED_LEFT, &fullFlag);
	Push(&myStack, root->left, TRIED_RIGHT, &fullFlag);
	Push(&myStack, root->right, TRIED_LEFT, &fullFlag);
	Push(&myStack, root->left->left, TRIED_RIGHT, &fullFlag);
	Push(&myStack, root->left->right, TRIED_LEFT, &fullFlag);
	Push(&myStack, root->right->left, TRIED_RIGHT, &fullFlag);
	Push(&myStack, root->right->right, TRIED_LEFT, &fullFlag);



	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 7){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_LEFT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 6){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_RIGHT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 5){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_LEFT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 4){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_RIGHT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 3){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_LEFT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 2){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_RIGHT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	else {
		if(popBuff->dataAddress->data != 1){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
		if(popBuff->dataAction != TRIED_LEFT){
			PRINTF("Unit Test Fail.\n");
			return -1;
		}
	}

	if (Pop(&myStack, popBuff, &emptyFlag) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}
	if (emptyFlag != 1){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	printf("Unit Test Success.\n");

	return 0;
}
