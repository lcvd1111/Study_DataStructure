#include "test.h"
#include "lib_graph.h"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 2, 15);
	testGraph.AddEdge(&testGraph, 0, 4, 30);
	testGraph.AddEdge(&testGraph, 1, 2, 50);
	testGraph.AddEdge_Directed(&testGraph, 2, 3, 77);

	//testGraph.Print(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_FloydWarshall(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	testGraph.Create(&testGraph, 5);

	testGraph.AddEdge(&testGraph, 0, 1, 17);
	testGraph.AddEdge(&testGraph, 0, 2, 50);
	testGraph.AddEdge(&testGraph, 0, 3, 36);
	testGraph.AddEdge(&testGraph, 0, 4, 20);
	testGraph.AddEdge(&testGraph, 1, 2, 12);
	testGraph.AddEdge(&testGraph, 1, 3, 30);
	testGraph.AddEdge(&testGraph, 1, 4, 37);
	testGraph.AddEdge(&testGraph, 2, 3, 3);
	testGraph.AddEdge(&testGraph, 2, 4, 43);
	testGraph.AddEdge(&testGraph, 3, 4, 9);

	testGraph.FloydWarshall(&testGraph);

	testGraph.Destroy(&testGraph);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}
