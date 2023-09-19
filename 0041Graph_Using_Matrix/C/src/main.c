#include "common.h"

//AddVertex(), DeleteVertex() interface is not implemented.

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();

	if (err){
		printf("Unit Test for Graph using Adjacency Matrix: Fail.\n");
		printf("Error Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Graph using Adjacency Matrix: Success.\n");

	return 0;
}
