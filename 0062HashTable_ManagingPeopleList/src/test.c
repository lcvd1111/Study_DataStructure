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
	int testSize = 5000;

	HASHMAP testMap;
	HASHMAP_METHOD_CONSTRUCTOR(&testMap);

	int keyLen = 0;
	int dataLen = 0;
	char keyBuf[NAME_LEN] = {0,};
	char dataBuf[DATA_LEN] = {0,};

	HASHMAP_NODE *searchResult = NULL;

	srand((unsigned int)time(NULL));
	for (int i=0; i<testSize ; i++){
		memset(keyBuf, 0, NAME_LEN);
		memset(dataBuf, 0, DATA_LEN);
		keyLen = rand() % 10;
		dataLen = rand() % 100;
		while(keyLen == 0){
			keyLen = rand() % 10;
		}
		for (int j=0 ; j<keyLen ; j++){
			keyBuf[j] = letterCollection[rand()%62];
		}
		keyBuf[keyLen] = 0;
		for (int j=0 ; j<dataLen ; j++){
			dataBuf[j] = letterCollection[rand()%62];
		}
		dataBuf[dataLen] = 0;

		(testMap.Method->Insert)(&testMap, keyBuf, dataBuf);
	}

	if ((testMap.Method->Search)(&testMap, "pX3m") != NULL){
		(testMap.Method->Delete)(&testMap, "pX3m");
	}
	(testMap.Method->Insert)(&testMap, "pX3m", "Test_Element_01");

	if ((testMap.Method->Search)(&testMap, "2F") != NULL){
		(testMap.Method->Delete)(&testMap, "2F");
	}
	(testMap.Method->Insert)(&testMap, "2F", "Test_Element_02");

	searchResult = (testMap.Method->Search)(&testMap, "pX3m");
	if (searchResult == NULL){
		UNIT_TEST_FAIL;
		return -1;
	}
	printf("\n[Data for 'pX3m']: %s\n", searchResult->data);

	searchResult = (testMap.Method->Search)(&testMap, "2F");
	if (searchResult == NULL){
		UNIT_TEST_FAIL;
		return -2;
	}
	printf("[Data for '2F']: %s\n", searchResult->data);

	if ((testMap.Method->Delete)(&testMap, "pX3m") != &testMap){
		UNIT_TEST_FAIL;
		return -3;
	}
	searchResult = (testMap.Method->Search)(&testMap, "pX3m");
	if (searchResult != NULL){
		UNIT_TEST_FAIL;
		return -4;
	}

	if ((testMap.Method->Delete)(&testMap, "2F") != &testMap){
		UNIT_TEST_FAIL;
		return -5;
	}
	searchResult = (testMap.Method->Search)(&testMap, "2F");
	if (searchResult != NULL){
		UNIT_TEST_FAIL;
		return -6;
	}

	(testMap.Method->MakeEmpty)(&testMap);
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
