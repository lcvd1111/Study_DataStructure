#include "test.h"

int UnitTest_MinHeap(void)
{
	HEAP *myHeap = CreateHeap(10);
	HEAP_NODE *tempArray = NULL;
	HEAP_NODE outputStore = {0,{0,}};

	if (myHeap->level != 10){
		PRINTF("Unit Test Fail.\n");
		return -1;
	}

	if (myHeap->size != 1023){
		PRINTF("Unit Test Fail.\n");
		return -2;
	}

	if (myHeap->lastIndex != -1){
		PRINTF("Unit Test Fail.\n");
		return -3;
	}

	(myHeap->Enqueue)(myHeap, 100, "a");
	if (myHeap->lastIndex != 0){
		PRINTF("Unit Test Fail.\n");
		return -4;
	}

	(myHeap->Enqueue)(myHeap, 130, "b");
	if (myHeap->lastIndex != 1){
		PRINTF("Unit Test Fail.\n");
		return -4;
	}

	(myHeap->Enqueue)(myHeap, 70, "c");
	(myHeap->Enqueue)(myHeap, 140, "d");
	(myHeap->Enqueue)(myHeap, 130, "e");
	(myHeap->Enqueue)(myHeap, 30, "f");
	(myHeap->Enqueue)(myHeap, 130, "g");
	(myHeap->Enqueue)(myHeap, 50, "h");
	(myHeap->Enqueue)(myHeap, 60, "i");
	(myHeap->Enqueue)(myHeap, 70, "j");
	(myHeap->Enqueue)(myHeap, 130, "k");
	(myHeap->Enqueue)(myHeap, 50, "l");
	(myHeap->Enqueue)(myHeap, 70, "m");

	tempArray = myHeap->heapArray;

	if (tempArray[0].id != 30 || strcmp(tempArray[0].data, "f")){
		PRINTF("Unit Test Fail.\n");
		return -5;
	}

	if (tempArray[1].id != 50 || strcmp(tempArray[1].data, "h")){
		PRINTF("Unit Test Fail.\n");
		return -6;
	}

	if (tempArray[2].id != 50 || strcmp(tempArray[2].data, "l")){
		PRINTF("Unit Test Fail.\n");
		return -7;
	}

	if (tempArray[3].id != 60 || strcmp(tempArray[3].data, "i")){
		PRINTF("Unit Test Fail.\n");
		return -8;
	}

	if (tempArray[4].id != 70 || strcmp(tempArray[4].data, "j")){
		PRINTF("Unit Test Fail.\n");
		PRINTF("id: %d, data: %s\n", tempArray[4].id, tempArray[4].data);
		return -9;
	}

	if (tempArray[5].id != 70 || strcmp(tempArray[5].data, "c")){
		PRINTF("Unit Test Fail.\n");
		return -10;
	}

	if (tempArray[6].id != 130 || strcmp(tempArray[6].data, "g")){
		PRINTF("Unit Test Fail.\n");
		return -11;
	}

	if (tempArray[7].id != 140 || strcmp(tempArray[7].data, "d")){
		PRINTF("Unit Test Fail.\n");
		return -12;
	}


	if (tempArray[8].id != 130 || strcmp(tempArray[8].data, "b")){
		PRINTF("Unit Test Fail.\n");
		return -13;
	}


	if (tempArray[9].id != 130 || strcmp(tempArray[9].data, "e")){
		PRINTF("Unit Test Fail.\n");
		return -14;
	}


	if (tempArray[10].id != 130 || strcmp(tempArray[10].data, "k")){
		PRINTF("Unit Test Fail.\n");
		return -15;
	}

	if (tempArray[11].id != 100 || strcmp(tempArray[11].data, "a")){
		PRINTF("Unit Test Fail.\n");
		return -16;
	}

	if (tempArray[12].id != 70 || strcmp(tempArray[12].data, "m")){
		PRINTF("Unit Test Fail.\n");
		return -17;
	}

	//Dequeueing test starts here.

	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -18;
	}

	if (outputStore.id != 30 || strcmp(outputStore.data, "f")){
		PRINTF("Unit Test Fail.\n");
		return -19;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -20;
	}

	if (outputStore.id != 50 || strcmp(outputStore.data, "l")){
		PRINTF("Unit Test Fail.\n");
		return -21;
	}

	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -22;
	}

	if (outputStore.id != 50 || strcmp(outputStore.data, "h")){
		PRINTF("Unit Test Fail.\n");
		return -23;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -22;
	}

	if (outputStore.id != 60 || strcmp(outputStore.data, "i")){
		PRINTF("Unit Test Fail.\n");
		return -23;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -24;
	}

	if (outputStore.id != 70 || strcmp(outputStore.data, "m")){
		PRINTF("Unit Test Fail.\n");
		return -25;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -26;
	}

	if (outputStore.id != 70 || strcmp(outputStore.data, "c")){
		PRINTF("Unit Test Fail.\n");
		return -27;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -28;
	}

	if (outputStore.id != 70 || strcmp(outputStore.data, "j")){
		PRINTF("Unit Test Fail.\n");
		return -29;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -30;
	}

	if (outputStore.id != 100 || strcmp(outputStore.data, "a")){
		PRINTF("Unit Test Fail.\n");
		return -31;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -32;
	}

	if (outputStore.id != 130 || strcmp(outputStore.data, "e")){
		PRINTF("Unit Test Fail.\n");
		return -33;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -34;
	}

	if (outputStore.id != 130 || strcmp(outputStore.data, "k")){
		PRINTF("Unit Test Fail.\n");
		return -35;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -36;
	}

	if (outputStore.id != 130 || strcmp(outputStore.data, "b")){
		PRINTF("Unit Test Fail.\n");
		return -37;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		PRINTF("Unit Test Fail.\n");
		return -38;
	}

	if (outputStore.id != 130 || strcmp(outputStore.data, "g")){
		PRINTF("Unit Test Fail.\n");
		return -39;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != myHeap){
		return -40;
	}

	if (outputStore.id != 140 || strcmp(outputStore.data, "d")){
		PRINTF("Unit Test Fail.\n");
		return -41;
	}
	
	if (myHeap->Dequeue(myHeap, &outputStore) != NULL){
		PRINTF("Unit Test Fail.\n");
		return -42;
	}

	if (DestroyHeap(myHeap)){
		PRINTF("Unit Test Fail.\n");
		return -9999;
	}

	return 0;
}
