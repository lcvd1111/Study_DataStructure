#include "test.hh"

int main(int argc, char **argv)
{
	int err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Failed." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_Prim();
	if (err){
		std::cout << "Unit Test for Prim MST: Failed." << std::endl;
		std::cout << "Error code: " << err << std::endl;
		return -2;
	}
	std::cout << "Unit Test for Prim MST: Success." << std::endl;

	return 0;
}
