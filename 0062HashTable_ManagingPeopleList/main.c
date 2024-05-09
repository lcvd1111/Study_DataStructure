#include "interface.h"
#include "test.h"

int main(void)
{
	int err = 0;
#ifdef UNITTEST_ON
	//UNITTEST_ON is defined in ./include/common.h
	if (err = UnitTest()){
		PRINTF_ERROR("ERROR: UnitTest() failed.\n");
		printf("Error Code: %d\n", err);
		return -1;
	}
	
#endif

	if (err = Ui_Main()){
		PRINTF_ERROR("ERROR: Ui_Main() failed.\n");
		printf("Error Code: %d\n", err);
		return -2;
	}

	return 0;
}
