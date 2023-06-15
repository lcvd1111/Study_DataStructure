#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	
	if((err=UnitTest_Deque()) != 0){
		printf("Error code: %d\n", err);
		return -1;
	}
	else
		printf("Unit Test for Deque: Success.\n");
	
	return 0;
}
