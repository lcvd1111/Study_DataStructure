#include "common.hh"
#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Success." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_TopologicalSort();
	if (err){
		std::cout << "Unit Test for Topological Sorting of Graph: Fail." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -2;
	}
	std::cout << "Unit Test for Topological Sorting of Graph: Success." << std::endl;

	return 0;
}
