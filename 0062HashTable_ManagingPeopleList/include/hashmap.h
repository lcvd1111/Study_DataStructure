#ifndef __HASHMAP_HEADER__
#define __HASHMAP_HEADER__

#include "common.h"
#include "list.h"

//Type Definitions and Delcarations
typedef struct _HASHMAP HASHMAP;
typedef struct _HASHMAP_METHOD HASHMAP_METHOD;
typedef LIST_NODE HASHMAP_NODE;

struct _HASHMAP {
	//Member Variables
	LIST *table;
	int tableSize;
	int currentSize;
	int collisionNum;

	//Member Functions
	HASHMAP_METHOD *Method;
};

struct _HASHMAP_METHOD {
	int (*Hash)(HASHMAP *this, char *keyArg);
	HASHMAP_NODE *(*Search)(HASHMAP *this, char *keyArg);
	HASHMAP *(*Insert)(HASHMAP *this, char *keyArg, char *dataArg);
	HASHMAP *(*Delete)(HASHMAP *this, char *keyArg);
	HASHMAP *(*Rehash)(HASHMAP *this);
	HASHMAP *(*MakeEmpty)(HASHMAP *this);
	HASHMAP *(*Print)(HASHMAP *this);
	int (*GetCurrentSize)(HASHMAP *this);
	int (*GetTableSize)(HASHMAP *this);
	int (*GetCollisionNum)(HASHMAP *this);
};

//Function Declarations for the methods of HASHMAP type.
void HASHMAP_METHOD_CONSTRUCTOR(HASHMAP *this);
void HASHMAP_METHOD_DESTRUCTOR(HASHMAP *this);
int HASHMAP_METHOD_Hash(HASHMAP *this, char *keyArg);
HASHMAP_NODE *HASHMAP_METHOD_Search(HASHMAP *this, char *keyArg);
HASHMAP *HASHMAP_METHOD_Insert(HASHMAP *this, char *keyArg, char *dataArg);
HASHMAP *HASHMAP_METHOD_Delete(HASHMAP *this, char *keyArg);
HASHMAP *HASHMAP_METHOD_Rehash(HASHMAP *this);
HASHMAP *HASHMAP_METHOD_MakeEmpty(HASHMAP *this);
HASHMAP *HASHMAP_METHOD_Print(HASHMAP *this);
int HASHMAP_METHOD_GetCurrentSize(HASHMAP *this);
int HASHMAP_METHOD_GetTableSize(HASHMAP *this);
int HASHMAP_METHOD_GetCollisionNum(HASHMAP *this);

#endif
