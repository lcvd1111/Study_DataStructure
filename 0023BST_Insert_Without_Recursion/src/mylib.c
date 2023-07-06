#include "mylib.h"

BINTREE_NODE *Insert(BINTREE_NODE *root, int numArg, const char *nameArg)
{
	BINTREE_NODE *current = NULL;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	current = root;

	while(1){
		if (numArg > current->number){
			if (current->right != NULL){
				current = current->right;
				continue;
			}

			current->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			current->right->number = numArg;
			strncpy(current->right->name, nameArg, NAME_MAX);
			current->right->left = NULL;
			current->right->left = NULL;
			return root;
		}
		else if (numArg < current->number){
			if (current->left != NULL){
				current = current->left;
				continue;
			}

			current->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			current->left->number = numArg;
			strncpy(current->left->name, nameArg, NAME_MAX);
			current->left->left = NULL;
			current->left->right = NULL;
			return root;
		}
		else if (numArg == current->number){
			//The situation where the element already exists in given BST.
			return current;
		}
		else {
			PRINTF("ERROR: Something went wrong.\n");
			return NULL;
		}
	}
	return NULL;
}

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
	if (stackArg->begin==NULL && stackArg->end==NULL){
		stackArg->end = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->begin = stackArg->end;
		stackArg->end->data = binArg;
		stackArg->end->prev = NULL;
		stackArg->end->next = NULL;
		return stackArg;
	}

	if (stackArg->end->next != NULL){
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
	if (stackArg->begin == NULL && stackArg->end == NULL){
		return NULL;
	}

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
	if (stackArg==NULL){
		PRINTF("ERROR: stackArg is NULL\n");
		return NULL;
	}

	while(Pop(stackArg))
		;

	if(stackArg->begin != NULL || stackArg->end != NULL){
		PRINTF("ERROR: EmptyStack() went something wrong.\n");
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

	if(EmptyStack(stackArg) != stackArg){
		PRINTF("ERROR: EmptyStack() failed.\n");
		return -2;
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

	if (root==NULL){
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

		//When the current becomes NULL after moving to left child.
		current = Pop(left_Stack);

		while(j){
			Push(right_Stack, current);
			current = current->right;

			if (current != NULL)
				break;

			//When the current becomes NULL after moving to right child.
			current = Pop(DFS_Stack);
			Pop(right_Stack);

			if (current == NULL){
				PRINTF("ERROR: Something went wrong.\n");
				return -2;
			}

			while(k){
				free(current);

				current = Pop(DFS_Stack);
				
				if (current == NULL){
					i=0;
					j=0;
					break;
				}

				if (left_Stack->end != NULL){
					if (current == left_Stack->end->data){
						Pop(left_Stack);
						break;
					}
				}

				if (right_Stack->end != NULL){
					if (current == right_Stack->end->data){
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
