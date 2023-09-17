#include "common.hh"

int main(int argc, char **argv)
{
	int err = 0;

	err = UnitTest_Graph_Using_Vector();
	if (err){
		std::cout << "Unit Test for Graph using Vector: Failed." << std::endl << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Graph using Vector: Success." << std::endl << std::endl << std::endl;

	err = UnitTest_Graph_Using_Set();
	if (err){
		std::cout << "Unit Test for Graph using Set: Failed." << std::endl << "Error Code: " << err << std::endl;
			return -1;
	}
	std::cout << "Unit Test for Graph using Set: Success." << std::endl;


	return 0;
}
