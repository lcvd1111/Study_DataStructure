#include "test.h"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.CreateGraph(&testGraph, 10);

	testGraph.AddEdge_Directed(&testGraph, 3,5);
	testGraph.AddEdge(&testGraph, 0,2);
	testGraph.AddEdge(&testGraph, 6,8);

	//testGraph.Print(&testGraph);

	testGraph.DestroyGraph(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_DFS_Undirected(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *DFS_output = NULL;

	testGraph.CreateGraph(&testGraph, 9);
	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 3);
	testGraph.AddEdge(&testGraph, 1, 2);
	testGraph.AddEdge(&testGraph, 1, 4);
	testGraph.AddEdge(&testGraph, 2, 5);
	testGraph.AddEdge(&testGraph, 2, 7);
	testGraph.AddEdge(&testGraph, 3, 8);
	testGraph.AddEdge(&testGraph, 4, 5);
	testGraph.AddEdge(&testGraph, 5, 6);

	
	DFS_output = testGraph.Create_DFS_Buffer(&testGraph);
	testGraph.DFS(&testGraph, DFS_output);

	if (DFS_output[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (DFS_output[1] != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (DFS_output[2] != 2){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (DFS_output[3] != 5){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (DFS_output[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (DFS_output[5] != 6){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (DFS_output[6] != 7){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (DFS_output[7] != 3){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (DFS_output[8] != 8){
		UNIT_TEST_FAIL;
		return -8;
	}

	testGraph.Release_DFS_Buffer(&testGraph, DFS_output);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;

	return 0;
}

int UnitTest_DFS_Directed(void)
{
	return 0;
}
