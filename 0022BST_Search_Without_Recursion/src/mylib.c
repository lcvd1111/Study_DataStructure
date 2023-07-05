#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = (STACK *)malloc(sizeof(STACK));
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

	//When the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->end = stackArg->begin;
		stackArg->end->data = binArg;
		stackArg->end->prev = NULL;
		stackArg->end->next = NULL;
		return stackArg;
	}

	if(stackArg->end->next != NULL){
		PRINTF("ERROR: stackArg->end->next is not NULL.\n");
		return NULL;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next->next = NULL;
	stackArg->end->next->data = binArg;
	stackArg->end = stackArg->end->next;

	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//When the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL)
		return NULL;

	
	ret = stackArg->end->data;
	
	//When the stack has only an element.
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

	if(Pop(stackArg) != NULL){
		PRINTF("ERROR: EmptyStack() went wrong.\n");
		return NULL;
	}

	if(stackArg->begin != NULL || stackArg->end != NULL){
		PRINTF("ERROR: EmptyStack() went wrong.\n");
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

	if(EmptyStack(stackArg)==NULL){
		PRINTF("ERROR: EmptyStack() failed.\n");
		return -2;
	}

	free(stackArg);

	return 0;
}

BINTREE_NODE *SearchBST(BINTREE_NODE *root, int arg)
{
	BINTREE_NODE *current = NULL;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return 0;
	}

	current = root;

	while(1){
		if (current->number > arg){
			if (current->left == NULL)
				return NULL;

			current = current->left;
			continue;
		}
		
		if (current->number < arg){
			if (current->right == NULL)
				return NULL;
			
			current = current->right;
			continue;
		}

		if (current->number == arg){
			return current;
		}

		PRINTF("ERROR: Search went wrong.\n");
		return NULL;
	}
	current = root;
	return 0;
}

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR select,
 int lArg, const char *lArgString, 
 int rArg, const char *rArgString)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(select){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));

		parent->left->number = lArg;
		strncpy(parent->left->name, lArgString, NAME_MAX);
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent has a right child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->number = rArg;
		strncpy(parent->right->name, rArgString, NAME_MAX);
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if (parent->left != NULL){
			PRINTF("ERROR: parent has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->number = lArg;
		strncpy(parent->left->name, lArgString, NAME_MAX);
		parent->left->left = NULL;
		parent->left->right = NULL;
		
		if (parent->right != NULL){
			PRINTF("ERROR: parent has a right child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE ));
		parent->right->number = rArg;
		strncpy(parent->right->name, rArgString, NAME_MAX);
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

int DeleteBintree(BINTREE_NODE *root)
{

	return 0;
}
