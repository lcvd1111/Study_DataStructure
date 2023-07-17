#include "test.h"

int UnitTest_Deque(void)
{
	DEQUE *testDeque = CreateDeque();
	BINTREE_NODE a={1,}, b={2,}, c={3,}, d={4,};

	if (testDeque->begin != NULL || testDeque->end != NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}
	PushRight(testDeque, &a);
	PushRight(testDeque, &b);
	PushRight(testDeque, &c);
	PushRight(testDeque, &d);

	if (PopRight(testDeque)->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (PopRight(testDeque)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (PopRight(testDeque)->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (PopRight(testDeque)->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (PopRight(testDeque) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	PushLeft(testDeque, &d);
	PushLeft(testDeque, &c);
	PushLeft(testDeque, &b);
	PushLeft(testDeque, &a);
	
	if (PopLeft(testDeque)->data != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (PopLeft(testDeque)->data != 2){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (PopLeft(testDeque)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (PopLeft(testDeque)->data != 4){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (PopLeft(testDeque) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (DeleteDeque(testDeque)){
		PRINTF("Unit Test Failed.\n");
	}

	return 0;
}

int UnitTest_BST(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 50;
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 37);
	Insert(testRoot, 97);
	Insert(testRoot, 66);
	Insert(testRoot, 85);
	Insert(testRoot, 300);
	Insert(testRoot, 3);
	Insert(testRoot, 17);
	Insert(testRoot, 25);
	Insert(testRoot, 61);
	Insert(testRoot, 45);
	Insert(testRoot, 77);

	if (testRoot->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (testRoot->left->data != 37){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->right->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->left->left->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}
	if (testRoot->left->right->data != 45){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}
	if (testRoot->right->left->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}
	if (testRoot->right->right->data != 300){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}
	if (testRoot->left->left->right->data != 17){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->right->left->left->data != 61){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testRoot->right->left->right->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->left->left->right->right->data != 25){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (testRoot->right->left->right->left->data != 77){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}
	
	if(DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	return 0;
}

int UnitTest_CopyBintree(void)
{
	BINTREE_NODE *testRoot = NULL;
	BINTREE_NODE *testRoot2 = NULL;

	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 50;
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 37);
	Insert(testRoot, 97);
	Insert(testRoot, 66);
	Insert(testRoot, 85);
	Insert(testRoot, 300);
	Insert(testRoot, 3);
	Insert(testRoot, 17);
	Insert(testRoot, 25);
	Insert(testRoot, 61);
	Insert(testRoot, 45);
	Insert(testRoot, 77);

PRINTF("JYJO DEBUG\n");
	testRoot2 = CopyBintree(testRoot);
PRINTF("JYJO DEBUG\n");

	if(DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
	}

PRINTF("JYJO DEBUG\n");
	if (testRoot2->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

PRINTF("JYJO DEBUG\n");
	if (testRoot2->left->data != 37){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot2->right->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot2->left->left->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}
	if (testRoot2->left->right->data != 45){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}
	if (testRoot2->right->left->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}
	if (testRoot2->right->right->data != 300){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}
	if (testRoot2->left->left->right->data != 17){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot2->right->left->left->data != 61){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testRoot2->right->left->right->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot2->left->left->right->right->data != 25){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (testRoot2->right->left->right->left->data != 77){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}
	
	if(DeleteBintree(testRoot2)){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	return 0;
}

int UnitTest_DFSandBFS(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->data = 50;
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 37);
	Insert(testRoot, 97);
	Insert(testRoot, 66);
	Insert(testRoot, 85);
	Insert(testRoot, 300);
	Insert(testRoot, 3);
	Insert(testRoot, 17);
	Insert(testRoot, 25);
	Insert(testRoot, 61);
	Insert(testRoot, 45);
	Insert(testRoot, 77);

	if(DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
	}
	return 0;
}

int UnitTest_CreateThreaded(void)
{
	return 0;
}

int UnitTest_ThreadedTraverse(void)
{
	return 0;
}
