#include "hashmap.h"

HASHMAP_METHOD gHashmapMethod = {
	.Hash = &HASHMAP_METHOD_Hash,
	.Search = &HASHMAP_METHOD_Search,
	.Insert = &HASHMAP_METHOD_Insert,
	.Delete = &HASHMAP_METHOD_Delete,
	.Rehash = &HASHMAP_METHOD_Rehash,
	.MakeEmpty = &HASHMAP_METHOD_MakeEmpty,
	.Print = &HASHMAP_METHOD_Print,
	.GetCurrentSize = &HASHMAP_METHOD_GetCurrentSize,
	.GetTableSize = &HASHMAP_METHOD_GetTableSize,
	.GetCollisionNum = &HASHMAP_METHOD_GetCollisionNum,
};

void HASHMAP_METHOD_CONSTRUCTOR(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	//Initializing the member variables
	this->tableSize = 100;
	this->currentSize = 0;
	this->collisionNum = 0;
	this->table = (LIST *)malloc(sizeof(LIST)*(this->tableSize));

	//Binding the Method Functions
	this->Method = &gHashmapMethod;

	return ;
}

void HASHMAP_METHOD_DESTRUCTOR(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	(this->Method->MakeEmpty)(this);
	free(this->table);

	return ;
}

int HASHMAP_METHOD_Hash(HASHMAP *this, char *keyArg)
{
	int ret = 0;
	int loopNum = 0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	loopNum = NAME_LEN / sizeof(unsigned int);
	for (int i=0 ; i<loopNum ; i++){
		ret += (*(((unsigned int *)keyArg)+i)) % (this->tableSize);
		ret = ret % (this->tableSize);
	}

	return ret;
}

HASHMAP_NODE *HASHMAP_METHOD_Search(HASHMAP *this, char *keyArg)
{
	HASHMAP_NODE *ret = NULL;
	int index = 0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	index = (this->Method->Hash)(this, keyArg);

	if (((this->table)[index].Method->IsEmpty)(&((this->table)[index])) != 0){
		return NULL;
	}

	//작성중

	return ret;
}

HASHMAP *HASHMAP_METHOD_Insert(HASHMAP *this, char *keyArg, char *dataArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_Delete(HASHMAP *this, char *keyArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_Rehash(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_MakeEmpty(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_Print(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

int HASHMAP_METHOD_GetCurrentSize(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return (this->currentSize);
}

int HASHMAP_METHOD_GetTableSize(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return (this->tableSize);
}

int HASHMAP_METHOD_GetCollisionNum(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return (this->collisionNum);
}
