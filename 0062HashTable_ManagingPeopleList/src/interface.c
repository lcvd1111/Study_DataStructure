#include "interface.h"

#define MENU_NUM 6

HASHMAP myMap;

int Ui_Main(void)
{
	int userInput = 0;
	char dummy[128] = {0,};

	HASHMAP_METHOD_CONSTRUCTOR(&myMap);
	
#ifndef UNITTEST_ON
	//UNITTEST_ON is defined in ./include/common.h
	system("clear");
#endif
	while(userInput != 6){
		userInput = Ui_MainScreen();

		switch (userInput){
		case 1:
			Ui_PrintList();
			break;
		case 2:
			Ui_Search();
			break;
		case 3:
			Ui_Add();
			break;
		case 4:
			Ui_Remove();
			break;
		case 5:
			Ui_EmptyList();
			break;
		case 6:
			break;
		default:
			userInput = 0;
			printf("\nPlease Input proper value, from 1 to %d.\n", MENU_NUM);
		}

		if (userInput == 6){
			system("clear");
			return 0;
		}

		printf("(Press Enter)\n");
		fgets(dummy, 128, stdin);

		system("clear");
	}
	system("clear");

	HASHMAP_METHOD_DESTRUCTOR(&myMap);

	return 0;
}

int Ui_MainScreen(void)
{
	static const char mainScreen_str[] =
		"\n"
		"  *************************\n"
		"  *                       *\n"
		"  *  1. Print People List *\n"
		"  *  2. Search a Person   *\n"
		"  *  3. Add a New Person  *\n"
		"  *  4. Delete a Person   *\n"
		"  *  5. Empty the List    *\n"
		"  *  6. Exit Program      *\n"
		"  *                       *\n"
		"  *************************\n\n";
	char userInput_str[128] = {0,};
	int userInput_int = 0;

	printf("%s", mainScreen_str);
	printf("Select a Menu(1~%d): ", MENU_NUM);

	fgets(userInput_str, 128, stdin);
	userInput_int = atoi(userInput_str);

	return userInput_int;
}

int Ui_PrintList(void)
{
	LIST *buf_List = NULL;
	HASHMAP_NODE *buf_Node = NULL;

	system("clear");

	//When the map is empty.
	if (myMap.currentSize == 0){
		printf("People List is empty currently.\n");
		return 0;
	}

	for (int i=0 ; i<myMap.tableSize ; i++){
		buf_List = myMap.table + i;
		if ((buf_List->Method->IsEmpty)(buf_List) == 0){
			buf_Node = buf_List->begin;
			for (int j=0 ; j<buf_List->size ; j++){
				printf("[Name]: %s, [Phone Number]: %s\n",
						buf_Node->key, buf_Node->data);
				buf_Node = buf_Node->next;
			}
		}
		else {
			continue;
		}
	}

	return 0;
}

int Ui_Search(void)
{
	char keyBuf[NAME_LEN] = {0,};
	HASHMAP_NODE *temp = NULL;

	system("clear");
	printf("[Name]: ");
	fgets(keyBuf, NAME_LEN, stdin);

	for (int i=0 ; i<NAME_LEN ; i++){
		if (keyBuf[i] == (char)'\n'){
			keyBuf[i] = 0;
		}
	}

	temp = (myMap.Method->Search)(&myMap, keyBuf);
	if (temp != NULL){
		printf("[Name]: %s, [Phone Number]: %s\n", temp->key, temp->data);
		return 0;
	}
	else {
		printf("%s doesn't exist!\n", keyBuf);
		return 0;
	}
}

int Ui_Add(void)
{
	char keyBuf[NAME_LEN] = {0,};
	char dataBuf[DATA_LEN] = {0,};
	HASHMAP_NODE *temp = NULL;

	system("clear");
	printf("[Name]: ");
	fgets(keyBuf, NAME_LEN, stdin);

	for (int i=0 ; i<NAME_LEN ; i++){
		if (keyBuf[i] == (char)'\n'){
			keyBuf[i] = 0;
		}
	}

	temp = (myMap.Method->Search)(&myMap, keyBuf);
	if (temp != NULL){
		printf("%s already exist!\n", keyBuf);
		printf("[Name]: %s, [Phone Number]: %s\n", temp->key, temp->data);
		return 0;
	}
	printf("[Phone Number]: ");
	fgets(dataBuf, DATA_LEN, stdin);

	for (int i=0 ; i<DATA_LEN ; i++){
		if (dataBuf[i] == (char)'\n'){
			dataBuf[i] = 0;
		}
	}

	(myMap.Method->Insert)(&myMap, keyBuf, dataBuf);

	return 0;
}

int Ui_Remove(void)
{
	char keyBuf[NAME_LEN] = {0,};
	HASHMAP_NODE *temp = NULL;

	system("clear");
	printf("[Name]: ");
	fgets(keyBuf, NAME_LEN, stdin);

	for (int i=0 ; i<NAME_LEN ; i++){
		if (keyBuf[i] == (char)'\n'){
			keyBuf[i] = 0;
		}
	}

	temp = (myMap.Method->Search)(&myMap, keyBuf);
	if (temp != NULL){
		(myMap.Method->Delete)(&myMap, keyBuf);
		printf("%s is removed!\n", keyBuf);
		return 0;
	}
	else {
		printf("%s doesn't exist!\n", keyBuf);
		return 0;
	}
}

int Ui_EmptyList(void)
{
	system("clear");
	(myMap.Method->MakeEmpty)(&myMap);
	printf("People List is Cleared!\n");
	return 0;
}
