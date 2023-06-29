#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg)
{
	if (stackArg==NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (binArg == NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	//When the Stack is full.
	if (stackArg->end == STACK_MAX-1){
		PRINTF("ERROR: stack is full.\n");
		return NULL;
	}

	stackArg->end += 1;
	(stackArg->stackArray)[stackArg->end] = binArg;

	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//When the stack is empty
	if (stackArg->end == -1)
		return NULL;
	
	ret = (stackArg->stackArray)[stackArg->end];

	stackArg->end -= 1;

	return ret;
}

int DeleteStack(STACK *stackArg)
{
	free(stackArg);
	return 0;
}

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECT selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a right child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a right child.\n");
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
	}
	return parent;
}

BINTREE_NODE *MakeMirror(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	BINTREE_NODE *swapBuffer = NULL;
	STACK *DFS_Stack = NULL;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->left == NULL && root->right == NULL){
		return root;
	}

	current = root;
	DFS_Stack = CreateStack();

	while(1){
		swapBuffer = current->left;
		current->left = current->right;
		current->right = swapBuffer;

		Push(DFS_Stack, current);
		current = current->left;

		if (current != NULL)
			continue;

		//when the left-moved is NULL.
		while(1){
			current = Pop(DFS_Stack);
			
			//When the traversal is completed.
			if (current != NULL)
				return root;

			current = current->right;

			if (current != NULL)
				break;

			//when the right-moved position NULL.
			continue; //It's okay to remove this statement.
		}
	}

	DeleteStack(DFS_Stack);

}

int DeleteBintree(BINTREE_NODE *root)
{
	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return -1;
	}

	if (root->left == NULL && root->right == NULL){
		free(root);
		return 0;
	}

	/*
	//Traversing every node
	while(1){
	}

	//Freeing every node
	*/

	return 0;
}
