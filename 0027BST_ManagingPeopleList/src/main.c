#include "common.h"

int main(int argc, char **argv)
{
	BST *peopleList = NULL;
	int loopCtl = 1;
	int userInput = 0;
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
	
	peopleList = CreateBST();

	while(loopCtl){
		userInput = MainMenu();

		switch (userInput){
		case 1:
			UserPrint(peopleList);
			break;
		case 2:
			UserSearch(peopleList);
			break;
		case 3:
			UserAdd(peopleList);
			break;
		case 4:
			UserDelete(peopleList);
			break;
		case 5:
			UserEmpty(peopleList);
			break;
		case 6:
			loopCtl = 0;
			break;
		}
	}

	if (CleanBST(peopleList)){
		PRINTF("ERROR: CleanBST() failed.\n");
		return -1;
	}
	free(peopleList);

	system("clear");
	return 0;
}
