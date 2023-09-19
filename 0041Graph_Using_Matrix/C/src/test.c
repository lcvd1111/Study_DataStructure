#include "test.h"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	Graph_Constructor(&testGraph, 5);

	if (testGraph.AddEdge(&testGraph,0,0) != &testGraph){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testGraph.AddEdge(&testGraph,0,0) != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testGraph.DeleteEdge(&testGraph, 1, 1) != NULL){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testGraph.DeleteEdge(&testGraph, 0, 0) != &testGraph){
		UNIT_TEST_FAIL;
		return -4;
	}

	for (int i=0; i<testGraph.size ; i++){
		for (int j=0; j<testGraph.size ; j++){
			if ((((i%2)==0)&&((j%2)==0))||((i%2==1)&&(j%2==1))){
				testGraph.AddEdge(&testGraph, i, j);
			}
		}
	}

	testGraph.Print(&testGraph);

	Graph_Destructor(&testGraph);
	return 0;
}
