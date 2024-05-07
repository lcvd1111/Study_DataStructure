#include "interface.h"

#define MENU_NUM 6

int Ui_Main(void)
{
	int userInput = 0;
	char dummy[128] = {0,};
	
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
	}
	system("clear");

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

	system("clear");

	printf("%s", mainScreen_str);
	printf("Select a Menu(1~%d): ", MENU_NUM);

	fgets(userInput_str, 128, stdin);
	userInput_int = atoi(userInput_str);

	return userInput_int;
}

int Ui_PrintList(void)
{
	return 0;
}

int Ui_Search(void)
{
	return 0;
}

int Ui_Add(void)
{
	return 0;
}

int Ui_Remove(void)
{
	return 0;
}

int Ui_EmptyList(void)
{
	return 0;
}
