#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	testGraph.Create(5);
	testGraph.AddEdge_Directed(0,3);
	testGraph.AddEdge(2,4);
	//testGraph.Print();
	return 0;
}

int UnitTest_DFS_Undirected(void)
{
	GRAPH testGraph;
	std::vector<int> DFS_output_Vector({});
	std::vector<int> &DFS_output = DFS_output_Vector;

	testGraph.Create(9);
	testGraph.AddEdge(0, 1);
	testGraph.AddEdge(0, 3);
	testGraph.AddEdge(1, 2);
	testGraph.AddEdge(1, 4);
	testGraph.AddEdge(2, 5);
	testGraph.AddEdge(2, 7);
	testGraph.AddEdge(3, 8);
	testGraph.AddEdge(4, 5);
	testGraph.AddEdge(5, 6);

	testGraph.DFS(DFS_output);

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

	return 0;
}

int UnitTest_DFS_Directed(void)
{
	return 0;
}
