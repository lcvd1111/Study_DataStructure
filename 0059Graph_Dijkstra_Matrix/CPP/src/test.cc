#include "test.hh"
#include "lib_graph.hh"

int UnitTest_Dijkstra(void)
{
	GRAPH testGraph;
	testGraph.Create(7);

	testGraph.AddEdge(0, 1, 3);
	testGraph.AddEdge(0, 2, 7);
	testGraph.AddEdge(0, 3, 10);
	testGraph.AddEdge(1, 2, 2);
	testGraph.AddEdge(2, 3, 6);
	testGraph.AddEdge(1, 5, 5);
	testGraph.AddEdge(1, 6, 11);
	testGraph.AddEdge(2, 6, 10);
	testGraph.AddEdge(2, 4, 4);
	testGraph.AddEdge(3, 6, 9);
	testGraph.AddEdge(5, 6, 4);
	testGraph.AddEdge(4, 6, 2);

	testGraph.Dijkstra(1);
	std::cout << std::endl;
	testGraph.Dijkstra(0);

	testGraph.Destroy();
	return 0;
}
