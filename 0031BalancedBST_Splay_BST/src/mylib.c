#include "mylib.h"

//Function Definitions
////SPLAY BST Operations
SPLAY_BST *Create_SplayBST(void);
SPLAY_BST *Insert_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *Search_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST *Delete_SplayBST(SPLAY_BST *BST, int value);
int Remove_SplayBST(SPLAY_BST *BST);

////Building Blocks for SPLAY BST Operations
SPLAY_BST_NODE *Insert_BST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *Search_BST(SPLAY_BST *BST, int value);
SPLAY_BST *Delete_BST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *RotateLeft(SPLAY_BST *BST, SPLAY_BST_NODE *node);
SPLAY_BST_NODE *RotateRight(SPLAY_BST *BST, SPLAY_BST_NODE *node);

////Circular Deque Operations
CIRCULAR_DEQUE *CreateDeque(void)
{
	CIRCULAR_DEQUE *ret = (CIRCULAR_DEQUE *)malloc(sizeof(CIRCULAR_DEQUE));
	ret->begin = -1;
	ret->end = -1;
	return ret;
}

CIRCULAR_DEQUE *PushLeft(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE *inputArg)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (inputArg==NULL){
		PRINTF("ERROR: inputArg is NULL.\n");
		return NULL;
	}

	//When the Deque is empty
	if (Deque->begin==-1 && Deque->end==-1){
		Deque->begin = 0;
		Deque->end = 0;
		(Deque->dequeArray)[Deque->begin] = inputArg;
		return Deque;
	}

	//When the Deque is full.
	if ((Deque->end + 1 == Deque->begin)||(Deque->end==DEQUE_MAX-1 && Deque->begin==0))
		return NULL;

	//Other remaining cases.
	Deque->begin -= 1;

	if (Deque->begin == -1)
		Deque->begin = DEQUE_MAX-1;

	(Deque->dequeArray)[Deque->begin] = inputArg;
	return Deque;
}

CIRCULAR_DEQUE *PopLeft(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE **outputStore)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (outputStore==NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1)
		return NULL;

	//When the Deque has only one element.
	if (Deque->begin == Deque->end){
		*outputStore = (Deque->dequeArray)[Deque->begin];
		Deque->begin = -1;
		Deque->end = -1;
		return Deque;
	}

	//Other remaining cases.
	*outputStore = (Deque->dequeArray)[Deque->begin];
	
	Deque->begin += 1;
	
	if (Deque->begin==DEQUE_MAX)
		Deque->begin = 0;

	return Deque;
}

CIRCULAR_DEQUE *PushRight(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE *inputArg)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (inputArg==NULL){
		PRINTF("ERROR: inputArg is NULL.\n");
		return NULL;
	}
	
	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1){
		Deque->begin=0;
		Deque->end=0;
		(Deque->dequeArray)[Deque->end] = inputArg;
		return Deque;
	}

	//When the Deque is full.
	if (Deque->end+1==Deque->begin || (Deque->end==DEQUE_MAX-1 && Deque->begin==0))
		return NULL;

	//Other remaining cases.
	Deque->end += 1;
	
	if (Deque->end == DEQUE_MAX)
		Deque->end = 0;

	(Deque->dequeArray)[Deque->end] = inputArg;
	return Deque;
}

CIRCULAR_DEQUE *PopRight(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE **outputStore)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (outputStore==NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1)
		return NULL;
	
	//When the Deque has only one element.
	if (Deque->begin == Deque->end){
		*outputStore = (Deque->dequeArray)[Deque->end];
		Deque->begin = -1;
		Deque->end = -1;
		return Deque;
	}

	//Other remaining cases.
	*outputStore = (Deque->dequeArray)[Deque->end];
	
	Deque->end -= 1;

	if (Deque->end==-1)
		Deque->end = DEQUE_MAX-1;

	return Deque;
}

int RemoveDeque(CIRCULAR_DEQUE *Deque)
{
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return -1;
	}

	free(Deque);

	return 0;
}
