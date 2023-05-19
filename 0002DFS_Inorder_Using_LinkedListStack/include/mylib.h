#ifndef __MYLIB_HEADER_
#define __MYLIB_HEADER_

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x , __func__ , __LINE__ , ##__VA_ARGS__)

typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum _CHILD_SELECT {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECT;

typedef struct _STACK_NODE {
	BINTREE_NODE *data;
	struct _STACK_NODE *next;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECT selector, int leftArg, int rightArg);
BINTREE_NODE *InorderTraverse(BINTREE_NODE *);
BINTREE_NODE *CleanBintree(BINTREE_NODE *);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
STACK *CleanStack(STACK *);
#endif
