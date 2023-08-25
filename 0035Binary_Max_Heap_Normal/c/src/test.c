#include "test.h"

int UnitTest_Heap(void)
{
	HEAP_NODE outPut;
	HEAP *testHeap = NULL;
	HEAP_NODE *tempArray = NULL;

	testHeap = CreateHeap(10);
	#define testHeap_Enqueue( ... ) testHeap->Enqueue(testHeap, ##__VA_ARGS__)
	#define testHeap_Dequeue( ... ) testHeap->Dequeue(testHeap, ##__VA_ARGS__)
	#define testHeap_ParentNode( ... ) testHeap->ParentNode(testHeap, ##__VA_ARGS__)
	#define testHeap_LeftChildNode( ... ) testHeap->LeftChildNode(testHeap, ##__VA_ARGS__)
	#define testHeap_RightChildNode( ... ) testHeap->RightChildNode(testHeap, ##__VA_ARGS__)

	if (testHeap->size != 1023){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testHeap->level != 10){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testHeap->lastIndex != -1){
		UNIT_TEST_FAIL;
		return -3;
	}
	
	testHeap_Enqueue(300, "a");
	testHeap_Enqueue(100, "b");
	testHeap_Enqueue(500, "c");
	testHeap_Enqueue(30, "d");
	testHeap_Enqueue(100, "e");
	testHeap_Enqueue(70, "f");
	testHeap_Enqueue(100, "g");
	testHeap_Enqueue(95, "h");
	testHeap_Enqueue(100, "i");
	testHeap_Enqueue(120, "j");
	testHeap_Enqueue(100, "k");
	testHeap_Enqueue(200, "l");

	tempArray = testHeap->heapArray;

	if (tempArray->key != 500 || strcmp(tempArray->data, "c")){
		PRINTF("key: %d, data: %s\n", tempArray->key, tempArray->data);
		UNIT_TEST_FAIL;
		return -4;
	}

	tempArray += 1;
	if (tempArray->key != 120 || strcmp(tempArray->data, "j")){
		UNIT_TEST_FAIL;
		return -5;
	}

	tempArray += 1;
	if (tempArray->key != 300 || strcmp(tempArray->data, "a")){
		UNIT_TEST_FAIL;
		return -6;
	}

	tempArray += 1;
	if (tempArray->key != 100 || strcmp(tempArray->data, "i")){
		UNIT_TEST_FAIL;
		return -7;
	}

	tempArray += 1;
	if (tempArray->key != 100 || strcmp(tempArray->data, "b")){
		UNIT_TEST_FAIL;
		return -8;
	}

	tempArray += 1;
	if (tempArray->key != 200 || strcmp(tempArray->data, "l")){
		UNIT_TEST_FAIL;
		return -9;
	}

	tempArray += 1;
	if (tempArray->key != 100 || strcmp(tempArray->data, "g")){
		UNIT_TEST_FAIL;
		return -10;
	}

	tempArray += 1;
	if (tempArray->key != 30 || strcmp(tempArray->data, "d")){
		UNIT_TEST_FAIL;
		return -11;
	}

	tempArray += 1;
	if (tempArray->key != 95 || strcmp(tempArray->data, "h")){
		UNIT_TEST_FAIL;
		return -12;
	}

	tempArray += 1;
	if (tempArray->key != 100 || strcmp(tempArray->data, "e")){
		UNIT_TEST_FAIL;
		return -13;
	}

	tempArray += 1;
	if (tempArray->key != 100 || strcmp(tempArray->data, "k")){
		UNIT_TEST_FAIL;
		return -14;
	}

	tempArray += 1;
	if (tempArray->key != 70 || strcmp(tempArray->data, "f")){
		UNIT_TEST_FAIL;
		return -15;
	}

	//Deletion Order = 500c, 300a, 200l, 120j, 100k, 100g, 100e, 100b, 100i, 95h, 70f, 30d
	tempArray = NULL;

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -16;
	}
	if (outPut.key != 500 || strcmp(outPut.data, "c")){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -18;
	}
	if (outPut.key != 300 || strcmp(outPut.data, "a")){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -20;
	}
	if (outPut.key != 200 || strcmp(outPut.data, "l")){
		UNIT_TEST_FAIL;
		PRINTF("key: %d, data: %s\n", outPut.key, outPut.data);
		return -21;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -22;
	}
	if (outPut.key != 120 || strcmp(outPut.data, "j")){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -24;
	}
	if (outPut.key != 100 || strcmp(outPut.data, "k")){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -26;
	}
	if (outPut.key != 100 || strcmp(outPut.data, "g")){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -28;
	}
	if (outPut.key != 100 || strcmp(outPut.data, "e")){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -30;
	}
	if (outPut.key != 100 || strcmp(outPut.data, "b")){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -32;
	}
	if (outPut.key != 100 || strcmp(outPut.data, "i")){
		UNIT_TEST_FAIL;
		return -33;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -34;
	}
	if (outPut.key != 95 || strcmp(outPut.data, "h")){
		UNIT_TEST_FAIL;
		return -35;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -36;
	}
	if (outPut.key != 70 || strcmp(outPut.data, "f")){
		UNIT_TEST_FAIL;
		return -37;
	}

	if (testHeap_Dequeue(&outPut) != testHeap){
		UNIT_TEST_FAIL;
		return -38;
	}
	if (outPut.key != 30 || strcmp(outPut.data, "d")){
		UNIT_TEST_FAIL;
		return -39;
	}

	if (testHeap_Dequeue(&outPut) != NULL){
		UNIT_TEST_FAIL;
		return -40;
	}
	
	if(RemoveHeap(testHeap)){
		UNIT_TEST_FAIL;
		return -9999;
	}

	return 0;
}
