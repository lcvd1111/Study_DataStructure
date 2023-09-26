#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	if (testGraph.nodeArray != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	testGraph.CreateGraph(5);

	testGraph.AddEdge(0,1);
	testGraph.AddEdge(0,2);
	testGraph.AddEdge_Directed(0,3);

	//testGraph.Print();

	testGraph.DestroyGraph();
	if (testGraph.nodeArray != NULL){
		UNIT_TEST_FAIL;
		return -3;
	}

	return 0;
}

int UnitTest_BFS_Undirected(void)
{
	GRAPH testGraph;
	std::vector<int> BFS_result;
	std::vector<int> &BFS_result_ref = BFS_result;

	testGraph.CreateGraph(10);
	testGraph.AddEdge(0, 1);
	testGraph.AddEdge(0, 6);
	testGraph.AddEdge(0, 9);
	testGraph.AddEdge(1, 5);
	testGraph.AddEdge(1, 7);
	testGraph.AddEdge(2, 8);
	testGraph.AddEdge(2, 4);
	testGraph.AddEdge(4, 7);
	testGraph.AddEdge(3, 8);

	//testGraph.Print();

	if (testGraph.BFS(BFS_result_ref) != &testGraph){
		UNIT_TEST_FAIL;
		return -1;
	}

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

	testGraph.DestroyGraph();

	return 0;
}

int UnitTest_BFS_Directed(void)
{
	GRAPH testGraph;
	std::vector<int> BFS_result({});
	std::vector<int> &BFS_result_ref = BFS_result;

	testGraph.CreateGraph(10);
	testGraph.AddEdge_Directed(0, 1);
	testGraph.AddEdge_Directed(0, 9);
	testGraph.AddEdge_Directed(3, 0);
	testGraph.AddEdge_Directed(2, 1);
	testGraph.AddEdge_Directed(1, 6);
	testGraph.AddEdge_Directed(3, 5);
	testGraph.AddEdge_Directed(9, 5);
	testGraph.AddEdge_Directed(7, 9);
	testGraph.AddEdge_Directed(4, 3);
	testGraph.AddEdge_Directed(4, 7);
	testGraph.AddEdge_Directed(9, 8);
	testGraph.AddEdge_Directed(8, 4);

	if (testGraph.BFS(BFS_result_ref) != &testGraph){
		UNIT_TEST_FAIL;
		return -999;
	}

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

	testGraph.DestroyGraph();
	return 0;
}
