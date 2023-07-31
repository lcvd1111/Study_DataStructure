#include "mylib.h"
#include "interface.h"
#include "test.h"

//Function Definitions
int MainMenu(void)
{
	int userInput = 0;

	printf("----<MAIN MENU>----\n");
	printf("1. Print Current List.\n");
	printf("2. Search a Member.\n");
	printf("3. Add a New Member.\n");
	printf("4. Delete a Member.\n");
	printf("5. Exit Program.\n");
	printf("--------------------\n");
	printf("Select a menu: ");	
	scanf("%d", &userInput);

	return userInput;
}

int UserPrint(BST *bstArg);	
int UserSearch(void);
int UserAdd(void);
int UserDelete(void);
int UserEmpty(void);
