#include "test.h"
#include "lib_heap.h"
#include "lib_graph.h"

int UnitTest_Heap(void)
{
	HEAP testHeap;
	HEAP *pTestHeap = &testHeap;
	HEAP_CONSTRUCTOR(pTestHeap);
	testHeap.Create(pTestHeap, 10);

	HEAP_NODE nodeBuffer;

	if (testHeap.entireSize != 1023){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testHeap.Dequeue(pTestHeap)!=NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	nodeBuffer.key = 150;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);

	nodeBuffer.key = 300;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 50;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 200;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 360;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 180;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 70;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 95;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 50;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);
	
	nodeBuffer.key = 70;
	testHeap.Enqueue(pTestHeap, &nodeBuffer);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 50){
		UNIT_TEST_FAIL;
		return -3;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 50){
		UNIT_TEST_FAIL;
		return -4;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 70){
		UNIT_TEST_FAIL;
		return -5;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 70){
		UNIT_TEST_FAIL;
		return -6;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 95){
		UNIT_TEST_FAIL;
		return -7;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 150){
		UNIT_TEST_FAIL;
		return -8;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 180){
		UNIT_TEST_FAIL;
		return -9;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 200){
		UNIT_TEST_FAIL;
		return -10;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 300){
		UNIT_TEST_FAIL;
		return -11;
	}
	testHeap.Dequeue(pTestHeap);

	testHeap.Peek(pTestHeap, &nodeBuffer);
	if (nodeBuffer.key != 360){
		UNIT_TEST_FAIL;
		return -12;
	}
	testHeap.Dequeue(pTestHeap);


	testHeap.Destroy(pTestHeap);
	HEAP_DESTRUCTOR(pTestHeap);

	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 2, 15);
	testGraph.AddEdge(&testGraph, 0, 4, 30);
	testGraph.AddEdge(&testGraph, 1, 2, 50);
	testGraph.AddEdge_Directed(&testGraph, 2, 3, 77);

	//testGraph.Print(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_Dijkstra(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 1, 17);
	testGraph.AddEdge(&testGraph, 0, 2, 50);
	testGraph.AddEdge(&testGraph, 0, 3, 36);
	testGraph.AddEdge(&testGraph, 0, 4, 20);
	testGraph.AddEdge(&testGraph, 1, 2, 12);
	testGraph.AddEdge(&testGraph, 1, 3, 30);
	testGraph.AddEdge(&testGraph, 1, 4, 37);
	testGraph.AddEdge(&testGraph, 2, 3, 3);
	testGraph.AddEdge(&testGraph, 2, 4, 43);
	testGraph.AddEdge(&testGraph, 3, 4, 9);

	testGraph.Print(&testGraph);
	testGraph.Dijkstra(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}
