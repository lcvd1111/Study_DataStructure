#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#define PRINTF( x , ... ) printf("[%s %d]" x , __func__, __LINE__, ##__VA_ARGS__)

typedef struct _BINTREE_NODE {
	int data;
	BINTREE_NODE *left;
	BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILD_SELECTOR;

typedef Me

#endif
