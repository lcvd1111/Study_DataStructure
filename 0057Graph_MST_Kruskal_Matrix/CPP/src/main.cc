#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;

	err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: FAIL." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: SUCCESS." << std::endl;

	err = UnitTest_UnionFind();
	if (err){
		std::cout << "Unit Test for Union-Find: FAIL." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Union-Find: SUCCESS." << std::endl;

	err = UnitTest_Kruskal();
	if (err){
		std::cout << "Unit Test for Kruskal Algorithm: FAIL." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Kruskal Algorithm: SUCCESS." << std::endl;

	return 0;
}
