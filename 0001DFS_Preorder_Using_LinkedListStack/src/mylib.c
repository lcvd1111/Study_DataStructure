#include <stdio.h>
#include <stdlib.h>
#include "../include/mylib.h"

//Function Definition
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector,int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("Error occured.\n");
		return NULL;
	}

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
			PRINTF("Error occured.\n");
			return NULL;
	}
	return parent;
}

int PreorderTraverse(BINTREE_NODE *root)
{
		int ret = 0;
		return ret;
}

int CleanBintree(BINTREE_NODE *root)
{
		int ret = 0;
		return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg)
{
		return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
		BINTREE_NODE *temp = NULL;
		return temp;
}

STACK *CleanStack(STACK *stackArg)
{
		return stackArg;
}
