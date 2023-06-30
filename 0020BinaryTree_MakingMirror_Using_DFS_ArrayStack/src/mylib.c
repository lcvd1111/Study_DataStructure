#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg, TRIED_ACTION actionArg)
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
	(stackArg->stackArray)[stackArg->end].addressData = binArg;
	(stackArg->stackArray)[stackArg->end].triedAction = actionArg;

	return stackArg;
}

STACK *Pop(STACK *stackArg, STACK_NODE *popOutput)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (popOutput == NULL){
		PRINTF("ERROR: popOutput is NULL.\n");
		return NULL;
	}

	//When the stack is empty
	if (stackArg->end == -1)
		return NULL;
	
	popOutput->addressData = (stackArg->stackArray)[stackArg->end].addressData;
	popOutput->triedAction = (stackArg->stackArray)[stackArg->end].triedAction;

	stackArg->end -= 1;

	return stackArg;
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
	STACK_NODE popOutput;
	int i=1, j=1, k=1;
	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->left == NULL && root->right == NULL){
		return root;
	}

	current = root;
	DFS_Stack = CreateStack();

	while(i){
		Push(DFS_Stack, current, TRIED_LEFT);
		current = current->left;
		
		if (current != NULL)
			continue;

		//When the trying to move left failed to NULL.
		Pop(DFS_Stack, &popOutput);
		current = popOutput.addressData;

		while(j){
			Push(DFS_Stack, current, TRIED_RIGHT);
			current = current->right;

			if (current != NULL)
				break;

			//When the trying to move right failed to NULL.
			Pop(DFS_Stack,&popOutput);
			current = popOutput.addressData;

			while(j){
				swapBuffer = current->left;
				current->left = current->right;
				current->right = swapBuffer;

				if(Pop(DFS_Stack, &popOutput)==NULL){
					i=0;
					j=0;
					return root;
				}

				current = popOutput.addressData;

				if (popOutput.triedAction == TRIED_LEFT)
					break;
				else if (popOutput.triedAction == TRIED_RIGHT)
					continue;
			}
		}
	}

	DeleteStack(DFS_Stack);

}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK *DFS_Stack = NULL;
	STACK *result_Stack = NULL;
	STACK_NODE popOutput;
	int i = 1;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return -1;
	}

	if (root->left == NULL && root->right == NULL){
		free(root);
		return 0;
	}

	current = root;
	DFS_Stack = CreateStack();
	result_Stack = CreateStack();

	//Traversing every node
	while(i){
		Push(result_Stack, current, TRIED_NONE);

		Push(DFS_Stack, current, TRIED_NONE);
		current = current->left;
		
		if(current != NULL)
			continue;

		while(1){
			if(Pop(DFS_Stack, &popOutput)==NULL){
				i=0;
				break;
			}
			current = popOutput.addressData;
			current = current->right;

			if (current != NULL)
				break;

			continue;
		}
	}

	//Freeing every node
	while(1){
		if (Pop(result_Stack, &popOutput) == NULL)
			break;

		free(popOutput.addressData);
	}

	DeleteStack(DFS_Stack);
	DeleteStack(result_Stack);
	return 0;
}
