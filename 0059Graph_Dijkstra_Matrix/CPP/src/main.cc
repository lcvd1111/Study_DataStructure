#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;

	err = UnitTest_Dijkstra();
	if (err){
		std::cout << "Unit Test for Dijkstra Algorithm: FAIL" << std::endl;
		std::cout << "Error Code: " << err << std::endl; 
		return -1;
	}
	std::cout << "Unit Test for Dijkstra Algorithm: SUCCESS" << std::endl;

	return 0;
}
