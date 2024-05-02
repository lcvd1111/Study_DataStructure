#include "test.h"

int UnitTest_LinkedList(void)
{
	LINKED_LIST testList;
	LINKED_LIST_METHOD_CONSTRUCTOR(&testList);

	if (testList.size != 0){
		PRINTF_ERROR("UNIT TEST FAIL.\n");
		return -1;
	}

	LINKED_LIST_METHOD_DESTRUCTOR(&testList);
	return 0;
}

int UnitTest_HashMap(void)
{
	HASHMAP testMap;
	HASHMAP_METHOD_CONSTRUCTOR(&testMap);
	testMap.Method->Print(&testMap);

	HASHMAP_METHOD_DESTRUCTOR(&testMap);
	return 0;
}
