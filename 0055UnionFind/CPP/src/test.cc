#include "test.hh"
#include "lib_unionfind.hh"

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

	if (testUF.SetSize(0) != 3){
		UNIT_TEST_FAIL;
		return -18;
	}

	if (testUF.SetSize(1) != 2){
		UNIT_TEST_FAIL;
		return -19;
	}

	if (testUF.SetSize(2) != 2){
		UNIT_TEST_FAIL;
		return -20;
	}

	if (testUF.SetSize(3) != 3){
		UNIT_TEST_FAIL;
		return -21;
	}

	if (testUF.SetSize(4) != 3){
		UNIT_TEST_FAIL;
		return -22;
	}

	testUF.Destroy();
	return 0;
}
