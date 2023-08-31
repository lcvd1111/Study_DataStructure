#include "test.h"

int UnitTest_StableHeap(void)
{
	HEAP *testHeap = CreateHeap(10);
	HEAP_NODE *tempArray = NULL;
	HEAP_NODE outputStore[20];
	memset(outputStore, 0, sizeof(HEAP_NODE)*20);
	HEAP *errReturn = NULL;

	if (testHeap->level != 10){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testHeap->size != 1023){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testHeap->lastIndex != -1){
		UNIT_TEST_FAIL;
		return -3;
	}

	//Enqueueing Test Start.
	testHeap->Enqueue(testHeap, 50, "a");
	testHeap->Enqueue(testHeap, 20, "b");
	testHeap->Enqueue(testHeap, 200, "c");
	testHeap->Enqueue(testHeap, 170, "d");
	testHeap->Enqueue(testHeap, 80, "e");
	testHeap->Enqueue(testHeap, 30, "f");
	testHeap->Enqueue(testHeap, 90, "h");
	testHeap->Enqueue(testHeap, 20, "i");
	testHeap->Enqueue(testHeap, 30, "j");
	testHeap->Enqueue(testHeap, 70, "k");
	testHeap->Enqueue(testHeap, 80, "l");
	testHeap->Enqueue(testHeap, 90, "m");
	testHeap->Enqueue(testHeap, 20, "n");
	testHeap->Enqueue(testHeap, 30, "o");
	testHeap->Enqueue(testHeap, 50, "p");
	testHeap->Enqueue(testHeap, 20, "q");
	testHeap->Enqueue(testHeap, 170, "r");

	tempArray = testHeap->heapArray;

	if (tempArray[0].id != 200 || strcmp(tempArray[0].data, "c")){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (tempArray[1].id != 170 || strcmp(tempArray[1].data, "d")){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (tempArray[2].id != 90 || strcmp(tempArray[2].data, "h")){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (tempArray[3].id != 170 || strcmp(tempArray[3].data, "r")){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (tempArray[4].id != 80 || strcmp(tempArray[4].data, "e")){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (tempArray[5].id != 90 || strcmp(tempArray[5].data, "m")){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (tempArray[6].id != 50 || strcmp(tempArray[6].data, "a")){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (tempArray[7].id != 30 || strcmp(tempArray[7].data, "j")){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (tempArray[8].id != 20 || strcmp(tempArray[8].data, "b")){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (tempArray[9].id != 70 || strcmp(tempArray[9].data, "k")){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (tempArray[10].id != 80 || strcmp(tempArray[10].data, "l")){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (tempArray[11].id != 30 || strcmp(tempArray[11].data, "f")){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (tempArray[12].id != 20 || strcmp(tempArray[12].data, "n")){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (tempArray[13].id != 30 || strcmp(tempArray[13].data, "o")){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (tempArray[14].id != 50 || strcmp(tempArray[14].data, "p")){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (tempArray[15].id != 20 || strcmp(tempArray[15].data, "q")){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (tempArray[16].id != 20 || strcmp(tempArray[16].data, "i")){
		UNIT_TEST_FAIL;
		return -20;
	}

	//Dequeueing Test Start.

	for (int i=0; i<17 ; i++){
		if ((errReturn = testHeap->Dequeue_P(testHeap, outputStore+i))!= testHeap){
			UNIT_TEST_FAIL;
			PRINTF("errReturn: %p\n", errReturn);
			return -21;
		}
	}
	
	if (testHeap->Dequeue_P(testHeap, outputStore+17) != NULL){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (outputStore[0].id != 200 || strcmp(outputStore[0].data, "c")){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (outputStore[1].id != 170 || strcmp(outputStore[1].data, "d")){
		UNIT_TEST_FAIL;
		return -24;
	}

	if (outputStore[2].id != 170 || strcmp(outputStore[2].data, "r")){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (outputStore[3].id != 90 || strcmp(outputStore[3].data, "h")){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (outputStore[4].id != 90 || strcmp(outputStore[4].data, "m")){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (outputStore[5].id != 80 || strcmp(outputStore[5].data, "e")){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (outputStore[6].id != 80 || strcmp(outputStore[6].data, "l")){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (outputStore[7].id != 70 || strcmp(outputStore[7].data, "k")){
		UNIT_TEST_FAIL;
		return -30;
	}
	if (outputStore[8].id != 50 || strcmp(outputStore[8].data, "a")){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (outputStore[9].id != 50 || strcmp(outputStore[9].data, "p")){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (outputStore[10].id != 30 || strcmp(outputStore[10].data, "f")){
		UNIT_TEST_FAIL;
		return -33;
	}
	if (outputStore[11].id != 30 || strcmp(outputStore[11].data, "j")){
		UNIT_TEST_FAIL;
		return -34;
	}

	if (outputStore[12].id != 30 || strcmp(outputStore[12].data, "o")){
		UNIT_TEST_FAIL;
		return -35;
	}

	if (outputStore[13].id != 20 || strcmp(outputStore[13].data, "b")){
		UNIT_TEST_FAIL;
		return -36;
	}

	if (outputStore[14].id != 20 || strcmp(outputStore[14].data, "i")){
		UNIT_TEST_FAIL;
		return -37;
	}

	if (outputStore[15].id != 20 || strcmp(outputStore[15].data, "n")){
		UNIT_TEST_FAIL;
		return -38;
	}

	if (outputStore[16].id != 20 || strcmp(outputStore[16].data, "q")){
		UNIT_TEST_FAIL;
		return -39;
	}

	if(DestroyHeap(testHeap)){
		UNIT_TEST_FAIL;
		return -9999;
	}

	return 0;
}
