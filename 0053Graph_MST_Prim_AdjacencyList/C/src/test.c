#include "lib_graph.h"
#include "lib_heap.h"

int UnitTest_Heap(void)
{
	int testPointer[10] = {0,1,2,3,4,5,6,7,8,9};
	HEAP testHeap;
	HEAP *p = &testHeap; //p == pTestHeap == pointer to testHeap
	HEAP_NODE testNode;

	HEAP_CONSTRUCTOR(p);
	testHeap.Create(p, 10);

	testNode.key = 7;
	testNode.data = testPointer+0;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 3;
	testNode.data = testPointer+1;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 62;
	testNode.data = testPointer+2;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 4;
	testNode.data = testPointer+3;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 8;
	testNode.data = testPointer+4;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 13;
	testNode.data = testPointer+5;
	testHeap.Enqueue(p, &testNode);
	
	testNode.key = 1;
	testNode.data = testPointer+6;
	testHeap.Enqueue(p, &testNode);

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testNode.data != testPointer + 6){
		UNIT_TEST_FAIL;
DEBUG("%d\n", *(int *)testNode.data);
DEBUG("%d\n", testNode.key);
		return -2;
	}

	testHeap.Destroy(p);
	HEAP_DESTRUCTOR(p);
	return 0;
}

int UnitTest_Graph(void)
{
	return 0;
}

int UnitTest_Prim(void)
{
	return 0;
}
