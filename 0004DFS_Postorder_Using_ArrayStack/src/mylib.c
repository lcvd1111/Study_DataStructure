#include "mylib.h"

//FUNCTION DEFINITIONS
STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg, LAST_ACTION actionArg, int *fullFlag)
{
	STACK_DATA **temp = stackArg->stack_Array;

	if (stackArg->end == STACK_MAX-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
		return NULL;
	}

	(stackArg->end) += 1;
	temp[stackArg->end] = (STACK_DATA *)malloc(sizeof(STACK_DATA));
	(temp[stackArg->end])->dataAddress = bintreeArg;
	(temp[stackArg->end])->dataAction = actionArg;

	if (stackArg->end == STACK_MAX-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
		return stackArg;
	}

	*fullFlag = 0;

	return stackArg;
}

STACK *Pop(STACK *stackArg, STACK_DATA *dest, int *emptyFlag)
{
	STACK_DATA **temp = stackArg->stack_Array;

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return NULL;
	}

	dest->dataAddress = (temp[stackArg->end])->dataAddress;
	dest->dataAction = (temp[stackArg->end])->dataAction;
	free(temp[stackArg->end]);
	temp[stackArg->end] = NULL;

	if (stackArg->end==0){
		(stackArg->end) -= 1;
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return stackArg;
	}

	(stackArg->end) -= 1;
	
	if (emptyFlag != NULL)
		*emptyFlag = 0;

	return stackArg;
}

STACK *EmptyStack(STACK *stackArg)
{
	STACK *ret = NULL;
	STACK_DATA buf;
	while( (ret = Pop(stackArg, &buf, NULL)) != NULL )
		;
	return stackArg;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR. parent is null.\n");
		return NULL;
	}

	switch (selector){
		case NONE:
			break;
		case LEFT:
			if (parent->left != NULL){
				PRINTF("ERROR. parent already has a child.\n");
				return NULL;
			}
			parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			if (parent->left == NULL){
				PRINTF("ERROR. malloc() failed.\n");
				return NULL;
			}
			parent->left->data = leftArg;
			parent->left->left = NULL;
			parent->left->right = NULL;
			break;
		case RIGHT:
			if (parent->right != NULL){
				PRINTF("ERROR. parent already has a child.\n");
				return NULL;
			}
			parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			if (parent->right == NULL){
				PRINTF("ERROR. malloc() failed.\n");
				return NULL;
			}
			parent->right->data = rightArg;
			parent->right->left = NULL;
			parent->right->right = NULL;
			break;
		case BOTH:
			if ((parent->left != NULL)||(parent->right != NULL)){
				PRINTF("ERROR. parent already has a child.\n");
				return NULL;
			}
			parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			if (parent->left == NULL){
				PRINTF("ERROR. malloc() failed.\n");
				return NULL;
			}
			parent->left->data = leftArg;
			parent->left->left = NULL;
			parent->left->right = NULL;
			
			parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			if (parent->right == NULL){
				PRINTF("ERROR. malloc() failed.\n");
				return NULL;
			}
			parent->right->data = rightArg;
			parent->right->left = NULL;
			parent->right->right = NULL;
			break;
		default:
			PRINTF("ERROR. Wrong selector value.\n");
			return NULL;
			break;
	}

	return parent;
}

int PostOrder(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK myStack;
	int emptyFlag;
	int fullFlag;
	STACK_DATA popBuffer;

	current = root;

	myStack.end = -1;
	for (int i=0 ; i<STACK_MAX ; i++){
		(myStack.stack_Array)[i] = NULL;
	}

	while(1){
		if (current != NULL){
			if (Push(&myStack, current, TRIED_LEFT, &fullFlag)==NULL){
				PRINTF("ERROR. Stack Overflow.\n");
				return -1;
			}
			current = current->left;
		}
		else if (current == NULL){
			if (Pop(&myStack, &popBuffer, &emptyFlag)==NULL){
				printf("Traversal Complete.\n");
				return 0;
			}
			current = popBuffer.dataAddress;
			switch(popBuffer.dataAction){
			case TRIED_LEFT:
				if (Push(&myStack, current, TRIED_RIGHT, &fullFlag)==NULL){
				PRINTF("ERROR. Stack Overflow.\n");
				return -1;
			}
			current = current->right;
				break;
			case TRIED_RIGHT:
				printf("Visit Check: %d\n", current->data);
				current = NULL;
				break;
			default:
				PRINTF("ERROR.\n");
				return -1;
				break;
			}
		}
	}

	EmptyStack(&myStack);

	return 0;
}
