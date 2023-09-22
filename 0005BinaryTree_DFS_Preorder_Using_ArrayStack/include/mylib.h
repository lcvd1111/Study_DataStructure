#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__
#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 50
#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum _CHILD_SELECTOR {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECTOR;

typedef BINTREE_NODE *STACK_ARRAY[STACK_MAX];

typedef struct _STACK {
	STACK_ARRAY stackArray;
	int end;
} STACK;

//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *, int *);
BINTREE_NODE *Pop(STACK *, int *);
STACK *CleanStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int , int);
BINTREE_NODE *PreOrder(BINTREE_NODE *);
int CleanBintree(BINTREE_NODE *);
#endif
