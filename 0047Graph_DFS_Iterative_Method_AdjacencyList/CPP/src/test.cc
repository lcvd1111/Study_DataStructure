#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;

	testGraph.Create(5);
	testGraph.AddEdge(0, 1);
	testGraph.AddEdge(0, 2);
	testGraph.AddEdge_Directed(1, 2);
	//testGraph.Print();

	testGraph.Destroy();

	return 0;
}

int UnitTest_DFS_1_Undirected(void)
{
	GRAPH testGraph;
	std::vector<int> outputStore({});
	std::vector<int> &pOutputStore = outputStore;

	testGraph.Create(7);

	testGraph.AddEdge(0, 1);
	testGraph.AddEdge(0, 2);
	testGraph.AddEdge(1, 2);
	testGraph.AddEdge(1, 3);
	testGraph.AddEdge(1, 4);
	testGraph.AddEdge(1, 6);
	testGraph.AddEdge(5, 6);

	testGraph.DFS_1(pOutputStore);

	if (outputStore[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (outputStore[1] != 2){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (outputStore[2] != 1){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (outputStore[3] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (outputStore[4] != 5){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (outputStore[5] != 4){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (outputStore[6] != 3){
		UNIT_TEST_FAIL;
		return -7;
	}

	return 0;
}

int UnitTest_DFS_1_Directed(void)
{
	GRAPH testGraph;
	std::vector<int> outputBuffer({});
	std::vector<int> &pOutputBuffer = outputBuffer;

	testGraph.Create(8);
	testGraph.AddEdge_Directed(0, 1);
	testGraph.AddEdge_Directed(0, 2);
	testGraph.AddEdge_Directed(2, 3);
	testGraph.AddEdge_Directed(2, 4);
	testGraph.AddEdge_Directed(2, 7);
	testGraph.AddEdge_Directed(5, 6);
	testGraph.AddEdge_Directed(6, 2);
	testGraph.AddEdge_Directed(6, 7);
	testGraph.AddEdge_Directed(7, 6);
	//testGraph.Print(&testGraph);

	testGraph.DFS_1(pOutputBuffer);

	if (outputBuffer[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (outputBuffer[1] != 2){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (outputBuffer[2] != 7){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (outputBuffer[3] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (outputBuffer[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (outputBuffer[5] != 3){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (outputBuffer[6] != 1){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (outputBuffer[7] != 0){
		UNIT_TEST_FAIL;
		return -8;
	}

	return 0;
}

int UnitTest_DFS_2_Undirected(void)
{
	GRAPH testGraph;
	std::vector<int> DFS_output({});
	std::vector<int> &pDFS_output = DFS_output;

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
	
	testGraph.DFS_2(pDFS_output);
	
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

int UnitTest_DFS_2_Directed(void)
{
	GRAPH testGraph;
	std::vector<int> DFS_output({});
	std::vector<int> &pDFS_output = DFS_output;

	testGraph.Create(8);
	testGraph.AddEdge_Directed(0, 1);
	testGraph.AddEdge_Directed(0, 2);
	testGraph.AddEdge_Directed(2, 3);
	testGraph.AddEdge_Directed(2, 4);
	testGraph.AddEdge_Directed(2, 7);
	testGraph.AddEdge_Directed(5, 6);
	testGraph.AddEdge_Directed(6, 2);
	testGraph.AddEdge_Directed(6, 7);
	testGraph.AddEdge_Directed(7, 6);

	testGraph.DFS_2(pDFS_output);

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

	if (DFS_output[3] != 3){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (DFS_output[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (DFS_output[5] != 7){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (DFS_output[6] != 6){
		UNIT_TEST_FAIL;
		return -7;
	}

	return 0;
}
