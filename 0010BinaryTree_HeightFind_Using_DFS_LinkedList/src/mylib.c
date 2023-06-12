#include "mylib.h"

//Function Definitions
BTREE_NODE *MakeChild
(BTREE_NODE *parent, CHILD_SELECTOR selector, int left, int right)
{
	if (parent==NULL){
		PRINTF("ERROR: parent is null\n");
		return NULL;
	}

	switch (selector) {
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: Parent already has children(or a child).\n");
			return NULL;
		}

		parent->left = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
		
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->left->data = left;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: Parent already has children(or a child).\n");
			return NULL;
		}

		parent->right = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
		
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->right->data = right;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case BOTH:
		if ((parent->left != NULL)
			|| (parent->right != NULL)){
			PRINTF("ERROR: Parent already has children(or a child).\n");
			return NULL;
		}

		parent->left = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
		
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->left->data = left;
		parent->left->left = NULL;
		parent->left->right = NULL;
		
		parent->right = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
		
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->right->data = right;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case NONE:
		break;
	default:
		PRINTF("ERROR: Wrong Selector Value.\n");
		return NULL;
		break;
	}	

	return parent;
}

STACK *CreateStack(void){

	STACK *ret = NULL;

	ret = (STACK *)malloc(sizeof(STACK));
	ret->begin = NULL;
	ret->end = NULL;

	return ret;
}

STACK *Push(STACK *stackArg, BTREE_NODE *btreeArg, TRIED_ACTION triedAction)
{
	STACK_NODE *temp = NULL;

	if (stackArg==NULL || btreeArg==NULL){
		PRINTF("ERROR: stack or btree node is NULL.\n");
		return NULL;
	}

	temp = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	
	if (!temp){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	temp->nodeAddress = btreeArg;
	temp->lastTried = triedAction;

	if (stackArg->begin == NULL){
		//The case when the stack is empty.
		stackArg->begin = temp;
		stackArg->end = temp;
		stackArg->begin->next = NULL;
		stackArg->begin->prev = NULL;
		return stackArg;
	}

	stackArg->end->next = temp;
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next->next = NULL;
	stackArg->end = stackArg->end->next;

	return stackArg;
}

WRAPPED_NODE *Pop(STACK *stackArg)
{
	WRAPPED_NODE *ret = NULL;
	
	if (stackArg->begin == NULL){
		//The case when the stack is empty.
		return NULL;
	}

	ret = (WRAPPED_NODE *)malloc(sizeof(WRAPPED_NODE));
	
	if (stackArg->begin == stackArg->end){
		//The case when  the stack has an signle element.
		ret->nodeAddress_W = stackArg->begin->nodeAddress;
		ret->lastTried_W = stackArg->begin->lastTried;
		free(stackArg->begin);
		stackArg->begin = NULL;
		stackArg->end = NULL;
		return ret;
	}

	ret->nodeAddress_W = stackArg->end->nodeAddress;
	ret->lastTried_W = stackArg->end->lastTried;
	stackArg->end = stackArg->end->prev;
	free(stackArg->end->next);
	stackArg->end->next = NULL;

	return ret;
}

STACK *EmptyStack(STACK *stackArg)
{
	return NULL;
}

int RemoveStack(STACK *stackArg)
{
	return 0;
}

int Calc_Subtree_Height(BTREE_NODE parent, CHILD_SELECTOR direction)
{
	return 0;
}

int Calc_Btree_Height_DFS(BTREE_NODE *root)
{
	return 0;
}
