#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

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
			if (parent->left != NULL){
				PRINTF("ERROR. Child already exists.\n");
				return NULL;
			}
			parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			parent->left->data = leftArg;
			parent->left->left = NULL;
			parent->left->right = NULL;
			break;
		case RIGHT:
			if (parent->right != NULL){
				PRINTF("ERROR. Child already exists.\n");
				return NULL;
			}
			parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			parent->right->data = rightArg;
			parent->right->left = NULL;
			parent->right->right = NULL;
			break;
		case BOTH:
			if ((parent->left != NULL)||(parent->right != NULL)){
				PRINTF("ERROR. Child already exists.\n");
				return NULL;
			}
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
	BINTREE_NODE *current = root;
	STACK traversalStack = {.begin=NULL, .end=NULL};
	
	while(1){
		if (current != NULL){
			printf("Visit Check: %d\n", current->data);
			Push(&traversalStack, current);
			current = current->left;
			continue;
		}
		else if (current == NULL){
			current = Pop(&traversalStack);
			if (current == NULL){
				printf("Traversal Completed!\n");
				ret = 0;
				break;
			}
			current = current->right;
			continue;
		}
	}
	return ret;
}

int PreorderTraverse_Recursive(BINTREE_NODE *root)
{
	//Base Case. Findishing the recursive calling.
	if (root == NULL)
		return 0;

	//Visit Check.
	printf("Visit Check: %d\n", root->data);

	PreorderTraverse_Recursive(root->left);

	PreorderTraverse_Recursive(root->right);
}

int CleanBintree(BINTREE_NODE *root)
{	
	int ret = 0;
	BINTREE_NODE *current = root;
	STACK traversalStack = {.begin=NULL, .end=NULL};
	STACK outputStack = {.begin=NULL, .end=NULL};
	
	while(1){
		if (current != NULL){
			Push(&outputStack, current);
			Push(&traversalStack, current);
			current = current->left;
			continue;
		}
		else if (current == NULL){
			current = Pop(&traversalStack);
			if (current == NULL){
				CleanStack(&traversalStack);
				break;
			}
			current = current->right;
			continue;
		}
	}

	while((current = Pop(&outputStack)) != NULL){
		free(current);
	}

	CleanStack(&outputStack);
	
	printf("Cleaning binary tree completed.\n");
	return 0;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg)
{
	if (stackArg->begin == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		if (stackArg->begin == NULL){
			PRINTF("Error. malloc fail.\n");
			return NULL;
		}
		stackArg->end = stackArg->begin;
		stackArg->begin->data = bintreeArg;
		stackArg->begin->next = NULL;
		return stackArg;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	if (stackArg->end->next == NULL){
		PRINTF("Error. malloc fail.\n");
		return NULL;
	}
	stackArg->end->next->data = bintreeArg;
	stackArg->end->next->next = NULL;
	stackArg->end = stackArg->end->next;

	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret;
	STACK_NODE *buf;

	if (stackArg->begin == NULL){
		return NULL;
	}

	ret = stackArg->end->data;

	if (stackArg->begin == stackArg->end){
		free(stackArg->end);
		stackArg->end = NULL;
		stackArg->begin = NULL;
		return ret;
	}

	buf = stackArg->begin;
	while (buf->next != stackArg->end)
		buf = buf->next;
	free(stackArg->end);
	stackArg->end = buf;
	
	return ret;
}

STACK *CleanStack(STACK *stackArg)
{
	while(stackArg->begin != NULL)
		Pop(stackArg);

	return stackArg;
}
