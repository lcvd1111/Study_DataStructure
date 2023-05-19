#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdlib.h>
#include <stdio.h>

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d] " x, __func__, __LINE__, ##__VA_ARGS__)

//DATA TYPE DEFINITION
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum _CHILD_SELECTOR {
	NONE,
	BOTH,
	LEFT,
	RIGHT,
} CHILD_SELECTOR;

typedef struct _DEQUE_NODE {
	BINTREE_NODE *data;
	struct _DEQUE_NODE *prev;
	struct _DEQUE_NODE *next;
} DEQUE_NODE;

typedef struct _DEQUE {
	DEQUE_NODE *begin;
	DEQUE_NODE *end;
} DEQUE;


//FUNCTION DECLARATION
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int LevelOrder(BINTREE_NODE *);
int EmptyBintree(BINTREE_NODE *);
DEQUE *InsertLeft(DEQUE *, BINTREE_NODE *);
BINTREE_NODE *DeleteLeft(DEQUE *);
DEQUE *InsertRight(DEQUE *, BINTREE_NODE *);
BINTREE_NODE *DeleteRight(DEQUE *);
DEQUE *EmptyDeque(DEQUE *);

#endif
