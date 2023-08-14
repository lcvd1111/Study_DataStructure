#include "test.h"

//Function Definitions
int UnitTest_Deque(void)
{
	SPLAY_BST_NODE testNode[DEQUE_MAX];
	DEQUE *testDeque = NULL;
	testDeque = CreateDeque();
	SPLAY_BST_NODE *popOutput = NULL;
	
	for (int i=0 ; i<DEQUE_MAX ; i++)
		testNode[i].data = i;

	if (PopLeft(testDeque, &popOutput) != NULL){
		return -1;
	}

	if (PopRight(testDeque, &popOutput) != NULL){
		return -2;
	}

	for (int i=0; i<DEQUE_MAX ; i++){
		PushRight(testDeque, testNode + i);
		if (testDeque->end != i){
			return -3;
		}
	}

	if (PushRight(testDeque, testNode) != NULL)
		return -4;

	if (PushLeft(testDeque, testNode) != NULL)
		return -5;

	for (int i=0 ; i<DEQUE_MAX-1 ; i++){
		if (testDeque->begin != i)
			return -6;
		PopLeft(testDeque, &popOutput);
		if (popOutput->data != i)
			return -7;
		if (testDeque->begin != i+1)
			return -8;
	}

	PopLeft(testDeque, &popOutput);
	if (popOutput->data != 255)
		return -9;

	if (testDeque->begin != -1 || testDeque->end != -1)
		return -10;


	RemoveDeque(testDeque);

	return 0;
}
int UnitTest_BST(void);
int UnitTest_SplayBST(void);
