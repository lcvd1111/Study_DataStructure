#include "test.h"
#include "lib_unionfind.h"
#include "lib_heap.h"
#include "lib_graph.h"

int UnitTest_UnionFind(void)
{
	UNION_FIND testUF;
	UNION_FIND_CONSTRUCTOR(&testUF);
	UNION_FIND *p = &testUF;

	testUF.Create(p,  5);
	if (testUF.Same(p, 0, 1) != 0){
		UNIT_TEST_FAIL;
		return -1;
	}

	if (testUF.Same(p, 0, 2) != 0){
		UNIT_TEST_FAIL;
		return -2;
	}

	if (testUF.Same(p, 0, 3) != 0){
		UNIT_TEST_FAIL;
		return -3;
	}

	if (testUF.Same(p, 1, 2) != 0){
		UNIT_TEST_FAIL;
		return -4;
	}

	if (testUF.Same(p, 1, 3) != 0){
		UNIT_TEST_FAIL;
		return -5;
	}

	if (testUF.Same(p, 2, 3) != 0){
		UNIT_TEST_FAIL;
		return -6;
	}

	if (testUF.Unite(p, 0, 4) != &testUF){
		UNIT_TEST_FAIL;
		return -7;
	}

	if (testUF.Unite(p, 0, 3) != &testUF){
		UNIT_TEST_FAIL;
		return -8;
	}

	if (testUF.Same(p, 3, 4) != 1){
		UNIT_TEST_FAIL;
		return -10;
	}

	if (testUF.Same(p, 0, 4) != 1){
		UNIT_TEST_FAIL;
		return -11;
	}

	if (testUF.Same(p, 0, 3) != 1){
		UNIT_TEST_FAIL;
		return -12;
	}

	if (testUF.Same(p, 1, 3) != 0){
		UNIT_TEST_FAIL;
		return -13;
	}

	if (testUF.Same(p, 2, 3) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Same(p, 1, 2) != 0){
		UNIT_TEST_FAIL;
		return -14;
	}

	if (testUF.Unite(p, 0, 3) != NULL){
		UNIT_TEST_FAIL;
		return -15;
	}

	if (testUF.Unite(p, 1, 2) != &testUF){
		UNIT_TEST_FAIL;
		return -16;
	}

	if (testUF.Unite(p, 1, 2) != NULL){
		UNIT_TEST_FAIL;
		return -17;
	}

	if (testUF.Size(p, 0) != 3){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testUF.Size(p, 1) != 2){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testUF.Size(p, 2) != 2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testUF.Size(p, 3) != 3){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testUF.Size(p, 4) != 3){
		UNIT_TEST_FAIL;
		return -22;
	}

	testUF.Destroy(p);
	UNION_FIND_DESTRUCTOR(p);
	p = NULL;

	return 0;
}

int UnitTest_Heap(void)
{
	return 0;
}

int UnitTest_Graph(void)
{
	return 0;
}

int UnitTest_Kruskal(void)
{
	return 0;
}
