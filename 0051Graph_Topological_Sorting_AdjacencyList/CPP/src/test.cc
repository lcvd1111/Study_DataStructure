#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;

	testGraph.Create(5);
	testGraph.AddEdge(0,2);
	testGraph.AddEdge(0,3);
	testGraph.AddEdge_Directed(1,4);

	//testGraph.Print();

	testGraph.Destroy();
	return 0;
}

int UnitTest_TopologicalSort(void)
{
	GRAPH testGraph;
	std::vector<int> output;
	std::vector<int> &pOutput = output;

	testGraph.Create(10);
	testGraph.AddEdge_Directed(0, 4);
	testGraph.AddEdge_Directed(1, 2);
	testGraph.AddEdge_Directed(1, 5);
	testGraph.AddEdge_Directed(1, 6);
	testGraph.AddEdge_Directed(2, 0);
	testGraph.AddEdge_Directed(2, 3);
	testGraph.AddEdge_Directed(3, 0);
	testGraph.AddEdge_Directed(5, 6);
	testGraph.AddEdge_Directed(5, 8);
	testGraph.AddEdge_Directed(6, 4);
	testGraph.AddEdge_Directed(6, 9);
	testGraph.AddEdge_Directed(8, 7);
	testGraph.AddEdge_Directed(9, 7);

	testGraph.TopologicalSorting(pOutput);

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

	testGraph.Destroy();

	return 0;
}
