#include "test.h"

int UnitTest_List(void)
{
	LIST testList;
	LIST_METHOD_CONSTRUCTOR(&testList);

	if ((testList.Method->IsEmpty)(&testList) != 1){
		UNIT_TEST_FAIL;
		return -1;
	}

	(testList.Method->AddElement)(&testList, "A", "001");
	if ((testList.Method->GetSize)(&testList) != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	(testList.Method->AddElement)(&testList, "B", "002");
	if ((testList.Method->GetSize)(&testList) != 2){
		UNIT_TEST_FAIL;
		return -3;
	}

	(testList.Method->AddElement)(&testList, "C", "003");
	if ((testList.Method->GetSize)(&testList) != 3){
		UNIT_TEST_FAIL;
		return -4;
	}

	(testList.Method->AddElement)(&testList, "D", "004");
	if ((testList.Method->GetSize)(&testList) != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	LIST_METHOD_DESTRUCTOR(&testList);
	return 0;
}

int UnitTest_HashMap(void)
{
	return 0;
}

int UnitTest(void)
{
	char dummyText[128] = {0,};
	int err = 0;

	printf(COLOR_BLACK "Unit Test for Linked List: " COLOR_BLACK);
	if (err = UnitTest_List()){
		printf(COLOR_RED "FAIL\n" COLOR_BLACK);
		return -1;
	}
	printf(COLOR_GREEN "SUCCESS\n" COLOR_BLACK);

	printf(COLOR_BLACK "Unit Test for Hashmap: " COLOR_BLACK);
	if (err = UnitTest_HashMap()){
		printf(COLOR_RED "FAIL\n" COLOR_BLACK);
		return -2;
	}
	printf(COLOR_GREEN "SUCCESS\n" COLOR_BLACK);

	printf(COLOR_BLACK "Unit Test is all successful.\n" COLOR_BLACK);
	printf(COLOR_BLACK "(Press Enter...)" COLOR_BLACK);
	fgets(dummyText, 128, stdin);

	return 0;
}
