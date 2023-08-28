#include "common.hh"

int main(int argc, char **argv)
{
	int err = 0;
	if (err = UnitTest_Heap()){
		std::cout << "Unit Test for Heap: Fail." << std::endl
					<< "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Heap: Success." << std::endl;

	return 0;
}
