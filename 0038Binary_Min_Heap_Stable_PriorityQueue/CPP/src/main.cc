#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;
	if (err=UnitTest_StablePriorityQueue_using_MinHeap()){
		std::cout << "Unit Test for Stable Priority Queue: Fail." << std::endl
				<< "Err code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Stable Priority Queue: Success." << std::endl;
	return 0;
}
