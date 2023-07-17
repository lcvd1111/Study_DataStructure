#include "test.h"
#include <time.h>

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

	testRoot2 = CopyBintree(testRoot);

	if(DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
	}

	if (testRoot2->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

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
	DEQUE *outputDeque = NULL;

	outputDeque = CreateDeque();

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

	InorderTraverse(testRoot, outputDeque);

	if (PopLeft(outputDeque)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (PopLeft(outputDeque)->data != 17){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (PopLeft(outputDeque)->data != 25){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (PopLeft(outputDeque)->data != 37){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (PopLeft(outputDeque)->data != 45){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (PopLeft(outputDeque)->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (PopLeft(outputDeque)->data != 61){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (PopLeft(outputDeque)->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (PopLeft(outputDeque)->data != 77){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (PopLeft(outputDeque)->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (PopLeft(outputDeque)->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (PopLeft(outputDeque)->data != 300){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (PopLeft(outputDeque) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	LevelorderTraverse(testRoot, outputDeque);

	if (PopLeft(outputDeque)->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (PopLeft(outputDeque)->data != 37){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	if (PopLeft(outputDeque)->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	if (PopLeft(outputDeque)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if (PopLeft(outputDeque)->data != 45){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (PopLeft(outputDeque)->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	if (PopLeft(outputDeque)->data != 300){
		PRINTF("Unit Test Failed.\n");
		return -20;
	}

	if (PopLeft(outputDeque)->data != 17){
		PRINTF("Unit Test Failed.\n");
		return -21;
	}


	if (PopLeft(outputDeque)->data != 61){
		PRINTF("Unit Test Failed.\n");
		return -22;
	}


	if (PopLeft(outputDeque)->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -23;
	}


	if (PopLeft(outputDeque)->data != 25){
		PRINTF("Unit Test Failed.\n");
		return -24;
	}


	if (PopLeft(outputDeque)->data != 77){
		PRINTF("Unit Test Failed.\n");
		return -25;
	}


	if (PopLeft(outputDeque) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -26;
	}

	DeleteDeque(outputDeque);

	if(DeleteBintree(testRoot)){
		PRINTF("Unit Test Failed.\n");
		return -27;
	}

	return 0;
}

int UnitTest_CreateThreaded(void)
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

	MakeThreadedTree(testRoot);

	if (testRoot->left->right->threadFlag != 1){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (testRoot->left->right->right->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->left->left->right->right->threadFlag != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->left->left->right->right->right->data !=37){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->right->left->left->threadFlag != 1){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testRoot->right->left->left->right->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->right->left->right->threadFlag != 1){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (testRoot->right->left->right->right->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->right->left->right->left->threadFlag != 1){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testRoot->right->left->right->left->right->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (DeleteThreadedTree(testRoot)){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	return 0;
}

int UnitTest_ThreadedTraverse(void)
{
	BINTREE_NODE *testRoot = NULL;
	DEQUE *outputDeque = NULL;

	outputDeque = CreateDeque();

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

	MakeThreadedTree(testRoot);

	ThreadedTraverse(testRoot, outputDeque);

	if (PopLeft(outputDeque)->data != 3){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (PopLeft(outputDeque)->data != 17){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (PopLeft(outputDeque)->data != 25){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (PopLeft(outputDeque)->data != 37){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (PopLeft(outputDeque)->data != 45){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (PopLeft(outputDeque)->data != 50){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (PopLeft(outputDeque)->data != 61){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (PopLeft(outputDeque)->data != 66){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (PopLeft(outputDeque)->data != 77){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (PopLeft(outputDeque)->data != 85){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (PopLeft(outputDeque)->data != 97){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (PopLeft(outputDeque)->data != 300){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (PopLeft(outputDeque) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (DeleteThreadedTree(testRoot)){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	return 0;
}

int UnitTest_TimeCompare(void)
{
	clock_t start, end;
	long interval1 = 0, interval2 = 0;
	BINTREE_NODE *testRoot = NULL;
	BINTREE_NODE *testRoot2 = NULL;
	DEQUE *outputDeque = NULL;

	outputDeque = CreateDeque();

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
	Insert(testRoot, 9000);
	Insert(testRoot, 4500);
	Insert(testRoot, 1);
	Insert(testRoot, 14);
	Insert(testRoot, 3726);
	Insert(testRoot, 142);
	Insert(testRoot, 24);
	Insert(testRoot, 708);
	Insert(testRoot, 23);
	Insert(testRoot, 123);
	Insert(testRoot, 500);
	Insert(testRoot, 999);
	Insert(testRoot, 19);
	Insert(testRoot, 2);
	Insert(testRoot, 4);
	Insert(testRoot, 5);
	Insert(testRoot, 51);
	Insert(testRoot, 54);
	Insert(testRoot, 800);
	testRoot2 = CopyBintree(testRoot);
	MakeThreadedTree(testRoot2);

	start = clock();
	InorderTraverse(testRoot, outputDeque);
	end = clock();
	interval1 = end - start;

	start = clock();
	ThreadedTraverse(testRoot, outputDeque);
	end = clock();
	interval2 = end - start;

	printf("Normal Inorder Traversal: %ld\n"
			"Threaded tree Traversal: %ld\n"
			, interval1, interval2);

	DeleteDeque(outputDeque);
	DeleteBintree(testRoot);
	DeleteThreadedTree(testRoot2);
	return 0;
}

