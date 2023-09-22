#include "mylib.h"
#include "test.h"

int UnitTest(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	QUEUE *myQueue = NULL;

	root->data = 1;
	root->left = NULL;
	root->right = NULL;

	myQueue = CreateQueue(6);

	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, LEFT, 6, 6);

	if(Dequeue(myQueue) != NULL){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -1;
	}
	printf("test case 01 success.\n");

	Enqueue(myQueue, root);
	Enqueue(myQueue, root->left);
	Enqueue(myQueue, root->right);
	Enqueue(myQueue, root->left->left);
	Enqueue(myQueue, root->left->right);
	Enqueue(myQueue, root->right->left);

	if(Enqueue(myQueue, root) != NULL){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -2;
	}
	printf("test case 02 success.\n");

	if(Dequeue(myQueue)->data != 1){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -3;
	}
	printf("test case 03 success.\n");

	if(Enqueue(myQueue, root) == NULL){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -4;
	}
	printf("test case 04 success.\n");

	if(Dequeue(myQueue)->data != 2){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -5;
	}
	printf("test case 05 success.\n");

	if(Dequeue(myQueue)->data != 3){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -6;
	}
	printf("test case 06 success.\n");

	if(Dequeue(myQueue)->data != 4){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -7;
	}
	printf("test case 07 success.\n");

	if(Dequeue(myQueue)->data != 5){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -8;
	}
	printf("test case 08 success.\n");

	if(Dequeue(myQueue)->data != 6){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -9;
	}
	printf("test case 09 success.\n");

	if(Dequeue(myQueue)->data != 1){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -10;
	}
	printf("test case 10 success.\n");

	if(Enqueue(myQueue, root->left) == NULL){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -11;
	}
	printf("test case 11 success.\n");

	if(Dequeue(myQueue)->data != 2){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -12;
	}
	printf("test case 12 success.\n");

	if(Dequeue(myQueue) != NULL){
		PRINTF("ERROR: Unit Test Fail.\n");
		return -13;
	}
	printf("test case 13 success.\n");

	free(root->right->left);
	free(root->left->right);
	free(root->left->left);
	free(root->right);
	free(root->left);
	free(root);

	DeleteQueue(myQueue);

	return 0;
}
