#include "test.hh"

int main(int argc, char **argv)
{
	int err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Fail." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	err = UnitTest_Prim();
	if (err){
		std::cout << "Unit Test for Prim Algorithm: Fail." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Prim Algorithm: Success." << std::endl;

	return 0;
}
