#include "mylib.h"
#include "test.h"

int UnitTest_Stack(void)
{
	int err;
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
	
	Push(myStack, &node01, TRIED_LEFT);
	Push(myStack, &node02, TRIED_RIGHT);
	Push(myStack, &node03, TRIED_LEFT);
	Push(myStack, &node04, TRIED_RIGHT);
	Push(myStack, &node05, TRIED_LEFT);
	EmptyStack(myStack);

	if(Pop(myStack) != NULL){
		PRINTF("Unit test Fail.\n");
		return -8;
	}

	if(err=RemoveStack(myStack) != 0){
		PRINTF("Unit test Fail. Err=%d\n", err);
		return -9;
	}
	
	return 0;
}

int UnitTest_HeightFind(void)
{
	BTREE_NODE *root = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root2 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root3 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root4 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root5 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root6 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	BTREE_NODE *root7 = (BTREE_NODE *)malloc(sizeof(BTREE_NODE));
	
	root->data = 1;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, LEFT , 4, 4);
	MakeChild(root->left->left, LEFT , 5, 5);
	MakeChild(root->left->left->left, LEFT, 6, 6);
	if (Calc_Btree_Height_DFS(root) != 5){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root2->data = 1;
	MakeChild(root2, RIGHT, 2, 2);
	if (Calc_Btree_Height_DFS(root2) != 2){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root3->data = 1;
	MakeChild(root3, BOTH, 2, 3);
	if (Calc_Btree_Height_DFS(root3) != 2){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root4->data = 1;
	MakeChild(root4, BOTH, 2, 3);
	MakeChild(root4->right, LEFT, 4, 4);
	if (Calc_Btree_Height_DFS(root4) != 3){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root5->data = 1;
	MakeChild(root5, BOTH, 2, 3);
	MakeChild(root5->right, BOTH, 4, 5);
	if (Calc_Btree_Height_DFS(root5) != 3){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root6->data = 1;
	MakeChild(root6, BOTH, 2, 3);
	MakeChild(root6->right, BOTH, 4, 5);
	MakeChild(root6->right->left, BOTH, 6, 7);
	if (Calc_Btree_Height_DFS(root6) != 4){
		PRINTF("Unit test Fail.\n");
		return -1;
	}

	root7->data = 1;
	MakeChild(root7, BOTH, 2, 3);
	MakeChild(root7->right, BOTH, 4, 5);
	MakeChild(root7->left, RIGHT, 6, 6);
	MakeChild(root7->left->right, BOTH, 7, 8);
	if (Calc_Btree_Height_DFS(root7) != 4){
		PRINTF("Unit test Fail.\n");
		return -1;
	}
	
	return 0;
}
