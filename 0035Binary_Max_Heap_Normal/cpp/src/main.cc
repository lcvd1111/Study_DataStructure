#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;
	if (err = UnitTest_BinaryMaxHeap()){
		std::cout << "Unit Test for Binary Max Heap Failed." << std::endl
					<< "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Binary Max Heap succeeded." << std::endl;

	return 0;
}
