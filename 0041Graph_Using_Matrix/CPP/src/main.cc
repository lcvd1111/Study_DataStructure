#include "common.hh"

int main(int argc, char **argv)
{
	int err = UnitTest_Graph();
	if (err){
		std::cout << "Unit Test for Graph: Fail." << std::endl
			<< "Error code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph: Success." << std::endl;

	return 0;
}
