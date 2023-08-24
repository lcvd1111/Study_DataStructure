#include "test.h"

int UnitTest_BinaryMaxHeap(void)
{
	MAX_HEAP *testHeap = NULL;
	HEAP_NODE *current = NULL;
	testHeap = CreateHeap(8);

	if (testHeap->depth != 7){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testHeap->maxNum != 255){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testHeap->lastIndex != -1){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (Insert(testHeap, 50, "a") == NULL){
		UNIT_TEST_FAIL;
		return -5;
	}
	
	if (Insert(testHeap, 30, "b") == NULL){
		UNIT_TEST_FAIL;
		return -6;
	}
	
	if (Insert(testHeap, 200, "c") == NULL){
		UNIT_TEST_FAIL;
		return -7;
	}
	
	if (Insert(testHeap, 70, "d") == NULL){
		UNIT_TEST_FAIL;
		return -8;
	}
	
	if (Insert(testHeap, 50, "e") == NULL){
		UNIT_TEST_FAIL;
		return -9;
	}
	
	if (Insert(testHeap, 10, "f") == NULL){
		UNIT_TEST_FAIL;
		return -10;
	}
	
	if (Insert(testHeap, 25, "g") == NULL){
		UNIT_TEST_FAIL;
		return -11;
	}
	
	if (Insert(testHeap, 150, "h") == NULL){
		UNIT_TEST_FAIL;
		return -12;
	}
	
	if (Insert(testHeap, 30, "i") == NULL){
		UNIT_TEST_FAIL;
		return -13;
	}
	
	if (Insert(testHeap, 70, "j") == NULL){
		UNIT_TEST_FAIL;
		return -14;
	}
	
	if (Insert(testHeap, 20, "k") == NULL){
		UNIT_TEST_FAIL;
		return -15;
	}
	
	if (Insert(testHeap, 30, "l") == NULL){
		UNIT_TEST_FAIL;
		return -16;
	}
	
	if (Insert(testHeap, 500, "m") == NULL){
		UNIT_TEST_FAIL;
		return -17;
	}
	
	if (Insert(testHeap, 200, "n") == NULL){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testHeap->lastIndex != 13){
		UNIT_TEST_FAIL;
		return -19;
	}
	
	current = testHeap->heapArray;
	if (current->key != 500 || strcmp(current->data, "m")){
		UNIT_TEST_FAIL;
		return -20;
	}

	current++;
	if (current->key != 150 || strcmp(current->data, "h")){
		UNIT_TEST_FAIL;
		return -21;
	}

	current++;
	if (current->key != 200 || strcmp(current->data, "c")){
		UNIT_TEST_FAIL;
		return -22;
	}

	current++;
	if (current->key != 70 || strcmp(current->data, "d")){
		UNIT_TEST_FAIL;
		return -23;
	}

	current++;
	if (current->key != 70 || strcmp(current->data, "j")){
		UNIT_TEST_FAIL;
		return -24;
	}

	current++;
	if (current->key != 50 || strcmp(current->data, "a")){
		UNIT_TEST_FAIL;
		return -25;
	}

	current++;
	if (current->key != 200 || strcmp(current->data, "n")){
		UNIT_TEST_FAIL;
		return -26;
	}

	current++;
	if (current->key != 30 || strcmp(current->data, "b")){
		UNIT_TEST_FAIL;
		return -27;
	}

	current++;
	if (current->key != 30 || strcmp(current->data, "i")){
		UNIT_TEST_FAIL;
		return -28;
	}

	current++;
	if (current->key != 50 || strcmp(current->data, "e")){
		UNIT_TEST_FAIL;
		return -29;
	}

	current++;
	if (current->key != 20 || strcmp(current->data, "k")){
		UNIT_TEST_FAIL;
		return -30;
	}

	current++;
	if (current->key != 10 || strcmp(current->data, "f")){
		UNIT_TEST_FAIL;
		return -31;
	}

	current++;
	if (current->key != 30 || strcmp(current->data, "l")){
		UNIT_TEST_FAIL;
		return -32;
	}

	current++;
	if (current->key != 25 || strcmp(current->data, "g")){
		UNIT_TEST_FAIL;
		return -33;
	}

	current = testHeap->heapArray;
	if (current->key != 500 || strcmp(current->data, "m")){
		UNIT_TEST_FAIL;
		return -34;
	}

	current = LeftChildNode(testHeap, current);
	if (current->key != 150 || strcmp(current->data, "h")){
		UNIT_TEST_FAIL;
		return -35;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 200 || strcmp(current->data, "c")){
		UNIT_TEST_FAIL;
		return -22;
	}
	
	current = ParentNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 70 || strcmp(current->data, "d")){
		UNIT_TEST_FAIL;
		return -23;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 70 || strcmp(current->data, "j")){
		UNIT_TEST_FAIL;
		return -24;
	}

	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 50 || strcmp(current->data, "a")){
		UNIT_TEST_FAIL;
		return -25;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 200 || strcmp(current->data, "n")){
		UNIT_TEST_FAIL;
		return -26;
	}

	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 30 || strcmp(current->data, "b")){
		UNIT_TEST_FAIL;
		return -27;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 30 || strcmp(current->data, "i")){
		UNIT_TEST_FAIL;
		return -28;
	}

	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 50 || strcmp(current->data, "e")){
		UNIT_TEST_FAIL;
		return -29;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 20 || strcmp(current->data, "k")){
		UNIT_TEST_FAIL;
		return -30;
	}

	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 10 || strcmp(current->data, "f")){
		UNIT_TEST_FAIL;
		return -31;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current->key != 30 || strcmp(current->data, "l")){
		UNIT_TEST_FAIL;
		return -32;
	}

	current = ParentNode(testHeap, current);
	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	current = LeftChildNode(testHeap, current);
	if (current->key != 25 || strcmp(current->data, "g")){
		UNIT_TEST_FAIL;
		return -33;
	}

	current = ParentNode(testHeap, current);
	current = RightChildNode(testHeap, current);
	if (current != NULL){
		UNIT_TEST_FAIL;
		return -34;
	}

	current = new HEAP_NODE;
	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -35;
	}

	if (current->key != 500 || strcmp(current->data, "m")){
		UNIT_TEST_FAIL;
		return -36;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -37;
	}

	if (current->key != 200 || strcmp(current->data, "c")){
		UNIT_TEST_FAIL;
		return -38;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -39;
	}

	if (current->key != 200 || strcmp(current->data, "n")){
		UNIT_TEST_FAIL;
		return -40;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -41;
	}

	if (current->key != 150 || strcmp(current->data, "h")){
		UNIT_TEST_FAIL;
		return -42;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -43;
	}

	if (current->key != 70 || strcmp(current->data, "j")){
		UNIT_TEST_FAIL;
		return -44;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -45;
	}

	if (current->key != 70 || strcmp(current->data, "d")){
		UNIT_TEST_FAIL;
		return -46;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -47;
	}

	if (current->key != 50 || strcmp(current->data, "a")){
		UNIT_TEST_FAIL;
		return -48;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -49;
	}

	if (current->key != 50 || strcmp(current->data, "e")){
		UNIT_TEST_FAIL;
		return -50;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -51;
	}

	if (current->key != 30 || strcmp(current->data, "l")){
		UNIT_TEST_FAIL;
		return -52;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -53;
	}

	if (current->key != 30 || strcmp(current->data, "b")){
		UNIT_TEST_FAIL;
		return -54;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -55;
	}

	if (current->key != 30 || strcmp(current->data, "i")){
		UNIT_TEST_FAIL;
		return -56;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -57;
	}

	if (current->key != 25 || strcmp(current->data, "g")){
		UNIT_TEST_FAIL;
		return -58;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -59;
	}

	if (current->key != 20 || strcmp(current->data, "k")){
		UNIT_TEST_FAIL;
		return -60;
	}

	if (Delete(testHeap, current) != testHeap){
		UNIT_TEST_FAIL;
		return -61;
	}

	if (current->key != 10 || strcmp(current->data, "f")){
		UNIT_TEST_FAIL;
		return -62;
	}

	if (Delete(testHeap, current) != NULL){
		UNIT_TEST_FAIL;
		return -57;
	}

	delete current;
	DeleteHeap(testHeap);
	return 0;
}
