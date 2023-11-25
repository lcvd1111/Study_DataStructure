#include "mylib.h"

//Function Definitions

STACK *CreateStack(void)
{
	STACK *ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
	for (int i=0 ; i<STACK_MAX ; i++)
		(ret->stackArray)[i]=NULL;

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

	//When the stack is full currently.
	if (stackArg->end == STACK_MAX - 1){
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

	//When the stack is empty currently.
	if (stackArg->end == -1){
		return NULL;
	}

	ret = (stackArg->stackArray)[stackArg->end];

	stackArg->end -= 1;

	return ret;
}

int DeleteStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return -1;
	}

	free(stackArg);
	
	return 0;
}


int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK *DFS_Stack = NULL;
	STACK *left_Stack = NULL;
	STACK *right_Stack = NULL;
	int i=1, j=1, k=1;

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
	left_Stack = CreateStack();
	right_Stack = CreateStack();

	while(i){
		Push(DFS_Stack, current);
		Push(left_Stack, current);

		current = current->left;

		if (current != NULL)
			continue;

		//When the current becomes NULL after moving left.
		current = Pop(DFS_Stack);
		Pop(left_Stack);

		while(j){
			Push(DFS_Stack, current);
			Push(right_Stack, current);
			current = current->right;

			if (current != NULL)
				break;

			//When the current becomes NULL after moving right.
			current = Pop(DFS_Stack);
			Pop(right_Stack);

			while(k){
				free(current);
				
				current = Pop(DFS_Stack);
				if (current == NULL){
					i = 0;
					j = 0;
					break;
				}

				if (left_Stack->end != -1){
					if (current == (left_Stack->stackArray)[left_Stack->end]){
						Pop(left_Stack);
						break;
					}
				}

				if (right_Stack->end != -1){
					if (current == (right_Stack->stackArray)[right_Stack->end]){
						Pop(right_Stack);
						continue;
					}
				}
			}
		}
	}

	DeleteStack(DFS_Stack);
	DeleteStack(left_Stack);
	DeleteStack(right_Stack);

	return 0;
}

BINTREE_NODE *Search_Recursive(BINTREE_NODE *root, int keyArg)
{
	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->number == keyArg)
		return root;
	
	if (root->number>keyArg && root->left==NULL)
		return NULL;

	if (root->number<keyArg && root->right==NULL)
		return NULL;

	if (root->number>keyArg)
		return Search_Recursive(root->left, keyArg);
	
	if (root->number<keyArg)
		return Search_Recursive(root->right, keyArg);

	PRINTF("ERROR: Something went wrong.\n");
	return NULL;
}

BINTREE_NODE *Insert_Recursive(BINTREE_NODE *root, int keyArg, char *keyStr)
{
	if(Search_Recursive(root, keyArg) != NULL){
		PRINTF("ERROR: keyArg already exists in the given BST.\n");
		return NULL;
	}

	if (root->number>keyArg && root->left==NULL){
		root->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		root->left->number = keyArg;
		strncpy(root->left->name, keyStr, NAME_MAX);
		return root;
	}

	if (root->number<keyArg && root->right == NULL){
		root->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		root->right->number = keyArg;
		strncpy(root->right->name, keyStr, NAME_MAX);
		return root;
	}

	if (root->number > keyArg)
		return Insert_Recursive(root->left, keyArg, keyStr);

	if (root->number < keyArg)
		return Insert_Recursive(root->right, keyArg, keyStr);

	PRINTF("ERROR: Something went wrong.\n");
	return NULL;
}
