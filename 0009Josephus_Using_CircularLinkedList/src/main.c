#include "mylib.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n, k;

	if(UnitTest()!=0){
		return -1;
	}
	printf("Unit Test Success.\n\n\n");

	while(1){
		printf("[Joshephus(n, k) = ???]\n"
				"n=? Input an positive integer: ");
		scanf("%d", &n);
		printf("k=? Input an positive integer: ");
		scanf("%d", &k);
		printf("Josephus(%d, %d)=%d\n\n", n, k, Josephus(n, k));
	}

	return 0;
}
