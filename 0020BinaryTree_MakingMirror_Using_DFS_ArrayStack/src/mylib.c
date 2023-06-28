#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg)
{
	if (stackArg==NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (binArg == NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	return ret;
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

	return parent;
}

BINTREE_NODE *MakeMirror(BINTREE_NODE *root)
{
	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->left == NULL && root->right == NULL){
		return root;
	}

}

int DeleteBintree(BINTREE_NODE *root)
{
	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return -1;
	}

	if (root->left == NULL && root->right == NULL){
		free(root);
		return 0;
	}

	return 0;
}
