#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	testGraph.Create(5);
	testGraph.Destroy();
	return 0;
}

int UnitTest_ShortestPath_Undirected(void)
{
	GRAPH testGraph;
	testGraph.Create(12);
	std::vector<int> pathOutput({});
	std::vector<int> &rPathOutput = pathOutput;
	int result = 0;

	testGraph.AddEdge(0, 1);
	testGraph.AddEdge(0, 6);
	testGraph.AddEdge(0, 4);
	testGraph.AddEdge(1, 4);
	testGraph.AddEdge(2, 5);
	testGraph.AddEdge(2, 6);
	testGraph.AddEdge(3, 4);
	testGraph.AddEdge(3, 6);
	testGraph.AddEdge(5, 10);
	testGraph.AddEdge(6, 8);
	testGraph.AddEdge(6, 9);
	testGraph.AddEdge(7, 9);
	testGraph.AddEdge(7, 11);
	testGraph.AddEdge(8, 10);
	testGraph.AddEdge(10, 11);


	result = testGraph.ShortestPath(0, 10, rPathOutput);

	std::cout << "[Path]: " ;
	for (std::vector<int>::iterator i=pathOutput.begin() ; i!=pathOutput.end() ; i++){
		std::cout << *i << " ";
	}
	std::cout << " ";
	std::cout << "[Length]: " << result << std::endl;

	return 0;

	return 0;
}

int UnitTest_ShortestPath_Directed(void)
{
	std::vector<int> pathOutput;
	std::vector<int> &rPathOutput = pathOutput;
	int result = 0;
	GRAPH testGraph;

	testGraph.Create(6);
	testGraph.AddEdge_Directed(0,1);
	testGraph.AddEdge_Directed(0,2);
	testGraph.AddEdge_Directed(1,5);
	testGraph.AddEdge_Directed(2,4);
	testGraph.AddEdge_Directed(3,0);
	testGraph.AddEdge_Directed(4,5);
	testGraph.AddEdge_Directed(5,0);

	result = testGraph.ShortestPath(0, 5, rPathOutput);

	std::cout << "[Path]: " ;
	for (std::vector<int>::iterator i=pathOutput.begin() ; i!=pathOutput.end() ; i++){
		std::cout << *i << " ";
	}
	std::cout << " ";
	std::cout << "[Length]: " << result << std::endl;

	return 0;

	return 0;
}
