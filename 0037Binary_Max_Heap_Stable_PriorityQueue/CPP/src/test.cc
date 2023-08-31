#include "test.hh"

int UnitTest_StablePriorityQueue(void)
{
	HEAP testHeap(10);
	HEAP_NODE *tempArray = NULL;

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

	//Enqueueing Test Start.
	tempArray = testHeap.heapArray;

	if (testHeap.Enqueue(50, "a") != &testHeap){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testHeap.Enqueue(20, "b") != &testHeap){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testHeap.Enqueue(200, "c") != &testHeap){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testHeap.Enqueue(170, "d") != &testHeap){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testHeap.Enqueue(80, "e") != &testHeap){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testHeap.Enqueue(30, "f") != &testHeap){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testHeap.Enqueue(90, "h") != &testHeap){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testHeap.Enqueue(20, "i") != &testHeap){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testHeap.Enqueue(30, "j") != &testHeap){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testHeap.Enqueue(70, "k") != &testHeap){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testHeap.Enqueue(80, "l") != &testHeap){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testHeap.Enqueue(90, "m") != &testHeap){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testHeap.Enqueue(20, "n") != &testHeap){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testHeap.Enqueue(30, "o") != &testHeap){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testHeap.Enqueue(50, "p") != &testHeap){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testHeap.Enqueue(20, "q") != &testHeap){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testHeap.Enqueue(170, "r") != &testHeap){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (tempArray[0].id != 200 || strcmp(tempArray[0].data, "c")){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (tempArray[1].id != 170 || strcmp(tempArray[1].data, "d")){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (tempArray[2].id != 90 || strcmp(tempArray[2].data, "h")){
		UNIT_TEST_FAIL;
		return -24;
	}

	if (tempArray[3].id != 170 || strcmp(tempArray[3].data, "r")){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (tempArray[4].id != 80 || strcmp(tempArray[4].data, "e")){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (tempArray[5].id != 90 || strcmp(tempArray[5].data, "m")){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (tempArray[6].id != 50 || strcmp(tempArray[6].data, "a")){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (tempArray[7].id != 30 || strcmp(tempArray[7].data, "j")){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (tempArray[8].id != 20 || strcmp(tempArray[8].data, "b")){
		UNIT_TEST_FAIL;
		return -30;
	}

	if (tempArray[9].id != 70 || strcmp(tempArray[9].data, "k")){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (tempArray[10].id != 80 || strcmp(tempArray[10].data, "l")){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (tempArray[11].id != 30 || strcmp(tempArray[11].data, "f")){
		UNIT_TEST_FAIL;
		return -33;
	}

	if (tempArray[12].id != 20 || strcmp(tempArray[12].data, "n")){
		UNIT_TEST_FAIL;
		return -34;
	}

	if (tempArray[13].id != 30 || strcmp(tempArray[13].data, "o")){
		UNIT_TEST_FAIL;
		return -35;
	}

	if (tempArray[14].id != 50 || strcmp(tempArray[14].data, "p")){
		UNIT_TEST_FAIL;
		return -36;
	}

	if (tempArray[15].id != 20 || strcmp(tempArray[15].data, "q")){
		UNIT_TEST_FAIL;
		return -37;
	}

	if (tempArray[16].id != 20 || strcmp(tempArray[16].data, "i")){
		UNIT_TEST_FAIL;
		return -38;
	}


	return 0;
}
