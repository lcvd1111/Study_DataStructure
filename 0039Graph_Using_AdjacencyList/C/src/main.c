#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;
	if (err = UnitTest_Graph_Interface()){
		printf("Unit Test for Graph Interface implenmented by Adjacency List: Fail.\n");
		printf("Err Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Graph Interface implenmented by Adjacency List: Success.\n");

	return 0;
}
