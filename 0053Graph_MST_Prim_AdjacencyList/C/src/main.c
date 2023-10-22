#include "test.h"

int main(int argc, char **argv)
{
	int err = UnitTest_Heap();
	if (err){
		printf("Unit Test for Heap: Fail.\n");
		printf("Error Code: %d\n", err);
	}
	printf("Unit Test for Heap: Success.\n");

	err = UnitTest_Graph();
	if (err){
		printf("Unit Test for Graph: Fail.\n");
		printf("Error Code: %d\n", err);
	}
	printf("Unit Test for Graph: Success.\n");

	err = UnitTest_Prim();
	if (err){
		printf("Unit Test for Prim Algorithm: Fail.\n");
		printf("Error Code: %d\n", err);
	}
	printf("Unit Test for Prim Algorithm: Success.\n");

	return 0;
}
