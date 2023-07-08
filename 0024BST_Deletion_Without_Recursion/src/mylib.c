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
		stackArg->end = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->begin = stackArg->end;
		stackArg->end->data = binArg;
		stackArg->end->prev = NULL;
		stackArg->end->next = NULL;
		return stackArg;
	}

	if (stackArg->end->next != NULL){
		PRINTF("ERROR: stackAg->ned->next != NULL.\n");
		return NULL;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end->next->data = binArg;
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next->next = NULL;
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
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (stackArg->begin == NULL && stackArg->end == NULL)
		return stackArg;

	while(Pop(stackArg))
		;

	if (stackArg->begin != NULL || stackArg->end != NULL){
		PRINTF("ERROR: Something went wrong.\n");
		return NULL;
	}

	return stackArg;
}

int DeleteStack(STACK *stackArg)
{
	if (EmptyStack(stackArg) == NULL){
		PRINTF("ERROR: EmptyStack( ) failed.\n");
		return -1;
	}

	free(stackArg);

	return 0;
}

BINTREE_NODE *Search(BINTREE_NODE *root, int key)
{
	BINTREE_NODE *current = NULL;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	current = root;

	while(1){
		if (current->number > key){
			if (current->left == NULL){
				current = NULL;
				break;
			}
			current = current->left;
			continue;
		}
		else if (current->number < key){
			if (current->right == NULL){
				current = NULL;
				break;
			}
			current = current->right;
			continue;
		}
		else if (current->number == key){
			break;
		}
		else{
			PRINTF("ERROR: Something went wrong.\n");
			return NULL;
		}
	}

	return current;
}

BINTREE_NODE *Insert(BINTREE_NODE *root, int keyArg, const char *keyStr)
{
	BINTREE_NODE *current = NULL;
	int direction = 0;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (Search(root, keyArg)){
		//When the key already exists in the given BST.
		return NULL;
	}

	current = root;

	while(1){
		if (current->number < keyArg){
			if (current->right == NULL){
				direction = 1;
				break;
			}
			current = current->right;
		}
		else if (current->number > keyArg){
			if (current->left == NULL){
				direction = 2;
				break;
			}
			current = current->left;
		}
		else if (current->number == keyArg){
			PRINTF("ERROR: key already exists in the given BST. But it failed to check it.\n");
			return NULL;
		}
		else {
			PRINTF("ERROR: Something went wrong.\n");
			return NULL;
		}
	}
	
	switch(direction){
	case 1:
		if (current->right != NULL){
			PRINTF("ERROR: current->right is not NULL.\n");
			return NULL;
		}
		current->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		current->right->number = keyArg;
		strncpy(current->right->name, keyStr, NAME_MAX);
		current->right->left = NULL;
		current->right->right = NULL;
		break;
	case 2:
		if (current->left != NULL){
			PRINTF("ERROR: current->left is not NULL.\n");
			return NULL;
		}
		current->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		current->left->number = keyArg;
		strncpy(current->left->name, keyStr, NAME_MAX);
		current->left->left = NULL;
		current->left->right = NULL;
		break;
	default:
		PRINTF("ERROR: Something went wrong.\n");
		return NULL;
	}

	return root;
}

BINTREE_NODE *Delete(BINTREE_NODE *root, int key)
{
	BINTREE_NODE *current = NULL;
	BINTREE_NODE *parent = NULL;
	BINTREE_NODE *successor = NULL;
	BINTREE_NODE *successor_parent = NULL;
	BINTREE_NODE *ret = NULL;
	int direction = 0;

	if (Search(root, key)==NULL){
		return NULL;
	}

	current = root;

	while(1){
		if (current->number > key){
			parent = current;
			current = current->left;
			direction = 1;
			continue;
		}
		else if (current->number < key){
			parent = current;
			current = current->right;
			direction = 2;
			continue;
		}
		else if (current->number == key){
			break;
		}
		else {
			PRINTF("ERROR: Something went wrong.\n");
			return NULL;
		}
	}

	if (current->left==NULL || current->right==NULL){
		if (current == root){
			if (current->left == NULL){
				ret = root->right;
				free(root);
				return ret;
			}

			ret = root->left;
			free(root);
			return ret;
		}
		
		if (current->left == NULL){
			if (direction == 1){
				parent->left = current->right;
				free(current);
				return root;
			}

			if (direction != 2){
				PRINTF("ERROR: Something went wrong.\n");
				return NULL;
			}

			parent->right = current->right;
			free(current);
			return root;
		}

		if (direction == 1){
			parent->left = current->left;
			free(current);
			return root;
		}

		if (direction != 2){
			PRINTF("ERROR: Something went wrong.\n");
			return NULL;
		}

		parent->right = current->left;
		free(current);
		return root;
	}

	//When the current has both left and right children.
	successor_parent = current;
	successor = current->right;

	while(successor->left != NULL){
		successor_parent = successor;
		successor = successor->left;
	}

	current->number = successor->number;
	strncpy(current->name, successor->name, NAME_MAX);

	if (successor->right == NULL){
		if (successor_parent == current){
			current->right = NULL;
			free(successor);
			return root;
		}

		successor_parent->left = NULL;
		free(successor);
		return root;
	}

	if (successor_parent == current){
		current->right = successor->right;
		free(successor);
		return root;
	}

	successor_parent->left = successor->right;
	free(successor);
	return root;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK *DFS_Stack, *left_Stack, *right_Stack;
	int i=1, j=1, k=1;

	DFS_Stack = CreateStack();
	left_Stack = CreateStack();
	right_Stack = CreateStack();

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return -1;
	}

	current = root;

	while(i){
		Push(DFS_Stack, current);
		Push(left_Stack, current);

		current = current->left;

		if (current != NULL)
			continue;

		//When the current is NULL after moving to left.
		current = Pop(left_Stack);
		Pop(DFS_Stack);

		while(j){
			Push(right_Stack, current);
			Push(DFS_Stack, current);
			current = current->right;
			
			if (current != NULL)
				break;

			//When the curren is NULL after moving to right.
			current = Pop(right_Stack);
			Pop(DFS_Stack);

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
