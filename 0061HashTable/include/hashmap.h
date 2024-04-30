#ifndef __HASHMAP_HEADER__
#define __HASHMAP_HEADER__

#include "common.h"

typedef struct _LINKED_LIST_NODE LINKED_LIST_NODE;
typedef struct _LINKED_LIST LINKED_LIST;
typedef struct _HASHMAP HASHMAP;

typedef struct _LINKED_LIST_NODE_METHOD LINKED_LIST_NODE_METHOD;
typedef struct _LINKED_LIST_METHOD LINKED_LIST_METHOD;
typedef struct _HASHMAP_METHOD HASHMAP_METHOD;

struct _LINKED_LIST_NODE {
	//Member Variables
	char name[NAME_LEN];
	int number;
	LINKED_LIST_NODE *next;
	LINKED_LIST_NODE *prev;

	//Member Functions
	LINKED_LIST_NODE_METHOD *Method;
};

struct _LINKED_LIST {
	//Member Variables
	LINKED_LIST_NODE *begin;
	LINKED_LIST_NODE *end;
	int size;

	//Member Functions
	LINKED_LIST_METHOD *Method;
};

struct _HAHSMAP {
	//Member Variables
	LINKED_LIST *table;
	int tableSize;
	int elementSize;
	int collisionNum;

	//Member Functions
	HASHMAP_METHOD *Method;
};

#endif
