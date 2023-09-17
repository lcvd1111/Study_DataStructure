#include "common.hh"

#define FILE_INPUT_TEST

int main(int argc, char **argv)
{
	GRAPH testGraph;
	int nodeNum = 0, edgeNum = 0;
	std::string node_a(""), node_b("");
#ifdef FILE_INPUT_TEST	
	freopen("testInput.txt", "r", stdin);
#endif

#ifndef FILE_INPUT_TEST
	std::cout << "(Vertexes num, Edges num): " ;
#endif
	std::cin >> nodeNum >> edgeNum;

	for (int i=0; i<edgeNum ; i++){
#ifndef FILE_INPUT_TEST
		std::cout << "(Node A, Node B): ";
#endif
		std::cin >> node_a >> node_b;
		testGraph.AddVertex(node_a);
		testGraph.AddVertex(node_b);
		testGraph.AddEdge(node_a, node_b);
	}

	//Printing Graph
	testGraph.Print();

	return 0;
}
