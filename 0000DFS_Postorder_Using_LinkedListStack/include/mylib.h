#ifndef _MYLIB_HEADER_
#define _MYLIB_HEADER_
#define PRINTF( x , ... ) printf("[FUN:%s LINE:%d] " x , __func__, __LINE__, ##__VA_ARGS__)
#define UNIT_TEST

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

typedef enum _LAST_ACTION {
	TRIED_LEFT,
	TRIED_RIGHT,
	TRIED_NOTHING,
} LAST_ACTION;

typedef struct _STACK_NODE_DATA {
	BINTREE_NODE *data_Address;
	LAST_ACTION data_Action;
} STACK_NODE_DATA;

typedef struct _STACK_NODE {
	STACK_NODE_DATA structData;
	struct _STACK_NODE *next;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
BINTREE_NODE *Post_order_Traversal(BINTREE_NODE *);
int CleanBintree(BINTREE_NODE *);
STACK *Push(STACK *, BINTREE_NODE *, LAST_ACTION);
STACK_NODE_DATA *Pop(STACK *, STACK_NODE_DATA *);
STACK *CleanStack(STACK *);


#endif
