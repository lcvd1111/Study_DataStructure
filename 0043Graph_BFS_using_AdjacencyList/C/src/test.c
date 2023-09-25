#include "common.h"
#include "test.h"

int UnitTest_Queue(void)
{
	QUEUE testQueue;
	QUEUE *qp = &testQueue;
	QUEUE_CONSTRUCTOR(&testQueue);
	int sampleArray[5]={0,};
	void *dequeueBuffer = NULL;
	void **vp = &dequeueBuffer;

	if (testQueue.CreateQueue(qp, 5) != qp){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testQueue.Dequeue(qp, vp) != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != qp){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testQueue.Dequeue(qp, vp) != NULL){
		UNIT_TEST_FAIL;
		return -5;
	}

	for (int i=0; i<5; i++){
		if (testQueue.Enqueue(qp, sampleArray+i) != qp){
			UNIT_TEST_FAIL;
			return -6-i;
		}
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != NULL){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (dequeueBuffer != sampleArray+0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (dequeueBuffer != sampleArray+1){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testQueue.Enqueue(qp, sampleArray) != qp){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testQueue.Enqueue(qp, sampleArray+1) != qp){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testQueue.Enqueue(qp, sampleArray+0) != NULL){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (dequeueBuffer != sampleArray+2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (dequeueBuffer != sampleArray+3){
		UNIT_TEST_FAIL;
		return -22;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (dequeueBuffer != sampleArray+4){
		UNIT_TEST_FAIL;
		return -24;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (dequeueBuffer != sampleArray){
		UNIT_TEST_FAIL;
		return -26;
	}


	if (testQueue.Dequeue(qp, vp) != qp){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (dequeueBuffer != sampleArray+1){
		UNIT_TEST_FAIL;
		return -28;
	}


	if (testQueue.Dequeue(qp, vp) != NULL){
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

	if (testGraph.DestroyGraph(&testGraph) != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testGraph.CreateGraph(&testGraph, 3) != &testGraph){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testGraph.CreateGraph(&testGraph, 6) != NULL){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testGraph.DestroyGraph(&testGraph) != &testGraph){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testGraph.CreateGraph(&testGraph, 5) != &testGraph){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testGraph.nodeArray[0].node_id != 0){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testGraph.nodeArray[1].node_id != 1){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testGraph.nodeArray[2].node_id != 2){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testGraph.nodeArray[3].node_id != 3){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testGraph.nodeArray[4].node_id != 4){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testGraph.AddEdge(&testGraph, 0, 3) != &testGraph){
		UNIT_TEST_FAIL;
		return -11;
	}

	if ((testGraph.nodeArray[0].next)->node_id != 3){
		UNIT_TEST_FAIL;
		return -12;
	}

	if ((testGraph.nodeArray[3].next)->node_id != 0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testGraph.AddEdge(&testGraph, 0, 2) != &testGraph){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testGraph.nodeArray[2].next->node_id != 0){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testGraph.nodeArray[0].next->next->node_id != 2){
		UNIT_TEST_FAIL;
		return -16;
	}

	//testGraph.Print(&testGraph);

	GRAPH_DESTRUCTOR(&testGraph);

	if (testGraph.nodeArray != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}

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

	testGraph.BFS(&testGraph, BFS_result);

	testGraph.Release_BFS_Buffer(&testGraph, BFS_result);
	testGraph.DestroyGraph(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}
