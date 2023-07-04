#include "test.h"
#include "mylib.h"

int main(int argc, char **argv)
{
	int err = 0;
	if(err = UnitTest_MakeChild()){
		printf("Unit Test for MakeChild: Fail.\n");
		printf("ERR code: %d\n", err);
		return -1;
	}
	printf("Unit Test for MakeChild: Success.\n");
	
	if(err = UnitTest_Search()){
		printf("Unit Test for BST Search: Fail.\n");
		printf("ERR code: %d\n", err);
		return -1;
	}
	printf("Unit Test for BST Search: Success.\n");
	
	return 0;
}
