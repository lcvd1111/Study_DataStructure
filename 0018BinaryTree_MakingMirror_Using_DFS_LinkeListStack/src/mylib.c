#include "mylib.h"

//Function Declarations
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->begin = NULL;
	ret->end = NULL;

	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (binArg == NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->end = stackArg->begin;
		stackArg->begin->addressData = binArg;
		stackArg->begin->prev = NULL;
		stackArg->begin->next = NULL;
		return stackArg;
	}

	if (stackArg->end->next != NULL){
		PRINTF("ERROR: Last element's next position is not NULL.\n");
		return NULL;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next->next = NULL;
	stackArg->end->next->addressData = binArg;
	stackArg->end = stackArg->end->next;
	
	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg==NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL)
		return NULL;
	
	ret = stackArg->end->addressData;
	
	//when the stack has only an element.
	if (stackArg->begin == stackArg->end){
		free(stackArg->begin);
		stackArg->begin = NULL;
		stackArg->end = NULL;
		return ret;
	}

	stackArg->end = stackArg->end->prev;
	free(stackArg->end->next);
	stackArg->end->next = NULL;

	return ret;
}

STACK *EmptyStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	while(Pop(stackArg) != NULL)
		;

	if (stackArg->begin != NULL || stackArg->end != NULL){
		PRINTF("ERROR: begin != NULL || end != NULL\n");
		return NULL;
	}

	return stackArg;
}

int DeleteStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return -1;
	}

	EmptyStack(stackArg);

	free(stackArg);

	return 0;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECT selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent->left is not NULL.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent->right is not NULL.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if (parent->left != NULL){
			PRINTF("ERROR: parent->left is not NULL.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		if (parent->right != NULL){
			PRINTF("ERROR: parent->right is not NULL.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
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

BINTREE_NODE *MakeMirror_DFS(BINTREE_NODE *root)
{
	return root;
}

int DeleteBintree(BINTREE_NODE *root)
{
	return 0;
}
