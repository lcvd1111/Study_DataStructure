#include "test.h"

int UnitTest_Stack(void)
{
	BINTREE_NODE testNode01 = {1, "TEST", NULL, NULL};
	BINTREE_NODE testNode02 = {2, "TEST", NULL, NULL};
	BINTREE_NODE testNode03 = {3, "TEST", NULL, NULL};
	BINTREE_NODE testNode04 = {4, "TEST", NULL, NULL};
	BINTREE_NODE testNode05 = {5, "TeST", NULL, NULL};
	STACK *testStack = NULL;

	testStack = CreateStack();

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	Push(testStack, &testNode01);
	Push(testStack, &testNode02);
	
	if (testStack->end->data->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testStack->end->prev->data->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (Pop(testStack)->number != 2){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	Push(testStack, &testNode03);
	Push(testStack, &testNode04);
	Push(testStack, &testNode05);

	if (Pop(testStack)->number != 5){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (Pop(testStack)->number != 4){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (Pop(testStack)->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (Pop(testStack)->number != 1){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (Pop(testStack) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testStack->begin != NULL || testStack->end != NULL){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (DeleteStack(testStack)){
		PRINTF("ERROR: DeleteStack(testStack) failed.\n");
		return -1;
	}

	return 0;
}

int UnitTest_Insert(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 81, "Ellen");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 17, "Susan");
	Insert(testRoot, 31, "Poole");
	Insert(testRoot, 130, "Friedberg");
	Insert(testRoot, 95, "Lax");
	Insert(testRoot, 75, "Boyce");
	Insert(testRoot, 3, "Tanenbaum");
	Insert(testRoot, 42, "Hartman");
	Insert(testRoot, 100, "Zorich");

	if (testRoot->left->number != 35){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(testRoot->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (strcmp(testRoot->right->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(testRoot->left->left->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->left->right->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(testRoot->left->right->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (strcmp(testRoot->right->right->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (strcmp(testRoot->left->left->left->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (strcmp(testRoot->left->left->right->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (testRoot->left->right->left->number != 42){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	if (strcmp(testRoot->left->right->left->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if (strcmp(testRoot->right->right->left->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	if (strcmp(testRoot->right->right->left->right->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -20;
	}

	DeleteBintree(testRoot);
	return 0;
}

int UnitTest_Search(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 81, "Ellen");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 17, "Susan");
	Insert(testRoot, 31, "Poole");
	Insert(testRoot, 130, "Friedberg");
	Insert(testRoot, 95, "Lax");
	Insert(testRoot, 75, "Boyce");
	Insert(testRoot, 3, "Tanenbaum");
	Insert(testRoot, 42, "Hartman");
	Insert(testRoot, 100, "Zorich");

	if (strcmp(Search(testRoot, 100)->name, "Zorich")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(Search(testRoot, 42)->name, "Hartman")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (strcmp(Search(testRoot, 3)->name, "Tanenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}
	
	if (strcmp(Search(testRoot, 75)->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (strcmp(Search(testRoot, 95)->name, "Lax")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (strcmp(Search(testRoot, 130)->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (strcmp(Search(testRoot, 31)->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (strcmp(Search(testRoot, 17)->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (strcmp(Search(testRoot, 35)->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (strcmp(Search(testRoot, 81)->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (strcmp(Search(testRoot, 77)->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	DeleteBintree(testRoot);

	return 0;
}

int UnitTest_Delete(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 77;
	strncpy(testRoot->name, "Joon", NAME_MAX);
	testRoot->left = NULL;
	testRoot->right = NULL;

	Insert(testRoot, 81, "Ellen");
	Insert(testRoot, 35, "Courant");
	Insert(testRoot, 17, "Susan");
	Insert(testRoot, 31, "Poole");
	Insert(testRoot, 130, "Friedberg");
	Insert(testRoot, 95, "Lax");
	Insert(testRoot, 75, "Boyce");
	Insert(testRoot, 3, "Tanenbaum");
	Insert(testRoot, 42, "Hartman");
	Insert(testRoot, 100, "Zorich");
	Insert(testRoot, 60, "Royden");
	Insert(testRoot, 50, "Folland");


	testRoot = Delete(testRoot, 35);
	if (testRoot->number != 77){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (testRoot->left->number != 42){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	if (testRoot->left->right->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	if (testRoot->left->right->left->number != 60){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (testRoot->left->right->left->left->number != 50){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	testRoot = Delete(testRoot, 42);
	if (testRoot->number != 77){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	if (testRoot->left->number != 50){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	if (testRoot->left->right->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -20;
	}

	if (testRoot->left->right->left->number != 60){
		PRINTF("Unit Test Failed.\n");
		return -21;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -22;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -23;
	}

	testRoot = Delete(testRoot, 50);
	if (testRoot->number != 77){
		PRINTF("Unit Test Failed.\n");
		return -24;
	}

	if (testRoot->left->number != 60){
		PRINTF("Unit Test Failed.\n");
		return -25;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -26;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -27;
	}

	if (testRoot->left->right->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -28;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -29;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -30;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -31;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -32;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -33;
	}

	testRoot = Delete(testRoot, 60);
	if (testRoot->number != 77){
		PRINTF("Unit Test Failed.\n");
		return -34;
	}

	if (testRoot->left->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -35;
	}

	if (testRoot->right->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -36;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -37;
	}

	if (testRoot->right->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -38;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -39;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -40;
	}

	if (testRoot->right->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -41;
	}

	if (testRoot->right->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -42;
	}

	testRoot = Delete(testRoot, 77);
	if (testRoot->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -42;
	}

	if (testRoot->left->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -43;
	}

	if (testRoot->right->number != 130){
		PRINTF("Unit Test Failed.\n");
		return -44;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -45;
	}

	if (testRoot->right->left->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -46;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -47;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -48;
	}

	if (testRoot->right->left->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -49;
	}

	testRoot = Delete(testRoot, 130);
	if (testRoot->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -50;
	}

	if (testRoot->left->number != 75){
		PRINTF("Unit Test Failed.\n");
		return -51;
	}

	if (testRoot->right->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -52;
	}

	if (testRoot->left->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -53;
	}

	if (testRoot->right->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -54;
	}

	if (testRoot->left->left->left->number != 3){
		PRINTF("Unit Test Failed\n");
		return -55;
	}

	if (testRoot->left->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -56;
	}

	testRoot = Delete(testRoot, 75);
	if (testRoot->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -57;
	}

	if (testRoot->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -58;
	}

	if (testRoot->right->number != 95){
		PRINTF("Unit Test Failed.\n");
		return -59;
	}

	if (testRoot->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -60;
	}

	if (testRoot->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -61;
	}

	if (testRoot->right->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -62;
	}

	testRoot = Delete(testRoot, 95);
	if (testRoot->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -63;
	}

	if (testRoot->left->number != 17){
		PRINTF("Unit Test Failed.\n");
		return -64;
	}

	if (testRoot->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -65;
	}

	if (testRoot->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -66;
	}

	if (testRoot->left->right->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -67;
	}

	testRoot = Delete(testRoot, 17);
	if (testRoot->number != 81){
		PRINTF("Unit Test Failed.\n");
		return -68;
	}

	if (testRoot->left->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -69;
	}

	if (testRoot->right->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -70;
	}

	if (testRoot->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -71;
	}

	testRoot = Delete(testRoot, 81);
	if (testRoot->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -72;
	}

	if (testRoot->left->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -73;
	}

	if (testRoot->left->left->number != 3){
		PRINTF("Unit Test Failed.\n");
		return -74;
	}

	Delete(testRoot, 3);
	if (testRoot->number != 100){
		PRINTF("Unit Test Failed.\n");
		return -75;
	}

	if (testRoot->left->number != 31){
		PRINTF("Unit Test Failed.\n");
		return -76;
	}

	DeleteBintree(testRoot);
	
	return 0;
}
