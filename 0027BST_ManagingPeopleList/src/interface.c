#include "mylib.h"
#include "interface.h"
#include "test.h"

//Function Definitions
int MainMenu(void)
{
	system("clear");
	char userInput[128] = {0,};
	int ret = 0;

	printf("----<MAIN MENU>----\n");
	printf("1. Print Current List.\n");
	printf("2. Search a Member.\n");
	printf("3. Add a New Member.\n");
	printf("4. Delete a Member.\n");
	printf("5. Empty the List.\n");
	printf("6. Exit Program.\n");
	printf("--------------------\n");
	printf("Select a menu: ");	
	fgets(userInput, 128, stdin);
	ret = atoi(userInput);
	return ret;
}

int UserPrint(BST *bstArg)
{
	BST_NODE *popOutput = NULL;
	DEQUE *traverseDeque =NULL;

	if (bstArg==NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return -1;
	}

	system("clear");
	traverseDeque = InorderTraverse(bstArg);
	while(PopLeft(traverseDeque, &popOutput)){
			printf("[Name]: %s \n[Info]: %s\n\n", popOutput->name, popOutput->description);
	}

	printf("(END}\n(Press ENTER)\n");
	getchar();

	CleanDeque(traverseDeque);
	
	return 0;
}

int UserSearch(BST *bstArg)
{
	char userInput1[STRING_LEN] = {0,};
	BST_NODE *searchResult = NULL;

	if (bstArg == NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return -1;
	}

	system("clear");
	printf("Name to Search: ");
	fgets(userInput1, STRING_LEN, stdin);

	for (int i=0 ; i<STRING_LEN ; i++){
		if (userInput1[i] == '\n')
			userInput1[i] = 0;
	}

	if (Search(bstArg, userInput1, &searchResult)==NULL){
		printf("There is no memeber in the list.\n");
		printf("(Press ENTER)\n");
		getchar();
		return 0;
	}

	printf("[%s]: %s\n", searchResult->name, searchResult->description);
	printf("(Press ENTER)\n");
	getchar();

	return 0;
}

int UserAdd(BST *bstArg)
{	
	char userInput1[STRING_LEN] = {0,};
	char userInput2[STRING_LEN] = {0,};

	if (bstArg == NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return -1;
	}

	system("clear");
	
	printf("Name to Add: ");
	fgets(userInput1, STRING_LEN, stdin);

	for (int i=0 ; i<STRING_LEN ; i++){
		if (userInput1[i] == '\n')
			userInput1[i] = 0;
	}

	printf("Description: ");
	fgets(userInput2, STRING_LEN, stdin);

	for (int i=0 ; i<STRING_LEN ; i++){
		if (userInput2[i] == '\n')
			userInput2[i] = 0;
	}

	if(Add(bstArg, userInput1, userInput2) == NULL){
		printf("Name is already in the list.\n");
		printf("(Press ENTER)\n");
		getchar();
		return 0;
	}

	printf("New human is added.\n");
	printf("(Press ENTER)\n");
	getchar();
	return 0;
}

int UserDelete(BST *bstArg)
{
	char userInput[STRING_LEN] = {0,};

	if (bstArg == NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return -1;
	}

	system("clear");

	printf("Name to Delete: ");
	fgets(userInput, STRING_LEN, stdin);

	for (int i=0 ; i<STRING_LEN ; i++){
		if (userInput[i]=='\n')
			userInput[i] = 0;
	}

	if (Delete(bstArg, userInput) == NULL){
		printf("Member is not in the list.\n");
		printf("(Press Enter\n");
		getchar();
		return 0;
	}

	printf("%s is deleted.\n", userInput);
	printf("(Press Enter\n");
	getchar();
	return 0;
}

int UserEmpty(BST *bstArg)
{
	system("clear");
	CleanBST(bstArg);
	printf("Cleaning the list completed.\n");
	printf("(Press Enter)\n");
	getchar();
	return 0;
}

