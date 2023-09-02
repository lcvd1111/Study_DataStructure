#include "test.hh"

int UnitTest_StablePriorityQueue_using_MinHeap(void)
{
	HEAP testHeap(10);
	HEAP_NODE *tempArray = NULL;
	HEAP_NODE outputStore[20];

	if (testHeap.level != 10){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testHeap.size != 1023){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testHeap.lastIndex != -1){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testHeap.lastEnqOrder != 0){
		UNIT_TEST_FAIL;
		return -4;
	}

	//Enqueueing test
	testHeap.Enqueue(50, "a");
	testHeap.Enqueue(80, "b");
	testHeap.Enqueue(30, "c");
	testHeap.Enqueue(70, "d");
	testHeap.Enqueue(80, "e");
	testHeap.Enqueue(90, "f");
	testHeap.Enqueue(50, "g");
	testHeap.Enqueue(30, "h");
	testHeap.Enqueue(40, "i");
	testHeap.Enqueue(80, "j");
	testHeap.Enqueue(100, "k");
	testHeap.Enqueue(50, "l");
	testHeap.Enqueue(30, "m");
	testHeap.Enqueue(30, "n");
	testHeap.Enqueue(60, "o");
	testHeap.Enqueue(70, "p");
	testHeap.Enqueue(50, "q");

	if (testHeap.lastEnqOrder != 17){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testHeap.lastIndex != 16){
		UNIT_TEST_FAIL;
		return -6;
	}

	tempArray = testHeap.heapArray;

	if (tempArray[0].id != 30 || strcmp(tempArray[0].data, "c")){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (tempArray[1].id != 30 || strcmp(tempArray[1].data, "h")){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (tempArray[2].id != 30 || strcmp(tempArray[2].data, "m")){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (tempArray[3].id != 40 || strcmp(tempArray[3].data, "i")){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (tempArray[4].id != 80 || strcmp(tempArray[4].data, "e")){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (tempArray[5].id != 50 || strcmp(tempArray[5].data, "a")){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (tempArray[6].id != 30 || strcmp(tempArray[6].data, "n")){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (tempArray[7].id != 50 || strcmp(tempArray[7].data, "q")){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (tempArray[8].id != 70 || strcmp(tempArray[8].data, "d")){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (tempArray[9].id != 80 || strcmp(tempArray[9].data, "j")){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (tempArray[10].id != 100 || strcmp(tempArray[10].data, "k")){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (tempArray[11].id != 90 || strcmp(tempArray[11].data, "f")){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (tempArray[12].id != 50 || strcmp(tempArray[12].data, "l")){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (tempArray[13].id != 50 || strcmp(tempArray[13].data, "g")){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (tempArray[13].id != 50 || strcmp(tempArray[13].data, "g")){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (tempArray[14].id != 60 || strcmp(tempArray[14].data, "o")){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (tempArray[15].id != 80 || strcmp(tempArray[15].data, "b")){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (tempArray[16].id != 70 || strcmp(tempArray[16].data, "p")){
		UNIT_TEST_FAIL;
		return -24;
	}

	//Dequeueing Test.
	for (int i=0 ; i<17 ; i++){
		if (testHeap.Dequeue(outputStore+i) != &testHeap){
			UNIT_TEST_FAIL;
			return -25;
		}
	}

	if (outputStore[0].id != 30 || strcmp(outputStore[0].data, "c")){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (outputStore[1].id != 30 || strcmp(outputStore[1].data, "h")){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (outputStore[2].id != 30 || strcmp(outputStore[2].data, "m")){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (outputStore[3].id != 30 || strcmp(outputStore[3].data, "n")){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (outputStore[4].id != 40 || strcmp(outputStore[4].data, "i")){
		UNIT_TEST_FAIL;
		return -30;
	}

	if (outputStore[5].id != 50 || strcmp(outputStore[5].data, "a")){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (outputStore[6].id != 50 || strcmp(outputStore[6].data, "g")){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (outputStore[7].id != 50 || strcmp(outputStore[7].data, "l")){
		UNIT_TEST_FAIL;
		return -33;
	}

	if (outputStore[8].id != 50 || strcmp(outputStore[8].data, "q")){
		UNIT_TEST_FAIL;
		return -34;
	}

	if (outputStore[9].id != 60 || strcmp(outputStore[9].data, "o")){
		UNIT_TEST_FAIL;
		return -35;
	}

	if (outputStore[10].id != 70 || strcmp(outputStore[10].data, "d")){
		UNIT_TEST_FAIL;
		return -36;
	}

	if (outputStore[11].id != 70 || strcmp(outputStore[11].data, "p")){
		UNIT_TEST_FAIL;
		return -37;
	}

	if (outputStore[12].id != 80 || strcmp(outputStore[12].data, "b")){
		UNIT_TEST_FAIL;
		return -38;
	}

	if (outputStore[13].id != 80 || strcmp(outputStore[13].data, "e")){
		UNIT_TEST_FAIL;
		return -39;
	}

	if (outputStore[14].id != 80 || strcmp(outputStore[14].data, "j")){
		UNIT_TEST_FAIL;
		return -40;
	}

	if (outputStore[15].id != 90 || strcmp(outputStore[15].data, "f")){
		UNIT_TEST_FAIL;
		return -41;
	}

	if (outputStore[16].id != 100 || strcmp(outputStore[16].data, "k")){
		UNIT_TEST_FAIL;
		return -42;
	}

	if (testHeap.Dequeue(outputStore+17) != NULL){
		UNIT_TEST_FAIL;
		return -43;
	}

	return 0;
}
