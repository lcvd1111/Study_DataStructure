#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE_CONSTRUCTOR(&testQueue);
	testQueue.Create(&testQueue, 5);

	char testPointer[5] = {0,};
	void *popOutput = NULL;

	if (testQueue.Dequeue(&testQueue, &popOutput) != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Enqueue(&testQueue, testPointer) != &testQueue){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Enqueue(&testQueue, testPointer+1) != &testQueue){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testQueue.Enqueue(&testQueue, testPointer+2) != &testQueue){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Enqueue(&testQueue, testPointer+3) != &testQueue){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testQueue.Enqueue(&testQueue, testPointer+4) != &testQueue){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testQueue.Enqueue(&testQueue, testPointer) != NULL){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (popOutput != (void *)(testPointer)){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testQueue.Enqueue(&testQueue, testPointer) != &testQueue){
		UNIT_TEST_FAIL;
		return -111;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (popOutput != (void *)(testPointer+1)){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (popOutput != (void *)(testPointer+2)){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (popOutput != (void *)(testPointer+3)){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (popOutput != (void *)(testPointer+4)){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != &testQueue){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (popOutput != (void *)(testPointer)){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testQueue.Dequeue(&testQueue, &popOutput) != NULL){
		UNIT_TEST_FAIL;
		return -20;
	}

	testQueue.Destroy(&testQueue);
	QUEUE_DESTRUCTOR(&testQueue);
	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 2);
	testGraph.AddEdge(&testGraph, 0, 3);
	testGraph.AddEdge_Directed(&testGraph, 1, 4);

	//testGraph.Print(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_ShortestPath(void)
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
