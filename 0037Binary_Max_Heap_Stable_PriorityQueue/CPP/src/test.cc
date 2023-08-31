#include "test.hh"

int UnitTest_StablePriorityQueue(void)
{
	HEAP testHeap(10);
	HEAP_NODE *tempArray = NULL;
	HEAP_NODE *outputStore = new HEAP_NODE[18];

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

	//Dequeueing test Start.
	for (int i=0 ; i<17 ; i++){
		if (testHeap.Dequeue_P(outputStore+i) != &testHeap){
			UNIT_TEST_FAIL;
			return -39;
		}
	}

	if (testHeap.Dequeue_P(outputStore+18) != NULL){
		UNIT_TEST_FAIL;
		return -40;
	}

	if (outputStore[0].id != 200 || strcmp(outputStore[0].data, "c")){
		UNIT_TEST_FAIL;
		return -41;
	}

	if (outputStore[1].id != 170 || strcmp(outputStore[1].data, "d")){
		UNIT_TEST_FAIL;
		return -42;
	}

	if (outputStore[2].id != 170 || strcmp(outputStore[2].data, "r")){
		UNIT_TEST_FAIL;
		return -43;
	}

	if (outputStore[3].id != 90 || strcmp(outputStore[3].data, "h")){
		UNIT_TEST_FAIL;
		return -44;
	}

	if (outputStore[4].id != 90 || strcmp(outputStore[4].data, "m")){
		UNIT_TEST_FAIL;
		return -45;
	}

	if (outputStore[5].id != 80 || strcmp(outputStore[5].data, "e")){
		UNIT_TEST_FAIL;
		return -46;
	}

	if (outputStore[6].id != 80 || strcmp(outputStore[6].data, "l")){
		UNIT_TEST_FAIL;
		return -47;
	}

	if (outputStore[7].id != 70 || strcmp(outputStore[7].data, "k")){
		UNIT_TEST_FAIL;
		return -48;
	}

	if (outputStore[8].id != 50 || strcmp(outputStore[8].data, "a")){
		UNIT_TEST_FAIL;
		STD_COUT << outputStore[8].id << " " << outputStore[8].data << std::endl;
		return -49;
	}

	if (outputStore[9].id != 50 || strcmp(outputStore[9].data, "p")){
		UNIT_TEST_FAIL;
		return -50;
	}

	if (outputStore[10].id != 30 || strcmp(outputStore[10].data, "f")){
		UNIT_TEST_FAIL;
		return -51;
	}
	if (outputStore[11].id != 30 || strcmp(outputStore[11].data, "j")){
		UNIT_TEST_FAIL;
		return -52;
	}

	if (outputStore[12].id != 30 || strcmp(outputStore[12].data, "o")){
		UNIT_TEST_FAIL;
		return -53;
	}

	if (outputStore[13].id != 20 || strcmp(outputStore[13].data, "b")){
		UNIT_TEST_FAIL;
		return -54;
	}

	if (outputStore[14].id != 20 || strcmp(outputStore[14].data, "i")){
		UNIT_TEST_FAIL;
		return -55;
	}

	if (outputStore[15].id != 20 || strcmp(outputStore[15].data, "n")){
		UNIT_TEST_FAIL;
		return -56;
	}

	if (outputStore[16].id != 20 || strcmp(outputStore[16].data, "q")){
		UNIT_TEST_FAIL;
		return -57;
	}

	return 0;
}
