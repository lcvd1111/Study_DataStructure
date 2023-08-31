#include "common.hh"

int main(int argc, char **argv)
{
	int err = 0;
	if (err=UnitTest_StablePriorityQueue()){
		std::cout << "Unit Test for Stable Priority Queue: Fail." << std::endl;
		std::cout << "Err code: " << err << std::endl;
		return -1;
	}

	std::cout << "Unit Test for Stable Priority Queue: Success." << std::endl;

	return 0;
}
