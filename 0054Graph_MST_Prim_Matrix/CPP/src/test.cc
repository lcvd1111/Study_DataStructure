#include "test.hh"
#include "lib_graph.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	testGraph.Create(5);

	testGraph.AddEdge(0,3,5);
	testGraph.AddEdge(1,4,3);

	//testGraph.Print();

	if (testGraph.Weight() != 8){
		UNIT_TEST_FAIL;
		return -1;
	}

	testGraph.Destroy();
	return 0;
}

int UnitTest_Prim(void)
{
	GRAPH testGraph;
	GRAPH testMST;

	testGraph.Create(7);
	testGraph.AddEdge(0, 3, 3);
	testGraph.AddEdge(0, 4, 1);
	testGraph.AddEdge(1, 2, 5);
	testGraph.AddEdge(1, 4, 7);
	testGraph.AddEdge(1, 6, 13);
	testGraph.AddEdge(2, 5, 8);
	testGraph.AddEdge(3, 6, 9);
	testGraph.AddEdge(4, 5, 6);
	testGraph.AddEdge(5, 6, 4);
	if (testGraph.Weight() != 56){
		UNIT_TEST_FAIL;
		return -1;
	}
	
	testMST = testGraph.Prim();

	if (testMST.Weight() != 26){
		UNIT_TEST_FAIL;
		return -2;
	}

	std::cout << "<Given Graph>" << std::endl;
	testGraph.Print();
	std::cout << std::endl << "<Created MST>" << std::endl;
	testMST.Print();

	testGraph.Destroy();
	testMST.Destroy();
	
	return 0;
}
