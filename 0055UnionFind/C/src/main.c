#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_UnionFind();
	if (err){
		printf("Unit Test for Union-Find: Success.\n");
		printf("Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Union-Find: Success.\n");

	return 0;
}
