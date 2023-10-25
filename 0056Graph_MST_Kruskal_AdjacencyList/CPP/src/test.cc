#include "test.hh"
#include "lib_graph.hh"
#include "lib_unionfind.hh"

int UnitTest_Graph(void)
{
	GRAPH testGraph;
	testGraph.Create(5);

	testGraph.AddEdge(0,3,5);
	testGraph.AddEdge(2,1, 13);
	//testGraph.Print();
	if (testGraph.Weight() != 18){
		UNIT_TEST_FAIL;
		testGraph.Destroy();
		return -1;
	}

	return 0;
}

int UnitTest_UnionFind(void)
{
	UNION_FIND testUF;
	testUF.Create(5);

	if (testUF.Same(0, 1) != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testUF.Same(0, 2) != 0){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testUF.Same(0, 3) != 0){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testUF.Same(1, 2) != 0){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testUF.Same(1, 3) != 0){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testUF.Same(2, 3) != 0){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testUF.Unite(0, 4) != &testUF){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testUF.Unite(0, 3) != &testUF){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testUF.Same(3, 4) != 1){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testUF.Same(0, 4) != 1){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testUF.Same(0, 3) != 1){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testUF.Same(1, 3) != 0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testUF.Same(2, 3) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Same(1, 2) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Unite(0, 3) != NULL){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testUF.Unite(1, 2) != &testUF){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testUF.Unite(1, 2) != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testUF.Size(0) != 3){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testUF.Size(1) != 2){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testUF.Size(2) != 2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testUF.Size(3) != 3){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testUF.Size(4) != 3){
		UNIT_TEST_FAIL;
		return -22;
	}

	testUF.Destroy();
	return 0;
}

int UnitTest_Kruskal(void)
{
	GRAPH testGraph;
	GRAPH testMST;

	testGraph.Create(7);
	testGraph.AddEdge(0, 3, 3);
	testGraph.AddEdge(0, 4, 1);
	testGraph.AddEdge(1, 2, 5);
	testGraph.AddEdge(1, 4, 7);
	testGraph.AddEdge(1, 6, 13);
	testGraph.AddEdge(2, 5, 8);
	testGraph.AddEdge(3, 6, 9);
	testGraph.AddEdge(4, 5, 6);
	testGraph.AddEdge(5, 6, 4);

	if (testGraph.Weight() != 56){
		UNIT_TEST_FAIL;
		return -1;
	}
	
	testGraph.Kruskal(testMST);

	if (testMST.Weight() != 26){
		UNIT_TEST_FAIL;
		return -2;
	}

	std::cout << "<Given Graph>" << std::endl;
	testGraph.Print();
	std::cout << std::endl << "<Created MST>" << std::endl;
	testMST.Print();

	testGraph.Destroy();
	testMST.Destroy();

	return 0;
}
