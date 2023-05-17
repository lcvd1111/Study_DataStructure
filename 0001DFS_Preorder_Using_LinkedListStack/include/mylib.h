#ifndef _MYLIB_HEADER_
#define _MYLIB_HEADER_

#define PRINTF( x , ... ) printf("[FUN:%s LINE:%d]" x , __func__, __LINE__)

//Data type Definition
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

typedef struct _STACK_NODE {
		BINTREE_NODE *data;
		struct _STACK_NODE *next;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

//Function Declaration
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector,int leftArg, int rightArg);
int PreorderTraverse(BINTREE_NODE *);
int CleanBintree(BINTREE_NODE *root);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
STACK *CleanStack(STACK *);
#endif
