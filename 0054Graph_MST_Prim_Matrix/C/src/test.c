#include "test.h"

int UnitTest_Heap(void)
{
	int testValue = 0;
	HEAP testHeap;
	HEAP *p = &testHeap; //p == pTestHeap == pointer to testHeap
	HEAP_NODE testNode;

	HEAP_CONSTRUCTOR(p);
	testHeap.Create(p, 10);

	testNode.key = 7;
	testNode.node_id = testValue+0;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 3;
	testNode.node_id = testValue+1;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 62;
	testNode.node_id = testValue+2;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 4;
	testNode.node_id = testValue+3;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 8;
	testNode.node_id = testValue+4;
	testHeap.Enqueue(p, &testNode);

	testNode.key = 13;
	testNode.node_id = testValue+5;
	testHeap.Enqueue(p, &testNode);
	
	testNode.key = 1;
	testNode.node_id = testValue+6;
	testHeap.Enqueue(p, &testNode);

	if (testHeap.lastIndex != 6){
		UNIT_TEST_FAIL;
		return -999;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testNode.node_id != testValue + 6){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testNode.node_id != testValue + 1){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testNode.node_id != testValue + 3){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testNode.node_id != testValue + 0){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testNode.node_id != testValue + 4){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testNode.node_id != testValue + 5){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testHeap.Dequeue(p, &testNode) != p){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testNode.node_id != testValue + 2){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testHeap.Dequeue(p, &testNode) != NULL){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testHeap.Empty(p) != 1){
		UNIT_TEST_FAIL;
		return -16;
	}

	testHeap.Destroy(p);
	HEAP_DESTRUCTOR(p);

	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 3, 5);
	testGraph.AddEdge(&testGraph, 0, 4, 3);
	testGraph.AddEdge(&testGraph, 4, 1, 2);

	//testGraph.Print(&testGraph);

	if (testGraph.Weight(&testGraph) != 10){
		UNIT_TEST_FAIL;
		return -1;
	}

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_Prim(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	GRAPH testMST;
	GRAPH_CONSTRUCTOR(&testMST);

	testGraph.Create(&testGraph, 7);
	testGraph.AddEdge(&testGraph, 0, 3, 3);
	testGraph.AddEdge(&testGraph, 0, 4, 1);
	testGraph.AddEdge(&testGraph, 1, 2, 5);
	testGraph.AddEdge(&testGraph, 1, 4, 7);
	testGraph.AddEdge(&testGraph, 1, 6, 13);
	testGraph.AddEdge(&testGraph, 2, 5, 8);
	testGraph.AddEdge(&testGraph, 3, 6, 9);
	testGraph.AddEdge(&testGraph, 4, 5, 6);
	testGraph.AddEdge(&testGraph, 5, 6, 4);
	if (testGraph.Weight(&testGraph) != 56){
		UNIT_TEST_FAIL;
		return -1;
	}
	
	testGraph.Prim(&testGraph, &testMST);

	if (testMST.Weight(&testMST) != 26){
		UNIT_TEST_FAIL;
		return -2;
	}

	printf("<Given Graph>\n");
	testGraph.Print(&testGraph);
	printf("\n<Created MST>\n");
	testMST.Print(&testMST);

	testGraph.Destroy(&testGraph);
	testMST.Destroy(&testMST);
	
	GRAPH_DESTRUCTOR(&testGraph);
	GRAPH_DESTRUCTOR(&testMST);

	return 0;
}
