#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_UnionFind();
	if (err){
		std::cout << "Unit Test for Union-Find: Fail." << std::endl;
		std::cout << "Error Code: " << err << std::endl;
		return -1;
	}
	std::cout << "Unit Test for Union-Find: Success." << std::endl;

	return 0;
}
