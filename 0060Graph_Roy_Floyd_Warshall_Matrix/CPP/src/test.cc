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
	return 0;
}
