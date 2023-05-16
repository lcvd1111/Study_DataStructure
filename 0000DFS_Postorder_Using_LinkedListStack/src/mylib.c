#include "../include/mylib.h"
#include <stdio.h>
#include <stdlib.h>

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	switch (selector){
	case NONE:
		break;
	case LEFT:
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:	
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	default:
		PRINTF("Error. Wrong selector for MakeChild( ).\n");
		return NULL;
	}
	return parent;
}

BINTREE_NODE *Post_order_Traversal(BINTREE_NODE *root)
{
	STACK myStack;
	BINTREE_NODE *current = NULL;
	STACK_NODE_DATA buffer;
	myStack.begin = NULL;
	myStack.end = NULL;

	current = root;

	while(1){
		if (current != NULL){
			Push(&myStack, current, TRIED_LEFT);
			current = current->left;
			continue;
		}
		else if (current == NULL){
			if(Pop(&myStack, &buffer) == NULL){
				printf("Traversal completed.\n");
				return root;
			}
			current = buffer.data_Address;

			switch(buffer.data_Action){
				case TRIED_LEFT:
					Push(&myStack, current, TRIED_RIGHT);
					current = current->right;
					continue;
					break;
				case TRIED_RIGHT:
					printf("Visit Check: %d\n", current->data);	
					current = NULL;
					continue;
					break;
				default:
					PRINTF("Error Occured.\n");
					return NULL;
			}
		}
	}
}

int CleanBintree(BINTREE_NODE *root)
{
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg, LAST_ACTION action)
{
	/* When the stack is empty */
	if (stackArg->begin == NULL){
			stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
			(stackArg->begin->structData).data_Address = bintreeArg;
			(stackArg->begin->structData).data_Action = action;
			stackArg->begin->next = NULL;
			stackArg->end = stackArg->begin;
			return stackArg;
	}

	/* When the stack is not empty */
	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end = stackArg->end->next;
	(stackArg->end->structData).data_Address = bintreeArg;
	(stackArg->end->structData).data_Action = action;
	stackArg->end->next = NULL;
	
	return stackArg;
}

STACK_NODE_DATA *Pop(STACK *stackArg, STACK_NODE_DATA* dest)
{
	STACK_NODE *buf = NULL;

	/* When the wrong argument is inputted */
	if (dest == NULL){
		PRINTF("Error. NULL is inputted.\n");
		return NULL;
	}

	/* When the stack is empty */
	if (stackArg->begin == NULL){
		return NULL;
	}

	dest->data_Address = (stackArg->end->structData).data_Address;
	dest->data_Action = (stackArg->end->structData).data_Action;
	
	/* When the stack has only an one element */
	if (stackArg->begin == stackArg->end){
			free(stackArg->end);
			stackArg->begin = NULL;
			stackArg->end = NULL;
			return dest;
	}

	/* When the stack has elements more than one */
	buf = stackArg->begin;
	while (buf->next != stackArg->end){
			buf = buf->next;
	}
	free(stackArg->end);
	stackArg->end = buf;
	return dest;
}

STACK *CleanStack(STACK *stackArg)
{
		STACK_NODE_DATA dummy;
		while(Pop(stackArg, &dummy) != NULL){
				;
		}
}
