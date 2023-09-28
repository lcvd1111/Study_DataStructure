#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE *qp = &testQueue;
	QUEUE_CONSTRUCTOR(&testQueue);
	int sampleInt = 0;
	int dequeueBuffer = -1;
	int *P_dequeueBuffer = &dequeueBuffer;

	if (testQueue.CreateQueue(qp, 5) != qp){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Enqueue(qp, sampleInt+0) != qp){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != NULL){
		UNIT_TEST_FAIL;
		return -5;
	}

	for (int i=0; i<5; i++){
		if (testQueue.Enqueue(qp, sampleInt+i) != qp){
			UNIT_TEST_FAIL;
			return -6-i;
		}
	}

	if (testQueue.Enqueue(qp, sampleInt+0) != NULL){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (dequeueBuffer != sampleInt+0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (dequeueBuffer != sampleInt+1){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testQueue.Enqueue(qp, sampleInt) != qp){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testQueue.Enqueue(qp, sampleInt+1) != qp){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testQueue.Enqueue(qp, sampleInt+0) != NULL){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (dequeueBuffer != sampleInt+2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (dequeueBuffer != sampleInt+3){
		UNIT_TEST_FAIL;
		return -22;
	}


	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (dequeueBuffer != sampleInt+4){
		UNIT_TEST_FAIL;
		return -24;
	}


	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (dequeueBuffer != sampleInt){
		UNIT_TEST_FAIL;
		return -26;
	}


	if (testQueue.Dequeue(qp, P_dequeueBuffer) != qp){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (dequeueBuffer != sampleInt+1){
		UNIT_TEST_FAIL;
		return -28;
	}


	if (testQueue.Dequeue(qp, P_dequeueBuffer) != NULL){
		UNIT_TEST_FAIL;
		return -29;
	}

	QUEUE_DESTRUCTOR(qp);

	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.CreateGraph(&testGraph, 5);
	//testGraph.Print(&testGraph);
	testGraph.AddEdge(&testGraph, 0, 3);
	//testGraph.Print(&testGraph);
	testGraph.AddEdge_Directed(&testGraph, 1,4);
	//testGraph.Print(&testGraph);
	testGraph.DestroyGraph(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);
	
	return 0;
}

int UnitTest_BFS_Undirected(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);

	int *BFS_result = NULL;

	testGraph.CreateGraph(&testGraph, 10);
	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 6);
	testGraph.AddEdge(&testGraph, 0, 9);
	testGraph.AddEdge(&testGraph, 1, 5);
	testGraph.AddEdge(&testGraph, 1, 7);
	testGraph.AddEdge(&testGraph, 2, 8);
	testGraph.AddEdge(&testGraph, 2, 4);
	testGraph.AddEdge(&testGraph, 4, 7);
	testGraph.AddEdge(&testGraph, 3, 8);

	//testGraph.Print(&testGraph);

	BFS_result = testGraph.Create_BFS_Buffer(&testGraph);

	if (testGraph.BFS(&testGraph, BFS_result) != &testGraph){
		UNIT_TEST_FAIL;
		return -1;
	}

	//for (int i=0; i<testGraph.size ; i++){printf("%d->", BFS_result[i]);}printf("END.\n");

	if (BFS_result[0] != 0){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (BFS_result[1] != 1){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (BFS_result[2] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (BFS_result[3] != 9){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (BFS_result[4] != 5){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (BFS_result[5] != 7){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (BFS_result[6] != 4){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (BFS_result[7] != 2){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (BFS_result[8] != 8){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (BFS_result[9] != 3){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testGraph.Release_BFS_Buffer(&testGraph, BFS_result) != 0){
		UNIT_TEST_FAIL;
		return -2;
	}

	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_BFS_Directed(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *BFS_result = NULL;

	testGraph.CreateGraph(&testGraph, 10);
	testGraph.AddEdge_Directed(&testGraph, 0, 1);
	testGraph.AddEdge_Directed(&testGraph, 0, 9);
	testGraph.AddEdge_Directed(&testGraph, 3, 0);
	testGraph.AddEdge_Directed(&testGraph, 2, 1);
	testGraph.AddEdge_Directed(&testGraph, 1, 6);
	testGraph.AddEdge_Directed(&testGraph, 3, 5);
	testGraph.AddEdge_Directed(&testGraph, 9, 5);
	testGraph.AddEdge_Directed(&testGraph, 7, 9);
	testGraph.AddEdge_Directed(&testGraph, 4, 3);
	testGraph.AddEdge_Directed(&testGraph, 4, 7);
	testGraph.AddEdge_Directed(&testGraph, 9, 8);
	testGraph.AddEdge_Directed(&testGraph, 8, 4);

	BFS_result = testGraph.Create_BFS_Buffer(&testGraph);

	testGraph.BFS(&testGraph, BFS_result);

	if (BFS_result[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (BFS_result[1] != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (BFS_result[2] != 9){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (BFS_result[3] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (BFS_result[4] != 5){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (BFS_result[5] != 8){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (BFS_result[6] != 4){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (BFS_result[7] != 3){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (BFS_result[8] != 7){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (BFS_result[9] != -1){
		UNIT_TEST_FAIL;
		return -10;
	}

	testGraph.Release_BFS_Buffer(&testGraph, BFS_result);
	testGraph.DestroyGraph(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}
