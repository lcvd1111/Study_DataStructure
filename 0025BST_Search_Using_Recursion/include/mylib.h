#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define NAME_MAX 32
#define STACK_MAX 100

//Type Declaration and Definitions
typedef struct _BINTREE_NODE {
	int number;
	char name[NAME_MAX];
	struct _BINTREE_NODE *left, *right;
} BINTREE_NODE;

typedef struct _STACK {
	BINTREE_NODE *stackArray[STACK_MAX];
	int end;
} STACK;

//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
int DeleteStack(STACK *);
int DeleteBintree(BINTREE_NODE *);
BINTREE_NODE *Search_Recursive(BINTREE_NODE *, int);

#endif
