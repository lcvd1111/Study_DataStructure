#include "test.h"

int UnitTest_Graph_Interface(void)
{
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

	Destructor_Graph(&testGraph);
	return 0;
}
