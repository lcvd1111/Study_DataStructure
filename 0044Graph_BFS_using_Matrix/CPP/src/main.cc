#include "common.hh"
#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;

	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Failed." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_BFS_Undirected();
	if (err){
		std::cout << "Unit Test for BFS for Undirected Graph: Failed." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -2;
	}
	std::cout << "Unit Test for BFS for Undirected Graph: Success." << std::endl;


	err = UnitTest_BFS_Directed();
	if (err){
		std::cout << "Unit Test for BFS for Directed Graph: Failed." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -3;
	}
	std::cout << "Unit Test for BFS for Directed Graph: Success." << std::endl;
	
	return 0;
}
