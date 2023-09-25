#include "common.h"
#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE *qp = &testQueue;
	QUEUE_CONSTRUCTOR(&testQueue);
	int sampleArray[5]={0,};
	void *dequeueBuffer = NULL;
	void **vp = &dequeueBuffer;

	if (testQueue.CreateQueue(qp, 5) != qp){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Dequeue(qp, vp) != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != qp){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Dequeue(qp, vp) != NULL){
		UNIT_TEST_FAIL;
		return -5;
	}

	for (int i=0; i<5; i++){
		if (testQueue.Enqueue(qp, sampleArray+i) != qp){
			UNIT_TEST_FAIL;
			return -6-i;
		}
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != NULL){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (dequeueBuffer != sampleArray+0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (dequeueBuffer != sampleArray+1){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testQueue.Enqueue(qp, sampleArray) != qp){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testQueue.Enqueue(qp, sampleArray+1) != qp){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != NULL){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (dequeueBuffer != sampleArray+2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (dequeueBuffer != sampleArray+3){
		UNIT_TEST_FAIL;
		return -22;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (dequeueBuffer != sampleArray+4){
		UNIT_TEST_FAIL;
		return -24;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (dequeueBuffer != sampleArray){
		UNIT_TEST_FAIL;
		return -26;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (dequeueBuffer != sampleArray+1){
		UNIT_TEST_FAIL;
		return -28;
	}


	if (testQueue.Dequeue(qp, vp) != NULL){
		UNIT_TEST_FAIL;
		return -29;
	}

	QUEUE_DESTRUCTOR(qp);
	return 0;
}

int UnitTest_Graph(void)
{
	return 0;
}

int UnitTest_BFS_Undirected(void)
{
	return 0;
}

int UnitTest_BFS_Directed(void)
{
	return 0;
}
