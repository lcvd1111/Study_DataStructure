#ifndef __HASHMAP_HEADER__
#define __HASHMAP_HEADER__

#include "common.h"

//Definitions and Declarations of type.
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

struct _LINKED_LIST_NODE_METHOD {
	LINKED_LIST_NODE *(*SetName)(LINKED_LIST_NODE *this, char *nameArg);
	LINKED_LIST_NODE *(*SetNumber)(LINKED_LIST_NODE *this, int numberArg);
};

struct _LINKED_LIST {
	//Member Variables
	LINKED_LIST_NODE *begin;
	LINKED_LIST_NODE *end;
	int size;

	//Member Functions
	LINKED_LIST_METHOD *Method;
};

struct _LINKED_LIST_METHOD {
	LINKED_LIST *(*AddElement)(LINKED_LIST *this, char *nameArg, int numberArg);
	LINKED_LIST *(*DeleteElement)(LINKED_LIST *this, LINKED_LIST_NODE *nodeArg);
};

struct _HASHMAP {
	//Member Variables
	LINKED_LIST *table;
	int tableSize;
	int elementSize;
	int collisionNum;

	//Member Functions
	HASHMAP_METHOD *Method;
};

struct _HASHMAP_METHOD {
	HASHMAP *(*Insert)(HASHMAP *this, char *nameArg, int numberArg);
	HASHMAP *(*Search)(HASHMAP *this, char *nameArg, LINKED_LIST_NODE **destArg);
	HASHMAP *(*Delete)(HASHMAP *this, char *nameArg);
	HASHMAP *(*Rehash)(HASHMAP *this);
	int (*Hash)(HASHMAP *this, char *nameArg);
	void (*Print)(HASHMAP *this);
};

//Declarations of Functions
void LINKED_LIST_NODE_METHOD_CONSTRUCTOR(LINKED_LIST_NODE *this);
void LINKED_LIST_NODE_METHOD_DESTRUCTOR(LINKED_LIST_NODE *this);
LINKED_LIST_NODE *LINKED_LIST_NODE_METHOD_SetName(LINKED_LIST_NODE *this, char *nameArg);
LINKED_LIST_NODE *LINKED_LIST_NODE_METHOD_SetNumber(LINKED_LIST_NODE *this, int numberArg);

void LINKED_LIST_METHOD_CONSTRUCTOR(LINKED_LIST *this);
void LINKED_LIST_METHOD_DESTRUCTOR(LINKED_LIST *this);
LINKED_LIST *LINKED_LIST_METHOD_AddElement(LINKED_LIST *this, char *nameArg, int numberArg);
LINKED_LIST *LINKED_LIST_METHOD_DeleteElement(LINKED_LIST *this, LINKED_LIST_NODE *nodeArg);

void HASHMAP_METHOD_CONSTRUCTOR(HASHMAP *this);
void HASHMAP_METHOD_DESTRUCTOR(HASHMAP *this);
HASHMAP *HASHMAP_METHOD_Insert(HASHMAP *this, char *nameArg, int numberArg);
HASHMAP *HASHMAP_METHOD_Search(HASHMAP *this, char *nameArg, LINKED_LIST_NODE **destArg);
HASHMAP *HASHMAP_METHOD_Delete(HASHMAP *this, char *nameArg);
HASHMAP *HASHMAP_METHOD_Rehash(HASHMAP *this);
int HASHMAP_METHOD_Hash(HASHMAP *this, char *nameArg);
void HASHMAP_METHOD_Print(HASHMAP *this);

#endif
