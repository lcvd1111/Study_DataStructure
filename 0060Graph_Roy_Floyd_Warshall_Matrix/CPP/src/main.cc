#include "test.hh"

int main(int argc, char **argv)
{
	int err = UnitTest_Graph();

	if (err){
		std::cout << "Unit Test for Graph: Faild." << std::endl;
		std::cout << "Error Code: %d" << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_FloydWarshall();
	if (err){
		std::cout << "Unit Test for Floyd-Warshall Algorithm: Faild." << std::endl;
		std::cout << "Error Code: %d" << err << std::endl;
		return -2;
	}
	std::cout << "Unit Test for Floyd-Warshall Algorithm: Success." << std::endl;

	return 0;
}
