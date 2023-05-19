#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>


BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECT selector, int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR. parent is NULL.\n");
		return NULL;
	}

	switch(selector)
	{
	case NONE:
		break;
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR. Parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR. malloc() Failed.\n");
			return NULL;
		}
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR. Parent already has a child.\n");
			return NULL;
		}
		
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR. malloc() Failed.\n");
			return NULL;
		}
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if ((parent->left != NULL)||(parent->right != NULL)){
			PRINTF("ERROR. Parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR. malloc() Failed.\n");
			return NULL;
		}
		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR. malloc() Failed.\n");
			return NULL;
		}
		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;

		break;
	default:
		PRINTF("Error. Wrong selector.\n");
		return NULL;
		break;
	}

	return parent;
}

BINTREE_NODE *InorderTraverse(BINTREE_NODE *rootNode)
{
	return rootNode;
}

BINTREE_NODE *CleanBintree(BINTREE_NODE *rootNode)
{
	return rootNode;
}


STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg)
{
	if (stackArg->begin == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		if (stackArg->begin==NULL){
			PRINTF("Error. malloc() Fail.\n");
			return NULL;
		}
		stackArg->begin->data = bintreeArg;
		stackArg->begin->next = NULL;
		stackArg->end = stackArg->begin;
		return stackArg;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	
	stackArg->end->next->data = bintreeArg;
	stackArg->end->next->next = NULL;
	stackArg->end = stackArg->end->next;

	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret = NULL;
	STACK_NODE *buf = NULL;

	if (stackArg->begin == NULL)
		return NULL;

	ret = stackArg->end->data;

	if (stackArg->end == stackArg->begin){
		free(stackArg->end);
		stackArg->end = NULL;
		stackArg->begin = NULL;
		return ret;
	}

	buf = stackArg->begin;

	while(buf->next != stackArg->end){
		buf = buf->next;
	}

	free(stackArg->end);
	stackArg->end = buf;
	stackArg->end->next = NULL;

	return ret;
}

STACK *CleanStack(STACK *stackArg)
{
	while(stackArg->begin != NULL);
		Pop(stackArg);

	return stackArg;
}

