#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Failed." << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_ShortestPath_Undirected();
	if (err){
		std::cout << "Unit Test for Finding Shortest path of Undirected Graph: Failed." << std::endl;
		return -2;
	}
	std::cout << "Unit Test for Finding Shortest path of Undirected Graph: Success." << std::endl;

	err = UnitTest_ShortestPath_Directed();
	if (err){
		std::cout << "Unit Test for Finding Shortest path of Directed Graph: Failed." << std::endl;
		return -3;
	}
	std::cout << "Unit Test for Finding Shortest path of Directed Graph: Success." << std::endl;

	return 0;
}
