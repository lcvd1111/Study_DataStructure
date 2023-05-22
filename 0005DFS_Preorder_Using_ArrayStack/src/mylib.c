#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));

	ret->end = -1;
	
	for (int i=0; i<STACK_MAX ; i++){
		ret->stackArray[i] = NULL;
	}

	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg, int *fullFlag)
{
	if (stackArg->end == STACK_MAX - 1){
		if (fullFlag != NULL)
			*fullFlag = 1;
		return NULL;
	}

	++(stackArg->end);

	(stackArg->stackArray)[stackArg->end] = bintreeArg;

	if (stackArg->end == STACK_MAX - 1){
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

	if (stackArg->end == -1){
		if (emptyFlag!= NULL)
			*emptyFlag = 1;
		return NULL;
	}

	ret = (stackArg->stackArray)[stackArg->end];

	(stackArg->stackArray)[stackArg->end] = NULL;
	
	--(stackArg->end);

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
	}
	else {
		if (emptyFlag != NULL)
			*emptyFlag = 0;
	}

	return ret;
}

STACK *CleanStack(STACK *stackArg)
{
	while(Pop(stackArg, NULL) != NULL)
		;
	
	return stackArg;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
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
			PRINTF("ERROR: parent already has a child(or children).\n");
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

BINTREE_NODE *PreOrder(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK *myStack;
	int emptyFlag;
	int fullFlag;

	myStack = CreateStack();
	current = root;

	while(1){
		if (current != NULL){
			printf("Visit Check: %d\n", current->data);
			if(Push(myStack, current, &fullFlag)==NULL){
				PRINTF("ERROR: Stack overflow occured.\n");
				return NULL;
			}
			current = current->left;
		}
		else if (current == NULL){
			current = Pop(myStack, &emptyFlag);
			if ((current == NULL)&&(emptyFlag == 1)){
				printf("Traversal Complete.\n");
				CleanStack(myStack);
				return root;
			}
			current = current->right;
		}
	}
	CleanStack(myStack);
	return root;
}

BINTREE_NODE *CleanBintree(BINTREE_NODE *root)
{
	return root;
}
