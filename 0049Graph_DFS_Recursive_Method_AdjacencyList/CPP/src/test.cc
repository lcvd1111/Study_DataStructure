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
	return 0;
}

int UnitTest_DFS_Directed(void)
{
	return 0;
}
