#include "mylib.h"
#include "test.h"

int UnitTest_Stack(void)
{
	STACK *myStack = NULL;
	WRAPPED_NODE *popRet = NULL;
	BTREE_NODE node01, node02, node03, node04, node05;

	node01.data = 1;
	node02.data = 2;
	node03.data = 3;
	node04.data = 4;
	node05.data = 5;
	
	myStack = CreateStack();

	if(Pop(myStack) != NULL){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	Push(myStack, &node01, TRIED_LEFT);
	Push(myStack, &node02, TRIED_RIGHT);
	Push(myStack, &node03, TRIED_LEFT);
	Push(myStack, &node04, TRIED_RIGHT);
	Push(myStack, &node05, TRIED_LEFT);

	popRet = Pop(myStack);
	if (!(popRet->nodeAddress_W->data == 5 && popRet->lastTried_W == TRIED_LEFT)) {
		PRINTF("Unit test Fail.\n");
		return -2;
	}
	free(popRet);

	popRet = Pop(myStack);
	if (!(popRet->nodeAddress_W->data == 4 && popRet->lastTried_W == TRIED_RIGHT)){
		PRINTF("Unit test Fail.\n");
		return -3;
	}
	free(popRet);

	popRet = Pop(myStack);
	if (!(popRet->nodeAddress_W->data == 3 && popRet->lastTried_W == TRIED_LEFT)){
		PRINTF("Unit test Fail.\n");
		return -4;
	}
	free(popRet);

	popRet = Pop(myStack);
	if (!(popRet->nodeAddress_W->data == 2 && popRet->lastTried_W == TRIED_RIGHT)){
		PRINTF("Unit test Fail.\n");
		return -5;
	}
	free(popRet);

	popRet = Pop(myStack);
	if (!(popRet->nodeAddress_W->data == 1 && popRet->lastTried_W == TRIED_LEFT)){
		PRINTF("Unit test Fail.\n");
		return -6;
	}
	free(popRet);

	if(Pop(myStack) != NULL){
		PRINTF("Unit test Fail.\n");
		return -7;
	}
	
	return 0;
}

int UnitTest_HeightFild(void)
{
	return 0;
}
