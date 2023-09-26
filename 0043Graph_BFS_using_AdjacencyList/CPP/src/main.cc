#include "common.hh"
#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Failed." << std::endl
			<< "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_BFS_Undirected();
	if (err){
		std::cout << "Unit Test for BFS of undirected graph: Failed." << std::endl
			<< "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for BFS of undirected graph: Success." << std::endl;


	err = UnitTest_BFS_Directed();
	if (err){
		std::cout << "Unit Test for BFS of directed graph: Failed." << std::endl
			<< "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for BFS of directed graph: Success." << std::endl;



	return 0;
}
