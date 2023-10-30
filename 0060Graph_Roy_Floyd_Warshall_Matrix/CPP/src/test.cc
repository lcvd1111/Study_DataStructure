#include "test.hh"
#include "lib_graph.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;

	testGraph.Create(5);

	testGraph.AddEdge(0, 3, 1);
	testGraph.AddEdge_Directed(0, 2, 5);

	//testGraph.Print();
	testGraph.Destroy();
	return 0;
}

int UnitTest_FloydWarshall(void)
{
	GRAPH testGraph;
	GRAPH distanceGraph;

	testGraph.Create(4);
	testGraph.AddEdge_Directed(0, 1, 1);
	testGraph.AddEdge_Directed(0, 2, 8);
	testGraph.AddEdge_Directed(1, 2, 2);
	testGraph.AddEdge_Directed(1, 3, 9);
	testGraph.AddEdge_Directed(2, 3, 1);
	testGraph.AddEdge_Directed(3, 0, 4);

	testGraph.FloydWarshall(distanceGraph);

	std::cout << "[Distance Matrix]" << std::endl;
	distanceGraph.Print();
	std::cout << std::endl;

	if(testGraph.Destroy()==NULL){
		UNIT_TEST_FAIL;
	}

	if(distanceGraph.Destroy()==NULL){
		UNIT_TEST_FAIL;
	}

	return 0;
}
