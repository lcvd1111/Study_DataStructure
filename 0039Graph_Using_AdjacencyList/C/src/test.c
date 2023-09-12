#include "test.h"

int UnitTest_Graph_Interface(void)
{
	GRAPH_NODE *tempNode = NULL;
	GRAPH testGraph;
	Constructor_Graph(&testGraph, 100);
	if (testGraph.currentSize != 0){
		UNIT_TEST_FAIL;
		return -1;
	}
	testGraph.AddVertex(&testGraph, "a");
	if (testGraph.currentSize != 1){
		UNIT_TEST_FAIL;
		return -2;
	}

	testGraph.AddVertex(&testGraph, "b");
	if (testGraph.currentSize != 2){
		UNIT_TEST_FAIL;
		return -3;
	}

	testGraph.AddVertex(&testGraph, "c");
	if (testGraph.currentSize != 3){
		UNIT_TEST_FAIL;
		return -4;
	}

	testGraph.AddVertex(&testGraph, "d");
	if (testGraph.currentSize != 4){
		UNIT_TEST_FAIL;
		return -5;
	}

	testGraph.AddVertex(&testGraph, "e");
	if (testGraph.currentSize != 5){
		UNIT_TEST_FAIL;
		return -6;
	}

	testGraph.AddVertex(&testGraph, "f");
	if (testGraph.currentSize != 6){
		UNIT_TEST_FAIL;
		return -7;
	}

	testGraph.AddVertex(&testGraph, "g");
	if (testGraph.currentSize != 7){
		UNIT_TEST_FAIL;
		return -8;
	}

	testGraph.AddVertex(&testGraph, "h");
	if (testGraph.currentSize != 8){
		UNIT_TEST_FAIL;
		return -9;
	}

	testGraph.AddVertex(&testGraph, "i");
	if (testGraph.currentSize != 9){
		UNIT_TEST_FAIL;
		return -10;
	}

	testGraph.DeleteVertex(&testGraph, "d");
	if (testGraph.currentSize != 8){
		UNIT_TEST_FAIL;
		return -11;
	}

	testGraph.DeleteVertex(&testGraph, "f");
	if (testGraph.currentSize != 7){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testGraph.currentLastIndex != 8){
		UNIT_TEST_FAIL;
		return -13;
	}

	testGraph.DeleteVertex(&testGraph, "i");
	if (testGraph.currentSize != 6){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testGraph.currentLastIndex != 7){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testGraph.DeleteVertex(&testGraph, "i") != NULL){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testGraph.currentSize != 6){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testGraph.currentLastIndex != 7){
		UNIT_TEST_FAIL;
		return -18;
	}
	testGraph.AddVertex(&testGraph, "i");
	if (strcmp(testGraph.vertexList[3]->data, "i") != 0){
		UNIT_TEST_FAIL;
		return -19;
	}
	
	if (testGraph.currentSize != 7){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testGraph.currentLastIndex != 7){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testGraph.AddEdge(&testGraph, 2, 6) == NULL){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (testGraph.AddEdge(&testGraph, 2, 6) != NULL){
		UNIT_TEST_FAIL;
		return -23;
	}

	if (testGraph.AddEdge(&testGraph, 6, 2) != NULL){
		UNIT_TEST_FAIL;
		return -24;
	}

	testGraph.AddEdge(&testGraph, 2, 1);

	if (testGraph.DeleteEdge(&testGraph, 1, 1) != NULL){
		UNIT_TEST_FAIL;
		return -25;
	}

	testGraph.AddEdge(&testGraph, 1, 0);
	if (testGraph.DeleteEdge(&testGraph, 1, 0) == NULL){
		UNIT_TEST_FAIL;
		return -26;
	}

	testGraph.AddEdge(&testGraph, testGraph.ReturnIndex(&testGraph, "i"), testGraph.ReturnIndex(&testGraph, "e"));
	testGraph.AddEdge(&testGraph, testGraph.ReturnIndex(&testGraph, "e"), testGraph.ReturnIndex(&testGraph, "g"));
	testGraph.AddEdge(&testGraph, testGraph.ReturnIndex(&testGraph, "h"), testGraph.ReturnIndex(&testGraph, "e"));

	//Printing Adjacency List
	for (int i=0 ; i<=testGraph.currentLastIndex ; i++){
		if (testGraph.vertexList[i] == NULL)
			continue;

		printf("Node [%s]: ", testGraph.vertexList[i]->data);
		tempNode = testGraph.vertexList[i];
		while(1){
			if (tempNode->next ==  NULL)
				break;
			tempNode = tempNode->next;
			printf("%s ", tempNode->data);
		}
		printf("\n");
	}
	printf("Number of total vertexes(nodes): %ld\n", testGraph.currentSize);

	testGraph.DeleteVertex(&testGraph, "e");
	printf("\n\nAfter Deletion of vertex 'e'\n");
	//Printing Adjacency List
	for (int i=0 ; i<=testGraph.currentLastIndex ; i++){
		if (testGraph.vertexList[i] == NULL)
			continue;

		printf("Node [%s]: ", testGraph.vertexList[i]->data);
		tempNode = testGraph.vertexList[i];
		while(1){
			if (tempNode->next ==  NULL)
				break;
			tempNode = tempNode->next;
			printf("%s ", tempNode->data);
		}
		printf("\n");
	}
	printf("Number of total vertexes(nodes): %ld\n", testGraph.currentSize);
	
	if(Destructor_Graph(&testGraph)){
		UNIT_TEST_FAIL;
		return -27;
	}

	return 0;
}
