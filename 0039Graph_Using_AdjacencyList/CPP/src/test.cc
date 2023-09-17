#include "test.hh"

int UnitTest_Graph_Using_Vector(void)
{
	V_GRAPH testGraph;

	if (testGraph.AddVertex("A") != &testGraph){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testGraph.AddVertex("A") != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testGraph.AddVertex("B") != &testGraph){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testGraph.AddVertex("C") != &testGraph){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testGraph.AddEdge("B", "C") != &testGraph){
		UNIT_TEST_FAIL;
		return -5;
	}
	
	if (testGraph.AddEdge("B", "C") != NULL){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testGraph.AddEdge("B", "D") != NULL){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testGraph.AddEdge("D", "A") != NULL){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testGraph.AddEdge("A", "A") != &testGraph){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testGraph.AddEdge("A", "A") != NULL){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testGraph.AddVertex("C") != NULL){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testGraph.AddVertex("D") != &testGraph){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testGraph.AddVertex("E") != &testGraph){
		UNIT_TEST_FAIL;
		return -13;
	}

	testGraph.AddVertex("F");

	if (testGraph.AddVertex("G") != &testGraph){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testGraph.AddEdge("C", "D") != &testGraph){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testGraph.AddEdge("C", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testGraph.AddEdge("C", "D") != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}


	if (testGraph.AddEdge("D", "C") != NULL){
		UNIT_TEST_FAIL;
		return -18;
	}


	if (testGraph.AddEdge("D", "G") != &testGraph){
		UNIT_TEST_FAIL;
		return -19;
	}


	if (testGraph.AddEdge("E", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -20;
	}


	if (testGraph.AddEdge("E", "G") != &testGraph){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testGraph.AddEdge("G", "E") != NULL){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (testGraph.AddEdge("A", "E") != &testGraph){
		UNIT_TEST_FAIL;
		return -23;
	}

	testGraph.Print();

	if (testGraph.DeleteEdge("A", "B") != NULL){
		UNIT_TEST_FAIL;
		return -24;
	}

	if (testGraph.DeleteEdge("A", "X") != NULL){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (testGraph.DeleteEdge("B", "A") != NULL){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (testGraph.DeleteEdge("X", "B") != NULL){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (testGraph.DeleteEdge("C", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (testGraph.DeleteEdge("C", "F") != NULL){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (testGraph.DeleteEdge("F", "C") != NULL){
		UNIT_TEST_FAIL;
		return -30;
	}

	if (testGraph.DeleteEdge("G", "D") != &testGraph){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (testGraph.DeleteEdge("G", "D") != NULL){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (testGraph.DeleteEdge("D", "G") != NULL){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (testGraph.DeleteEdge("A", "E") != &testGraph){
		UNIT_TEST_FAIL;
		return -32;
	}

	std::cout << std::endl << "After the Deletion of (C,F) and (D,G)" << std::endl;
	testGraph.Print();

	if (testGraph.DeleteVertex("X") != NULL){
		UNIT_TEST_FAIL;
		return -33;
	}

	if (testGraph.DeleteVertex("E") != &testGraph){
		UNIT_TEST_FAIL;
		return -34;
	}

	if (testGraph.DeleteVertex("E") != NULL){
		UNIT_TEST_FAIL;
		return -35;
	}
	
	std::cout << std::endl << "After the Deletion of Vertex E" << std::endl;
	testGraph.Print();

	return 0;
}

int UnitTest_Graph_Using_Set(void)
{
	S_GRAPH testGraph;

	if (testGraph.AddVertex("A") != &testGraph){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testGraph.AddVertex("A") != NULL){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testGraph.AddVertex("B") != &testGraph){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testGraph.AddVertex("C") != &testGraph){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testGraph.AddEdge("B", "C") != &testGraph){
		UNIT_TEST_FAIL;
		return -5;
	}
	
	if (testGraph.AddEdge("B", "C") != NULL){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testGraph.AddEdge("B", "D") != NULL){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testGraph.AddEdge("D", "A") != NULL){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testGraph.AddEdge("A", "A") != &testGraph){
		UNIT_TEST_FAIL;
		return -9;
	}

	if (testGraph.AddEdge("A", "A") != NULL){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testGraph.AddVertex("C") != NULL){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testGraph.AddVertex("D") != &testGraph){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testGraph.AddVertex("E") != &testGraph){
		UNIT_TEST_FAIL;
		return -13;
	}

	testGraph.AddVertex("F");

	if (testGraph.AddVertex("G") != &testGraph){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testGraph.AddEdge("C", "D") != &testGraph){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testGraph.AddEdge("C", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testGraph.AddEdge("C", "D") != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}


	if (testGraph.AddEdge("D", "C") != NULL){
		UNIT_TEST_FAIL;
		return -18;
	}


	if (testGraph.AddEdge("D", "G") != &testGraph){
		UNIT_TEST_FAIL;
		return -19;
	}


	if (testGraph.AddEdge("E", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -20;
	}


	if (testGraph.AddEdge("E", "G") != &testGraph){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testGraph.AddEdge("G", "E") != NULL){
		UNIT_TEST_FAIL;
		return -22;
	}

	if (testGraph.AddEdge("A", "E") != &testGraph){
		UNIT_TEST_FAIL;
		return -23;
	}

	testGraph.Print();

	if (testGraph.DeleteEdge("A", "B") != NULL){
		UNIT_TEST_FAIL;
		return -24;
	}

	if (testGraph.DeleteEdge("A", "X") != NULL){
		UNIT_TEST_FAIL;
		return -25;
	}

	if (testGraph.DeleteEdge("B", "A") != NULL){
		UNIT_TEST_FAIL;
		return -26;
	}

	if (testGraph.DeleteEdge("X", "B") != NULL){
		UNIT_TEST_FAIL;
		return -27;
	}

	if (testGraph.DeleteEdge("C", "F") != &testGraph){
		UNIT_TEST_FAIL;
		return -28;
	}

	if (testGraph.DeleteEdge("C", "F") != NULL){
		UNIT_TEST_FAIL;
		return -29;
	}

	if (testGraph.DeleteEdge("F", "C") != NULL){
		UNIT_TEST_FAIL;
		return -30;
	}

	if (testGraph.DeleteEdge("G", "D") != &testGraph){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (testGraph.DeleteEdge("G", "D") != NULL){
		UNIT_TEST_FAIL;
		return -31;
	}

	if (testGraph.DeleteEdge("D", "G") != NULL){
		UNIT_TEST_FAIL;
		return -32;
	}

	if (testGraph.DeleteEdge("A", "E") != &testGraph){
		UNIT_TEST_FAIL;
		return -32;
	}

	std::cout << std::endl << "After the Deletion of (C,F) and (D,G)" << std::endl;
	testGraph.Print();

	if (testGraph.DeleteVertex("X") != NULL){
		UNIT_TEST_FAIL;
		return -33;
	}

	if (testGraph.DeleteVertex("E") != &testGraph){
		UNIT_TEST_FAIL;
		return -34;
	}

	if (testGraph.DeleteVertex("E") != NULL){
		UNIT_TEST_FAIL;
		return -35;
	}
	
	std::cout << std::endl << "After the Deletion of Vertex E" << std::endl;
	testGraph.Print();

	return 0;
}
