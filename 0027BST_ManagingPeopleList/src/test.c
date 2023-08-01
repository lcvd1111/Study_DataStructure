#include "test.h"

int UnitTest_BST(void)
{
	BST *testBST = NULL;
	BST_NODE *searchResult = NULL;
	DEQUE *traverseDeque = NULL;

	testBST = CreateBST();
	if (testBST == NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}
	Add(testBST, "Joon", "Me");
	if (strcmp(testBST->root->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Add(testBST, "Ellen", "Love");
	if (strcmp(testBST->root->left->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Add(testBST, "Courant", "SVC");
	if (strcmp(testBST->root->left->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}
	
	Add(testBST, "Susan", "MVC");
	if (strcmp(testBST->root->right->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	Add(testBST, "Poole", "LA1");
	if (strcmp(testBST->root->right->left->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Add(testBST, "Friedberg", "LA2");
	if (strcmp(testBST->root->left->right->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Add(testBST, "Boyce", "ODE1");
	if (strcmp(testBST->root->left->left->left->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	Add(testBST, "Tannenbaum", "ODE2");
	if (strcmp(testBST->root->right->right->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	if (Add(testBST, "Tannenbaum", "ODE2") != NULL){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	if (Search(testBST, "TESTKEY", &searchResult) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}
	Search(testBST, "Joon", &searchResult);
	if(strcmp(searchResult->description, "Me")){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	Search(testBST, "Ellen", &searchResult);
	if(strcmp(searchResult->description, "Love")){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	Search(testBST, "Susan", &searchResult);
	if(strcmp(searchResult->description, "MVC")){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	Search(testBST, "Courant", &searchResult);
	if(strcmp(searchResult->description, "SVC")){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	Search(testBST, "Friedberg", &searchResult);
	if(strcmp(searchResult->description, "LA2")){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	Search(testBST, "Poole", &searchResult);
	if(strcmp(searchResult->description, "LA1")){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	Search(testBST, "Tannenbaum", &searchResult);
	if(strcmp(searchResult->description, "ODE2")){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}
	
	Search(testBST, "Boyce", &searchResult);
	if(strcmp(searchResult->description, "ODE1")){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if (Delete(testBST, "TESTNAME") != NULL){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	Delete(testBST, "Joon");
	traverseDeque = InorderTraverse(testBST);

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -20;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -21;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -22;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -23;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -24;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -25;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -26;
	}

	CleanDeque(traverseDeque);
	traverseDeque = NULL;

	Delete(testBST, "Courant");
	traverseDeque = InorderTraverse(testBST);

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -27;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -28;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -29;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -30;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -31;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -32;
	}

	CleanDeque(traverseDeque);
	traverseDeque = NULL;

	Delete(testBST, "Boyce");
	traverseDeque = InorderTraverse(testBST);

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -33;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -34;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -35;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -36;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -37;
	}

	CleanDeque(traverseDeque);
	traverseDeque = NULL;

	Delete(testBST, "Tannenbaum");
	traverseDeque = InorderTraverse(testBST);

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -38;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -39;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -39;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -40;
	}

	CleanDeque(traverseDeque);
	traverseDeque = NULL;

	Delete(testBST, "Ellen");
	traverseDeque = InorderTraverse(testBST);

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -41;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -42;
	}

	PopLeft(traverseDeque, &searchResult);
	if (strcmp(searchResult->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -43;
	}

	CleanDeque(traverseDeque);
	traverseDeque = NULL;

	if (CleanBST(testBST) != 0){
		PRINTF("Unit Test Failed.\n");
		return -27;
	}

	return 0;
}

int UnitTest_Deque(void)
{
	BST_NODE node1 = {.name="a", .description="aa"};
	BST_NODE node2 = {.name="b", .description="bb"};
	BST_NODE node3 = {.name="c", .description="cc"};
	BST_NODE node4 = {.name="d", .description="dd"};
	BST_NODE node5 = {.name="e", .description="ee"};
	BST_NODE *popOutput = NULL;	
	DEQUE *testDeque = NULL;

	testDeque = CreateDeque();
	PushRight(testDeque, &node1);

	if (strcmp(testDeque->begin->data->name, "a")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}

	if (strcmp(testDeque->end->data->name, "a")){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}


	PushRight(testDeque, &node2);
	if (strcmp(testDeque->begin->data->name, "a")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}
	
	if (strcmp(testDeque->end->data->name, "b")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}	

	PushRight(testDeque, &node3);
	if (strcmp(testDeque->end->data->name, "c")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}

	PushRight(testDeque, &node4);
	if (strcmp(testDeque->end->data->name, "d")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	PushRight(testDeque, &node5);
	if (strcmp(testDeque->end->data->name, "e")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}


	PopRight(testDeque, &popOutput);
	if (strcmp(popOutput->name, "e")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	PopLeft(testDeque, &popOutput);
	if (strcmp(popOutput->name, "a")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	PopRight(testDeque, &popOutput);
	if (strcmp(popOutput->name, "d")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	PopLeft(testDeque, &popOutput);
	if (strcmp(popOutput->name, "b")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	PopRight(testDeque, &popOutput);
	if (strcmp(popOutput->name, "c")){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	if (PopLeft(testDeque, &popOutput) != NULL){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	return 0;
}

int UnitTest_Traversal(void)
{
	BST *testBST = NULL;
	BST_NODE *searchResult = NULL;
	DEQUE *resultDeque = NULL;
	BST_NODE *popOutput = NULL;

	testBST = CreateBST();
	if (testBST == NULL){
		PRINTF("Unit Test Failed.\n");
		return -1;
	}
	Add(testBST, "Joon", "Me");
	if (strcmp(testBST->root->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -2;
	}

	Add(testBST, "Ellen", "Love");
	if (strcmp(testBST->root->left->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -3;
	}

	Add(testBST, "Courant", "SVC");
	if (strcmp(testBST->root->left->left->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -4;
	}
	
	Add(testBST, "Susan", "MVC");
	if (strcmp(testBST->root->right->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -5;
	}

	Add(testBST, "Poole", "LA1");
	if (strcmp(testBST->root->right->left->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -6;
	}

	Add(testBST, "Friedberg", "LA2");
	if (strcmp(testBST->root->left->right->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -7;
	}

	Add(testBST, "Boyce", "ODE1");
	if (strcmp(testBST->root->left->left->left->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -8;
	}

	Add(testBST, "Tannenbaum", "ODE2");
	if (strcmp(testBST->root->right->right->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -9;
	}

	resultDeque = InorderTraverse(testBST);
	
	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Boyce")){
		PRINTF("Unit Test Failed.\n");
		return -10;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Courant")){
		PRINTF("Unit Test Failed.\n");
		return -11;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Ellen")){
		PRINTF("Unit Test Failed.\n");
		return -12;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Friedberg")){
		PRINTF("Unit Test Failed.\n");
		return -13;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Joon")){
		PRINTF("Unit Test Failed.\n");
		return -14;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Poole")){
		PRINTF("Unit Test Failed.\n");
		return -15;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Susan")){
		PRINTF("Unit Test Failed.\n");
		return -16;
	}

	PopLeft(resultDeque, &popOutput);
	if (strcmp(popOutput->name, "Tannenbaum")){
		PRINTF("Unit Test Failed.\n");
		return -17;
	}

	if(CleanBST(testBST)){
		PRINTF("Unit Test Failed.\n");
		return -18;
	}

	if(CleanDeque(resultDeque)){
		PRINTF("Unit Test Failed.\n");
		return -19;
	}

	return 0;
}

