#include "test.h"

static const char letterCollection[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

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
	HASHMAP testMap;
	HASHMAP_METHOD_CONSTRUCTOR(&testMap);

	(testMap.Method->Insert)(&testMap, "A", "001");
	(testMap.Method->Insert)(&testMap, "B", "002");
	(testMap.Method->Insert)(&testMap, "C", "003");
	(testMap.Method->Insert)(&testMap, "D", "004");
	(testMap.Method->Insert)(&testMap, "E", "005");

	(testMap.Method->Print)(&testMap);

	HASHMAP_METHOD_DESTRUCTOR(&testMap);

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

	return 0;
}
