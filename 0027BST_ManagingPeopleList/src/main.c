#include "common.h"

int main(int argc, char **argv)
{
#ifdef UNIT_TEST_ON
	if (UnitTest_BST()){
		printf("Unit Test for Binary Search Tree failed.\n");
		return -1;
	}

	if (UnitTest_Deque()){
		printf("Unit Test for Deque failed.\n");
		return -2;
	}

	if (UnitTest_Traversal()){
		printf("Unit Test for Inorder Traversal failed.\n");
		return -3;
	}
	printf("Unit Test is completed all.\n\n");
#endif

	int userInput = 0;
	userInput = MainMenu();
	printf("user input: %d\n", userInput);
	return 0;
}
