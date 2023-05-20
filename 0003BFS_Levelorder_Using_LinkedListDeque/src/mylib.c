#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>

//FUNCTION DEFINITIONS
BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL\n");
		return NULL;
	}

	switch (selector){
	case NONE:
		break;
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: Parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR: malloc() failed.\n");
			return NULL;
		}

		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: Parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR: malloc() failed.\n");
			return NULL;
		}

		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;

		break;
	case BOTH:
		if ((parent->left != NULL)||(parent->right != NULL)){
			PRINTF("ERROR: Parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if ((parent->left == NULL)||(parent->right == NULL)){
			PRINTF("ERROR: malloc() failed.\n");
			return NULL;
		}

		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return NULL;
		break;
	}

	return parent;
}

int LevelOrder(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	DEQUE myDeque = {.begin=NULL, .end=NULL};
	int emptyFlag = 0;

	current = root;

	while(1){
		if (current != NULL){
			printf("Visit Check: %d\n", current->data);
			InsertLeft(&myDeque, current->left);
			InsertLeft(&myDeque, current->right);
			current = DeleteRight(&myDeque, &emptyFlag);
			if ((current == NULL)&&(emptyFlag == 1)){
				printf("Traversal Compelted.\n");
				return 0;
			}
			continue;
		}
		else if (current == NULL){
			current = DeleteRight(&myDeque, &emptyFlag);
			if ((current == NULL)&&(emptyFlag == 1)){
				printf("Traversal Completed.\n");
				return 0;
			}
			continue;
		}
	}
}

int EmptyBintree(BINTREE_NODE *root)
{
	;
}

DEQUE *InsertLeft(DEQUE *dequeArg, BINTREE_NODE *bintreeArg)
{
	if (dequeArg->begin == NULL){
		if ((dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE))) == NULL){
			PRINTF("ERROR: malloc() failed.\n");
			return NULL;
		}
		dequeArg->begin->data = bintreeArg;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		dequeArg->end = dequeArg->begin;
		return dequeArg;
	}

	if ((dequeArg->begin->prev = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE))) == NULL){
		PRINTF("ERROR: malloc() failed.\n");
		return NULL;
	}
	dequeArg->begin->prev->data = bintreeArg;
	dequeArg->begin->prev->prev = NULL;
	dequeArg->begin->prev->next = dequeArg->begin;
	dequeArg->begin = dequeArg->begin->prev;

	return dequeArg;

}

BINTREE_NODE *DeleteLeft(DEQUE *dequeArg, int *emptyFlag)
{
	BINTREE_NODE *ret = NULL;
	DEQUE_NODE *buf;

	if (dequeArg->begin == NULL){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return NULL;
	}

	ret = dequeArg->begin->data;
	buf = dequeArg->begin->next;
	free(dequeArg->begin);
	dequeArg->begin = buf;

	if (buf==NULL)
		dequeArg->end = buf;

	return ret;
}

DEQUE *InsertRight(DEQUE *dequeArg, BINTREE_NODE *bintreeArg)
{
	if (dequeArg->begin == NULL){
		if ((dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE))) == NULL){
			PRINTF("ERROR: malloc() failed.\n");
			return NULL;
		}
		dequeArg->begin->data = bintreeArg;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		dequeArg->end = dequeArg->begin;
		return dequeArg;
	}

	if ((dequeArg->end->next = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE))) == NULL){
		PRINTF("ERROR: malloc() failed.\n");
		return NULL;
	}
	dequeArg->end->next->data = bintreeArg;
	dequeArg->end->next->prev = dequeArg->end;
	dequeArg->end->next->next = NULL;
	dequeArg->end = dequeArg->end->next;

	return dequeArg;
}

BINTREE_NODE *DeleteRight(DEQUE *dequeArg, int *emptyFlag)
{
	BINTREE_NODE *ret = NULL;
	DEQUE_NODE *buf = NULL;

	if(dequeArg->begin == NULL){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return NULL;
	}

	ret = dequeArg->end->data;
	buf = dequeArg->end->prev;
	free(dequeArg->end);
	dequeArg->end = buf;
	
	if(buf == NULL)
		dequeArg->begin = buf;

	return ret;
}

DEQUE *EmptyDeque(DEQUE *dequeArg)
{
	while(dequeArg->begin != NULL)
		DeleteRight(dequeArg, NULL);

	return dequeArg;
}

