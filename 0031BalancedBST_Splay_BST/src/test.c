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

int UnitTest_BST(void)
{
	SPLAY_BST *testBST = Create_SplayBST();
	DEQUE *DFS_output = CreateDeque();
	SPLAY_BST_NODE *popOutput = NULL;

	if(Insert_BST(testBST, 50) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if(Insert_BST(testBST, 20) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -2;
	}

	if(Insert_BST(testBST, 10) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -3;
	}

	if(Insert_BST(testBST, 300) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -4;
	}

	if(Insert_BST(testBST, 250) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -5;
	}

	if(Insert_BST(testBST, 71) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -6;
	}

	if(Insert_BST(testBST, 130) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -7;
	}

	if(Insert_BST(testBST, 45) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -8;
	}

	if(Insert_BST(testBST, 68) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -9;
	}

	if(Insert_BST(testBST, 280) == NULL){
		PRINTF("Unit Test Fail.\n");
		return -10;
	}

	if(testBST != PreorderTraversal(testBST, DFS_output)){
		PRINTF("Unit Test Fail.\n");
		return -11;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -12;
	}

	if (popOutput->data != 50){
		PRINTF("Unit Test Fail.\n");
		return -13;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -14;
	}

	if (popOutput->data != 20){
		PRINTF("Unit Test Fail.\n");
		return -15;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -16;
	}

	if (popOutput->data != 10){
		PRINTF("Unit Test Fail.\n");
		return -17;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -18;
	}

	if (popOutput->data != 45){
		PRINTF("Unit Test Fail.\n");
		return -19;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -20;
	}

	if (popOutput->data != 300){
		PRINTF("Unit Test Fail.\n");
		return -21;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -22;
	}

	if (popOutput->data != 250){
		PRINTF("Unit Test Fail.\n");
		return -23;
	}
	
	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -24;
	}

	if (popOutput->data != 71){
		PRINTF("Unit Test Fail.\n");
		return -25;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -26;
	}

	if (popOutput->data != 68){
		PRINTF("Unit Test Fail.\n");
		return -27;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -28;
	}

	if (popOutput->data != 130){
		PRINTF("Unit Test Fail.\n");
		return -29;
	}

	if(PopLeft(DFS_output, &popOutput) != DFS_output){
		PRINTF("Unit Test Fail.\n");
		return -30;
	}

	if (popOutput->data != 280){
		PRINTF("Unit Test Fail.\n");
		return -31;
	}

	if(PopLeft(DFS_output, &popOutput) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -32;
	}

	if (Delete_BST(testBST, 9999) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -33;
	}

	if (Delete_BST(testBST, 250) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -34;
	}

	if (testBST->root->right->left->data != 130 
		|| testBST->root->right->left->left->data != 71
		|| testBST->root->right->left->right->data != 280
		|| testBST->root->right->left->right->left != NULL
		|| testBST->root->right->left->right->right != NULL
		|| testBST->root->right->left->left->left->data != 68
		|| testBST->root->right->left->left->right != NULL
		|| testBST->root->right->left->left->left->left != NULL
		|| testBST->root->right->left->left->left->right != NULL){
		PRINTF("Unit Test Fail.\n");
		return -35;
	}

	if (Delete_BST(testBST, 130) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -36;
	}

	if (testBST->root->right->left->data != 71
		|| testBST->root->right->right != NULL
		|| testBST->root->right->left->left->data != 68
		|| testBST->root->right->left->right->data != 280
		|| testBST->root->right->left->left->left != NULL
		|| testBST->root->right->left->left->right != NULL
		|| testBST->root->right->left->right->left != NULL
		|| testBST->root->right->left->right->right != NULL){
		PRINTF("Unit Test Fail.\n");
		return -37;
	}

	if (Delete_BST(testBST, 68) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -38;
	}

	if (Delete_BST(testBST, 280) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -39;
	}

	if (testBST->root->right->data != 300
		|| testBST->root->right->left->data != 71
		|| testBST->root->right->left->left != NULL
		|| testBST->root->right->left->right != NULL
		|| testBST->root->right->right != NULL){
		PRINTF("Unit Test Fail.\n");
	

		printf("%d %d %p %p %p\n"
				,testBST->root->right->data
				,testBST->root->right->left->data
				,testBST->root->right->left->left
				,testBST->root->right->left->right
				,testBST->root->right->right);

		return -40;
	}

	if (Delete_BST(testBST, 300) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -41;
	}

	if (testBST->root->right->left != NULL
		|| testBST->root->right->right != NULL
		|| testBST->root->right->data != 71){
		PRINTF("Unit Test Fail.\n");
		return -42;
	}

	if (Delete_BST(testBST, 50) != testBST){
		PRINTF("Unit Test Fail.\n");
		return -43;
	}

	if (testBST->root->right->data != 71){
		PRINTF("Unit Test Fail.\n");
		return -44;
	}

	if (testBST->root->right->left != NULL
		|| testBST->root->right->right != NULL){
		PRINTF("Unit Test Fail.\n");
		return -45;
	}

	if (Remove_SplayBST(testBST)){
		PRINTF("ERROR: Remove_SplayBST(testBST) failed.\n");
		return -9999;
	}

	if (RemoveDeque(DFS_output)){
		PRINTF("ERROR: RemoveDeque(DFS_output) failed.\n");
		return -8888;
	}

	return 0;
}
int UnitTest_SplayBST(void);
