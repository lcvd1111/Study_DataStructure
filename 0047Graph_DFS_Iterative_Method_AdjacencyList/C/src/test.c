#include "test.h"

int UnitTest_Stack(void)
{
	STACK testStack;
	STACK_CONSTRUCTOR(&testStack);
	int testArray[5] = {0,};
	int *popOutput = NULL;

	if (testStack.Pop(&testStack,(void *)&popOutput) != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testStack.Empty(&testStack) != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	testStack.Push(&testStack, (void *)(testArray));
	testStack.Push(&testStack, (void *)(testArray+1));
	testStack.Push(&testStack, (void *)(testArray+2));
	testStack.Push(&testStack, (void *)(testArray+3));
	testStack.Push(&testStack, (void *)(testArray+4));

	if (testStack.Empty(&testStack) != 0){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testStack.Pop(&testStack, (void*)&popOutput) != &testStack){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (popOutput != (void *)(testArray + 4)){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testStack.Pop(&testStack, (void*)&popOutput) != &testStack){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (popOutput != (void *)(testArray + 3)){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testStack.Pop(&testStack, (void*)&popOutput) != &testStack){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (popOutput != (void *)(testArray + 2)){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testStack.Pop(&testStack, (void*)&popOutput) != &testStack){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (popOutput != (void *)(testArray + 1)){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testStack.Pop(&testStack, (void*)&popOutput) != &testStack){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (popOutput != (void *)(testArray)){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testStack.Pop(&testStack, (void *)&popOutput) != NULL){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testStack.Empty(&testStack) != 1){
		UNIT_TEST_FAIL;
		return -15;
	}

	STACK_DESTRUCTOR(&testStack);
	return 0;
}

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);

	testGraph.CreateGraph(&testGraph, 5);
	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 2);
	testGraph.AddEdge_Directed(&testGraph, 1, 2);

	testGraph.DestroyGraph(&testGraph);

	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_DFS_1_Undirected(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *outputStore = NULL;

	testGraph.CreateGraph(&testGraph, 7);

	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 2);
	testGraph.AddEdge(&testGraph, 1, 2);
	testGraph.AddEdge(&testGraph, 1, 3);
	testGraph.AddEdge(&testGraph, 1, 4);
	testGraph.AddEdge(&testGraph, 1, 6);
	testGraph.AddEdge(&testGraph, 5, 6);

	outputStore = testGraph.Create_DFS_Buffer(&testGraph);
	testGraph.DFS_1(&testGraph, outputStore);

	if (outputStore[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (outputStore[1] != 2){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (outputStore[2] != 1){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (outputStore[3] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (outputStore[4] != 5){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (outputStore[5] != 4){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (outputStore[6] != 3){
		UNIT_TEST_FAIL;
		return -7;
	}

	testGraph.Release_DFS_Buffer(&testGraph, outputStore);
	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_DFS_1_Directed(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *outputBuffer = NULL;

	testGraph.CreateGraph(&testGraph, 8);
	testGraph.AddEdge_Directed(&testGraph, 0, 1);
	testGraph.AddEdge_Directed(&testGraph, 0, 2);
	testGraph.AddEdge_Directed(&testGraph, 2, 3);
	testGraph.AddEdge_Directed(&testGraph, 2, 4);
	testGraph.AddEdge_Directed(&testGraph, 2, 7);
	testGraph.AddEdge_Directed(&testGraph, 5, 6);
	testGraph.AddEdge_Directed(&testGraph, 6, 2);
	testGraph.AddEdge_Directed(&testGraph, 6, 7);
	testGraph.AddEdge_Directed(&testGraph, 7, 6);
	//testGraph.Print(&testGraph);

	outputBuffer = testGraph.Create_DFS_Buffer(&testGraph);

	testGraph.DFS_1(&testGraph, outputBuffer);

	if (outputBuffer[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (outputBuffer[1] != 2){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (outputBuffer[2] != 7){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (outputBuffer[3] != 6){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (outputBuffer[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (outputBuffer[5] != 3){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (outputBuffer[6] != 1){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (outputBuffer[7] != 0){
		UNIT_TEST_FAIL;
		return -8;
	}

	testGraph.Release_DFS_Buffer(&testGraph, outputBuffer);
	GRAPH_DESTRUCTOR(&testGraph);
	return 0;
}

int UnitTest_DFS_2_Undirected(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *DFS_output = NULL;

	testGraph.CreateGraph(&testGraph, 9);
	testGraph.AddEdge(&testGraph, 0, 1);
	testGraph.AddEdge(&testGraph, 0, 3);
	testGraph.AddEdge(&testGraph, 1, 2);
	testGraph.AddEdge(&testGraph, 1, 4);
	testGraph.AddEdge(&testGraph, 2, 5);
	testGraph.AddEdge(&testGraph, 2, 7);
	testGraph.AddEdge(&testGraph, 3, 8);
	testGraph.AddEdge(&testGraph, 4, 5);
	testGraph.AddEdge(&testGraph, 5, 6);
	
	DFS_output = testGraph.Create_DFS_Buffer(&testGraph);
	testGraph.DFS_2(&testGraph, DFS_output);
	
	if (DFS_output[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (DFS_output[1] != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (DFS_output[2] != 2){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (DFS_output[3] != 5){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (DFS_output[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (DFS_output[5] != 6){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (DFS_output[6] != 7){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (DFS_output[7] != 3){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (DFS_output[8] != 8){
		UNIT_TEST_FAIL;
		return -8;
	}

	testGraph.Release_DFS_Buffer(&testGraph, DFS_output);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}

int UnitTest_DFS_2_Directed(void)
{
	GRAPH testGraph;
	GRAPH_CONSTRUCTOR(&testGraph);
	int *DFS_output = NULL;

	testGraph.CreateGraph(&testGraph, 8);
	testGraph.AddEdge_Directed(&testGraph, 0, 1);
	testGraph.AddEdge_Directed(&testGraph, 0, 2);
	testGraph.AddEdge_Directed(&testGraph, 2, 3);
	testGraph.AddEdge_Directed(&testGraph, 2, 4);
	testGraph.AddEdge_Directed(&testGraph, 2, 7);
	testGraph.AddEdge_Directed(&testGraph, 5, 6);
	testGraph.AddEdge_Directed(&testGraph, 6, 2);
	testGraph.AddEdge_Directed(&testGraph, 6, 7);
	testGraph.AddEdge_Directed(&testGraph, 7, 6);

	DFS_output = testGraph.Create_DFS_Buffer(&testGraph);
	testGraph.DFS_2(&testGraph, DFS_output);

	if (DFS_output[0] != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (DFS_output[1] != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (DFS_output[2] != 2){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (DFS_output[3] != 3){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (DFS_output[4] != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (DFS_output[5] != 7){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (DFS_output[6] != 6){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (DFS_output[7] != 0){
		UNIT_TEST_FAIL;
		return -8;
	}

	testGraph.Release_DFS_Buffer(&testGraph, DFS_output);
	GRAPH_DESTRUCTOR(&testGraph);

	return 0;
}
