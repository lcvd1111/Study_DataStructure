#include "test.h"
#include "lib_unionfind.h"
#include "lib_heap.h"
#include "lib_graph.h"

int UnitTest_UnionFind(void)
{
	UNION_FIND testUF;
	UNION_FIND_CONSTRUCTOR(&testUF);
	UNION_FIND *p = &testUF;

	testUF.Create(p, 5);
	if (testUF.Same(p, 0, 1) != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testUF.Same(p, 0, 2) != 0){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testUF.Same(p, 0, 3) != 0){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testUF.Same(p, 1, 2) != 0){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testUF.Same(p, 1, 3) != 0){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testUF.Same(p, 2, 3) != 0){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testUF.Unite(p, 0, 4) != &testUF){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testUF.Unite(p, 0, 3) != &testUF){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testUF.Same(p, 3, 4) != 1){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testUF.Same(p, 0, 4) != 1){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testUF.Same(p, 0, 3) != 1){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testUF.Same(p, 1, 3) != 0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testUF.Same(p, 2, 3) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Same(p, 1, 2) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Unite(p, 0, 3) != NULL){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testUF.Unite(p, 1, 2) != &testUF){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testUF.Unite(p, 1, 2) != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testUF.Size(p, 0) != 3){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testUF.Size(p, 1) != 2){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testUF.Size(p, 2) != 2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testUF.Size(p, 3) != 3){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testUF.Size(p, 4) != 3){
		UNIT_TEST_FAIL;
		return -22;
	}

	testUF.Destroy(p);
	UNION_FIND_DESTRUCTOR(p);
	p = NULL;

	return 0;
}

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
	testGraph.AddEdge_Directed(&testGraph, 2, 3, 15);

	//testGraph.Print(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_Kruskal(void)
{
	GRAPH inputGraph, MST;
	GRAPH_CONSTRUCTOR(&inputGraph);
	GRAPH_CONSTRUCTOR(&MST);

	inputGraph.Create(&inputGraph, 5);
	inputGraph.AddEdge(&inputGraph, 0, 1, 30);
	inputGraph.AddEdge(&inputGraph, 0, 2, 70);
	inputGraph.AddEdge(&inputGraph, 0, 3, 61);
	inputGraph.AddEdge(&inputGraph, 0, 4, 83);
	inputGraph.AddEdge(&inputGraph, 1, 2, 41);
	inputGraph.AddEdge(&inputGraph, 1, 3, 55);
	inputGraph.AddEdge(&inputGraph, 1, 4, 25);
	inputGraph.AddEdge(&inputGraph, 2, 3, 35);
	inputGraph.AddEdge(&inputGraph, 2, 4, 43);
	inputGraph.AddEdge(&inputGraph, 3, 4, 60);

	inputGraph.Kruskal(&inputGraph, &MST);

	printf("[Given Graph]\n");
	inputGraph.Print(&inputGraph);
	printf("\n[MST]\n");
	MST.Print(&MST);

	GRAPH_DESTRUCTOR(&inputGraph);
	GRAPH_DESTRUCTOR(&MST);
	return 0;
}
