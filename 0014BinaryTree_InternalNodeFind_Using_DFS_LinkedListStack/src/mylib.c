#include "mylib.h"

//Function Definitions
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (selector){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->header = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = lArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		parent->right->header = NULL;
		break;
	case BOTH:
		if (parent->left!=NULL || parent->right!=NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->header = NULL;
		
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = lArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		parent->right->header = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong selector Value.\n");
		return NULL;
		break;
	}
	return parent;
}

STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));

	//Initial state is set to 'Empty' by default.
	ret->begin = NULL;
	ret->end = NULL;
	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg, ACTION triedAction)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->end = stackArg->begin;
		stackArg->begin->addressData = binArg;
		stackArg->begin->lastAction = triedAction;
		stackArg->begin->next = NULL;
		stackArg->begin->prev = NULL;
		return stackArg;
	}

	if(stackArg->end->next != NULL){
		PRINTF("ERROR: end->next is not NULL.\n");
		return NULL;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end->next->addressData = binArg;
	stackArg->end->next->lastAction = triedAction;
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next = NULL;
	stackArg->end = stackArg->end->next;	

	return stackArg;
}

STACK *Pop(STACK *stackArg, STACK_NODE *outputStore)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		return NULL;
	}

	outputStore->addressData = stackArg->end->addressData;
	outputStore->lastAction = stackArg->end->lastAction;
	outputStore->prev = NULL;
	outputStore->next = NULL;

	///When the stack has only an element.
	if (stackArg->begin == stackArg->end){
		free(stackArg->end);
		stackArg->begin = NULL;
		stackArg->end = NULL;
		return stackArg;
	}

	stackArg->end=stackArg->end->prev;
	free(stackArg->end->next);
	stackArg->end->next = NULL;

	return stackArg;
}

int EmptyStack(STACK *stackArg)
{
	return 0;
}

int FindInternalNodes(BINTREE_NODE *root)
{
	int ret = 0;
	
	return ret;
}

int DeleteBintree(BINTREE_NODE *root)
{
	int ret = 0;

	return ret;
}
