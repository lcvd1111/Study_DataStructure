#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err = UnitTest_Stack()){
		printf("Unit Test for Stack: Fail.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Stack: Success.\n");
	
	if (err = UnitTest_Insert()){
		printf("Unit Test for BST Insertion: Fail.\n");
		printf("Err code: %d\n", err);
		return -2;
	}
	printf("Unit Test for BST Insertion: Success.\n");

	return 0;
}
