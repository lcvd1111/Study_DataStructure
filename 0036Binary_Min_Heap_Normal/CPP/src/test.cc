#include "test.hh"

int UnitTest_Heap(void)
{
	HEAP *testHeap = CreateHeap(10);
	HEAP_NODE *outputStore = new HEAP_NODE[14];
	HEAP_NODE *tempArray = NULL;
	memset(outputStore, 0, 14*sizeof(HEAP_NODE));
	
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
	testHeap->Enqueue(100, "a");
	testHeap->Enqueue(130, "b");
	testHeap->Enqueue(70, "c");
	testHeap->Enqueue(140, "d");
	testHeap->Enqueue(130, "e");
	testHeap->Enqueue(30, "f");
	testHeap->Enqueue(130, "g");
	testHeap->Enqueue(50, "h");
	testHeap->Enqueue(60, "i");
	testHeap->Enqueue(70, "j");
	testHeap->Enqueue(130, "k");
	testHeap->Enqueue(50, "l");
	testHeap->Enqueue(70, "m");

	tempArray = testHeap->heapArray;

	if (tempArray[0].id != 30 || strcmp(tempArray[0].data, "f")){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (tempArray[1].id != 50 || strcmp(tempArray[1].data, "h")){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (tempArray[2].id != 50 || strcmp(tempArray[2].data, "l")){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (tempArray[3].id != 60 || strcmp(tempArray[3].data, "i")){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (tempArray[4].id != 70 || strcmp(tempArray[4].data, "j")){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (tempArray[5].id != 70 || strcmp(tempArray[5].data, "c")){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (tempArray[6].id != 130 || strcmp(tempArray[6].data, "g")){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (tempArray[7].id != 140 || strcmp(tempArray[7].data, "d")){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (tempArray[8].id != 130 || strcmp(tempArray[8].data, "b")){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (tempArray[9].id != 130 || strcmp(tempArray[9].data, "e")){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (tempArray[10].id != 130 || strcmp(tempArray[10].data, "k")){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (tempArray[11].id != 100 || strcmp(tempArray[11].data, "a")){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (tempArray[12].id != 70 || strcmp(tempArray[12].data, "m")){
		UNIT_TEST_FAIL;
		return -17;
	}

	//Dequeueing Test Start.
	for (int i=0 ; i<13 ; i++){
		if ((testHeap->Dequeue(outputStore+i)) != testHeap){
			UNIT_TEST_FAIL;
			return -18;
		}
	}

	if ((testHeap->Dequeue(outputStore+13))!=NULL){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (outputStore[0].id != 30 || strcmp(outputStore[0].data, "f")){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (outputStore[1].id != 50 || strcmp(outputStore[1].data, "l")){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (outputStore[2].id != 50 || strcmp(outputStore[2].data, "h")){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (outputStore[3].id != 60 || strcmp(outputStore[3].data, "i")){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (outputStore[4].id != 70 || strcmp(outputStore[4].data, "m")){
		UNIT_TEST_FAIL;
		return -24;
	}

	if (outputStore[5].id != 70 || strcmp(outputStore[5].data, "c")){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (outputStore[6].id != 70 || strcmp(outputStore[6].data, "j")){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (outputStore[7].id != 100 || strcmp(outputStore[7].data, "a")){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (outputStore[8].id != 130 || strcmp(outputStore[8].data, "e")){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (outputStore[9].id != 130 || strcmp(outputStore[9].data, "k")){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (outputStore[10].id != 130 || strcmp(outputStore[10].data, "b")){
		UNIT_TEST_FAIL;
		return -30;
	}

	if (outputStore[11].id != 130 || strcmp(outputStore[11].data, "g")){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (outputStore[12].id != 140 || strcmp(outputStore[12].data, "d")){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (DestroyHeap(testHeap)){
		UNIT_TEST_FAIL;
		return -9999;
	}

	delete[] outputStore;
	return 0;
}
