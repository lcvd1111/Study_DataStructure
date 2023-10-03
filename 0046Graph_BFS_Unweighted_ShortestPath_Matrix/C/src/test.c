#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE_CONSTRUCTOR(&testQueue);
	int outputStore = -1;

	testQueue.Create(&testQueue, 5);

	if (testQueue.Dequeue(&testQueue, &outputStore) != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Enqueue(&testQueue, 1) != &testQueue){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Enqueue(&testQueue, 2) != &testQueue){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testQueue.Enqueue(&testQueue, 3) != &testQueue){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Enqueue(&testQueue, 4) != &testQueue){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testQueue.Enqueue(&testQueue, 5) != &testQueue){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testQueue.Enqueue(&testQueue, 1) != NULL){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (outputStore != 1){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testQueue.Enqueue(&testQueue, 1) != &testQueue){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (outputStore != 2){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (outputStore != 3){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (outputStore != 4){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (outputStore != 5){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != &testQueue){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (outputStore != 1){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testQueue.Dequeue(&testQueue, &outputStore) != NULL){
		UNIT_TEST_FAIL;
		return -21;
	}

	QUEUE_DESTRUCTOR(&testQueue);
	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 10);
	testGraph.AddEdge(&testGraph, 0, 3);
	testGraph.AddEdge(&testGraph, 0, 4);
	testGraph.AddEdge_Directed(&testGraph, 1, 5);
	//testGraph.Print(&testGraph);

	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_ShortestPath_BFS(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 12);
	int *path = NULL;
	int result = 0;

	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 6);
	testGraph.AddEdge(&testGraph, 0, 4);
	testGraph.AddEdge(&testGraph, 1, 4);
	testGraph.AddEdge(&testGraph, 2, 5);
	testGraph.AddEdge(&testGraph, 2, 6);
	testGraph.AddEdge(&testGraph, 3, 4);
	testGraph.AddEdge(&testGraph, 3, 6);
	testGraph.AddEdge(&testGraph, 5, 10);
	testGraph.AddEdge(&testGraph, 6, 8);
	testGraph.AddEdge(&testGraph, 6, 9);
	testGraph.AddEdge(&testGraph, 7, 9);
	testGraph.AddEdge(&testGraph, 7, 11);
	testGraph.AddEdge(&testGraph, 8, 10);
	testGraph.AddEdge(&testGraph, 10, 11);

	path = (int *)malloc(sizeof(int)*(12));
	memset(path, 1, sizeof(int)*12);

	result = testGraph.BFS_ShortestPath(&testGraph, path, 0, 10);
	for (int i=0; i<result+1 ; i++){
		printf("%d ", path[result-i]);
	}
	printf("\nLength:%d\n", result);

	free(path);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}
