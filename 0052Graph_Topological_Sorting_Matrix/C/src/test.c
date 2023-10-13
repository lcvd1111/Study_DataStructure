#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE *pTestQueue = &testQueue;
	QUEUE_CONSTRUCTOR(pTestQueue);
	
	int dequeueBuffer = 0;

	int testInteger = 1;

	testQueue.Create(pTestQueue, 50);

	if (testQueue.Empty(pTestQueue) != 1){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Enqueue(pTestQueue, testInteger) != pTestQueue){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Peek(pTestQueue) != testInteger){
		UNIT_TEST_FAIL;
		return -3;
	}
	
	if (testQueue.Enqueue(pTestQueue, testInteger+1) != pTestQueue){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Enqueue(pTestQueue, testInteger+2) != pTestQueue){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testQueue.Dequeue(pTestQueue, &dequeueBuffer) != pTestQueue){
		UNIT_TEST_FAIL;
		return -6;
	}
	
	if (dequeueBuffer != testInteger){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testQueue.Peek(pTestQueue) != testInteger+1){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testQueue.Dequeue(pTestQueue, &dequeueBuffer) != pTestQueue){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (dequeueBuffer != testInteger + 1){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testQueue.Peek(pTestQueue) != testInteger+2){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testQueue.Dequeue(pTestQueue, &dequeueBuffer) != pTestQueue){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (dequeueBuffer != testInteger + 2){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testQueue.Peek(pTestQueue) != -1){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testQueue.Empty(pTestQueue) != 1){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testQueue.Dequeue(pTestQueue, &dequeueBuffer) != NULL){
		UNIT_TEST_FAIL;
		return -16;
	}

	testQueue.Destroy(pTestQueue);

	QUEUE_DESTRUCTOR(pTestQueue);

	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH *pTestGraph = &testGraph;
	GRAPH_CONSTRUCTOR(pTestGraph);

	testGraph.Create(pTestGraph, 5);
	testGraph.AddEdge(pTestGraph, 0, 3);
	testGraph.AddEdge_Directed(pTestGraph, 1, 4);
	//testGraph.Print(pTestGraph);

	GRAPH_DESTRUCTOR(pTestGraph);

	return 0;
}

int UnitTest_TopologicalSorting(void)
{
	GRAPH testGraph;
	GRAPH *pTestGraph = &testGraph;
	GRAPH_CONSTRUCTOR(pTestGraph);
	int *output = NULL;

	testGraph.Create(pTestGraph, 10);
	testGraph.AddEdge_Directed(pTestGraph, 0, 4);
	testGraph.AddEdge_Directed(pTestGraph, 1, 2);
	testGraph.AddEdge_Directed(pTestGraph, 1, 5);
	testGraph.AddEdge_Directed(pTestGraph, 1, 6);
	testGraph.AddEdge_Directed(pTestGraph, 2, 0);
	testGraph.AddEdge_Directed(pTestGraph, 2, 3);
	testGraph.AddEdge_Directed(pTestGraph, 3, 0);
	testGraph.AddEdge_Directed(pTestGraph, 5, 6);
	testGraph.AddEdge_Directed(pTestGraph, 5, 8);
	testGraph.AddEdge_Directed(pTestGraph, 6, 4);
	testGraph.AddEdge_Directed(pTestGraph, 6, 9);
	testGraph.AddEdge_Directed(pTestGraph, 8, 7);
	testGraph.AddEdge_Directed(pTestGraph, 9, 7);

	output = (int *)malloc(sizeof(int)*(testGraph.size));
	memset(output, 0, sizeof(int)*(testGraph.size));

	testGraph.TopologicalSorting(pTestGraph, output);

	if (output[0] != 1){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (output[1] != 2){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (output[2] != 5){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (output[3] != 3){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (output[4] != 6){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (output[5] != 8){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (output[6] != 0){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (output[7] != 9){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (output[8] != 4){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (output[9] != 7){
		UNIT_TEST_FAIL;
		return -10;
	}

	free(output);
	testGraph.Destroy(pTestGraph);
	GRAPH_DESTRUCTOR(pTestGraph);

	return 0;
}
