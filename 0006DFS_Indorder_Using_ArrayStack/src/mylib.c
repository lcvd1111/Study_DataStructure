#include "mylib.h"

//Function Definitions
STACK *CreateStack(uint32_t num)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
	ret->length = num;
	ret->stackArray = (BINTREE_NODE **)malloc(num * sizeof(BINTREE_NODE *));
	
	for (int i = 0 ; i<num ; i++)
		(ret->stackArray)[i] = NULL;

	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg, int *fullFlag)
{
	if (stackArg==NULL){
		PRINTF("ERROR. STACK * argument is NULL.\n");
		return NULL;
	}

	if (stackArg->end == (stackArg->length)-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
		return NULL;
	}

	(stackArg->end)++;

	(stackArg->stackArray)[stackArg->end] = bintreeArg;

	if (stackArg->end == (stackArg->length)-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
	}
	else {
		if (fullFlag != NULL)
			*fullFlag = 0;
	}
	
	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg, int *emptyFlag)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg==NULL){
		PRINTF("ERROR. STACK * argument is NULL.\n");
		return NULL;
	}

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return NULL;
	}
	
	ret = (stackArg->stackArray)[stackArg->end];
	(stackArg->stackArray)[stackArg->end] = NULL;
	(stackArg->end)--;

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
	}
	else {
		if (emptyFlag != NULL)
			*emptyFlag =0;
	}

	return ret;
}

STACK *CleanStack(STACK *stackArg)
{
	BINTREE_NODE **buf = stackArg->stackArray;

	while(Pop(stackArg, NULL) != NULL)
		;
	return stackArg;
}

STACK *RemoveStack(STACK *stackArg){

	if (stackArg == NULL)
		return NULL;

	CleanStack(stackArg);
	free(stackArg);

	return NULL;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector,int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (selector){
	case NONE:
		break;
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if ((parent->left != NULL)||(parent->right != NULL)){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return NULL;
		break;
	}
	return parent;
}

BINTREE_NODE *InOrder(BINTREE_NODE *root)
{
	BINTREE_NODE *current = root;
	int emptyFlag;
	int fullFlag;
	STACK *myStack = NULL;
	myStack = CreateStack(STACK_MAX);
	
	while(1){
		if (current != NULL){
			if(Push(myStack, current, &fullFlag)==NULL){
				PRINTF("ERROR: Stack Overflow occured.\n");
				return NULL;
			}
			current = current->left;
		}
		else if (current == NULL){
			current = Pop(myStack, &emptyFlag);
			if ((current == NULL)&&(emptyFlag == 1)){
				printf("Traversal Complete.\n");
				return root;
			}
			printf("Visit Check: %d\n", current->data);
			current = current->right;
		}
	}

	RemoveStack(myStack);

	return root;
}

BINTREE_NODE *CleanBintree(BINTREE_NODE *root)
{
	return root;
}

