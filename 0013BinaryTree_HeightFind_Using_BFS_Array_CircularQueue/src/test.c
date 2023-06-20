#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE *myQueue = NULL;
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	QUEUE_NODE output;

	myQueue = CreateQueue();
	
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	
	Enqueue(myQueue, root, 0);
	Enqueue(myQueue, root->left, 0);
	Enqueue(myQueue, root->right, 0);
	Enqueue(myQueue, root->left->left, 0);
	Enqueue(myQueue, root->left->right, 0);
	Enqueue(myQueue, root->right->left, 0);
	Enqueue(myQueue, root->right->right, 0);

	if (myQueue->begin != 0 || myQueue->end != 6){
		PRINTF("Unit Test failed.\n");
		return -10;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 1){
		PRINTF("Unit Test failed.\n");
		return -1;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 2){
		PRINTF("Unit Test failed.\n");
		return -2;
	}
	
	Dequeue(myQueue, &output);
	if (output.addressData->data != 3){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 4){
		PRINTF("Unit Test failed.\n");
		return -4;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 5){
		PRINTF("Unit Test failed.\n");
		return -5;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 6){
		PRINTF("Unit Test failed.\n");
		return -6;
	}

	Dequeue(myQueue, &output);
	if (output.addressData->data != 7){
		PRINTF("Unit Test failed.\n");
		return -7;
	}

	if (myQueue->begin != -1 || myQueue->end != -1){
		PRINTF("Unit Test failed.\n");
		return -10;
	}
	
	if(Dequeue(myQueue, &output) != NULL){
		PRINTF("Unit Test failed\n");
		return -8;
	}

	if (DeleteQueue(myQueue)){
		PRINTF("Unit Test failed\n");
		return -9;
	}

	if (DeleteBintree(root)){
		PRINTF("Unit Test failed\n");
		return -10;
	}

	return 0;
}

int UnitTest_BFS(void)
{
	BINTREE_NODE *root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	root->left = NULL;
	root->right = NULL;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);

	if (FindHeightBFS(root) != 3){
		PRINTF("Unit Test failed.\n");
		return -1;
	}

	MakeChild(root->left->left, LEFT, 8, 8);
	if (FindHeightBFS(root) != 4){
		PRINTF("Unit Test failed.\n");
		return -2;
	}

	MakeChild(root->left->left, RIGHT, 9, 9);
	if (FindHeightBFS(root) != 4){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	MakeChild(root->right->left, BOTH, 10, 11);
	if (FindHeightBFS(root) != 4){
		PRINTF("Unit Test failed.\n");
		return -3;
	}

	MakeChild(root->right->left->left, BOTH, 12, 13);
	if (FindHeightBFS(root) != 5){
		PRINTF("Unit Test failed.\n");
		return -4;
	}

	if (DeleteBintree(root)){
		PRINTF("Unit Test failed\n");
		return -5;
	}

	return 0;
}
