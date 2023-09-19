#include "test.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph(7);

	if (testGraph.DeleteVertex(0,0) != NULL){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testGraph.AddVertex(0,0) != &testGraph){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testGraph.AddVertex(0,0) != NULL){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testGraph.DeleteVertex(0,0) != &testGraph){
		UNIT_TEST_FAIL;
		return -4;
	}

	for (int i=0; i<testGraph.size ; i++){
		for (int j=i ; j<testGraph.size ; j++){
			if ((i%2==1&&j%2==1)||(i%2==0&&j%2==0)){
				testGraph.AddVertex(i,j);
			}
		}
	}
	testGraph.Print();

	return 0;
}
