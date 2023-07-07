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
	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg)
{
	stackArg;
}

STACK *EmptyStack(STACK *stackArg)
{
	return stackArg;
}

int *DeleteStack(STACK *stackArg)
{
	return 0;
}

BINTREE_NODE *Search(BINTREE_NODE *root, int key)
{
	return root;
}

BINTREE_NODE *Insert(BINTREE_NODE *root, int keyArg, const char *keyStr)
{
	return root;
}

BINTREE_NODE *Delete(BINTREE_NODE *root, int key)
{
	return root;
}

int DeleteBintree(BINTREE_NODE *root)
{
	return 0;
}
