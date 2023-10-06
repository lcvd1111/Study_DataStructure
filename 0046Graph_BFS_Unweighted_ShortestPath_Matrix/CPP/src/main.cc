#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Failed." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_ShortestPath_Undirected();
	if (err){
		std::cout << "Unit Test for Finding Shortest Path for Undirected Graph: Fail." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -2;
	}
	std::cout << "Unit Test for Finding Shortest Path for Undirected Graph: Success." << std::endl;

	err = UnitTest_ShortestPath_Directed();
	if (err){
		std::cout << "Unit Test for Finding Shortest Path for Directed Graph: Fail." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -3;
	}
	std::cout << "Unit Test for Finding Shortest Path for Directed Graph: Success." << std::endl;

	return 0;
}
