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

	PushLeft(testDeque, testNode);
	for (int i=1 ; i<DEQUE_MAX ; i++){
		PushLeft(testDeque, testNode+i);
		
		if (testDeque->begin + i != DEQUE_MAX)
			return -11;
	}

	if (PushLeft(testDeque, testNode) != NULL)
		return -12;

	if (PushRight(testDeque, testNode) != NULL)
		return -13;

	for (int i=0 ; i<DEQUE_MAX-2 ; i++){
		if (testDeque->begin != i+1)
			return -14;
		PopLeft(testDeque, &popOutput);
		if (popOutput->data != DEQUE_MAX - 1 - i)
			return -15;
		if (testDeque->begin != i+2)
			return -16;
	}

	if (testDeque->begin != DEQUE_MAX-1 || testDeque->end != 0)
		return -17;

	if (PopLeft(testDeque, &popOutput) == NULL)
		return -18;

	if (popOutput->data != 1)
		return -19;

	if (testDeque->begin != 0 || testDeque->end != 0)
		return -20;

	if (PopLeft(testDeque, &popOutput) == NULL)
		return -21;

	if (popOutput->data != 0)
		return -22;

	if (PopLeft(testDeque, &popOutput) != NULL)
		return -23;

	if (PopRight(testDeque, &popOutput) != NULL)
		return -24;

	RemoveDeque(testDeque);

	return 0;
}

int UnitTest_BST(void);
int UnitTest_SplayBST(void);
