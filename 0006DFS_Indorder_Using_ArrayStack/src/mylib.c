#include "mylib.h"

//Function Definitions
STACK *CreateStack(uint32_t num)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	ret->end = -1;
	ret->length = num;
	ret->stackArray = (BINTREE_NODE **)malloc(sizeof(BINTREE_NODE *)*num);

	for (int i = 0 ; i<num ; i++)
		(ret->stackArray)[i] = NULL;

	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *bintreeArg, int *fullFlag)
{
	if (stackArg==NULL){
		PRINTF("ERROR. STACK * argument is NULL.\n");
		return NULL;
	}

	if (stackArg->end == (stackArg->length)-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
		return NULL;
	}

	(stackArg->end)++;

	(stackArg->stackArray)[stackArg->end] = bintreeArg;

	if (stackArg->end == (stackArg->length)-1){
		if (fullFlag != NULL)
			*fullFlag = 1;
	}
	else {
		if (fullFlag != NULL)
			*fullFlag = 0;
	}
	
	return stackArg;
}

BINTREE_NODE *Pop(STACK *stackArg, int *emptyFlag)
{
	BINTREE_NODE *ret = NULL;

	if (stackArg==NULL){
		PRINTF("ERROR. STACK * argument is NULL.\n");
		return NULL;
	}

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
		return NULL;
	}
	
	ret = (stackArg->stackArray)[stackArg->end];
	(stackArg->stackArray)[stackArg->end] = NULL;
	(stackArg->end)--;

	if (stackArg->end == -1){
		if (emptyFlag != NULL)
			*emptyFlag = 1;
	}
	else {
		if (emptyFlag != NULL)
			*emptyFlag =0;
	}

	return ret;
}

STACK *CleanStack(STACK *stackArg)
{
	BINTREE_NODE **buf = stackArg->stackArray;

	while(Pop(stackArg, NULL) != NULL)
		;
	return stackArg;
}

STACK *RemoveStack(STACK *stackArg){

	if (stackArg == NULL)
		return NULL;

	CleanStack(stackArg);
	free(stackArg);

	return NULL;
}
