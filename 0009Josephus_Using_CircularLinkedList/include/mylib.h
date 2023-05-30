#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Data Type Definitions
typedef struct _CIRCULAR_LIST_NODE {
	int number;
	struct _CIRCULAR_LIST_NODE *next;
	struct _CIRCULAR_LIST_NODE *prev;
} CIRCULAR_LIST_NODE;

typedef struct _CIRCULAR_LIST {
	CIRCULAR_LIST_NODE *begin;
	CIRCULAR_LIST_NODE *current;
} CIRCULAR_LIST;


//Function Declarations
CIRCULAR_LIST *Add_List(CIRCULAR_LIST *, int );
CIRCULAR_LIST *Create_List(int );
CIRCULAR_LIST *Kill_Current(CIRCULAR_LIST *listArg);
int Destroy_List(CIRCULAR_LIST *);
CIRCULAR_LIST *Move_One(CIRCULAR_LIST *);
CIRCULAR_LIST *Move_Several(CIRCULAR_LIST *, int );
int Josephus(int n, int k);

#endif
