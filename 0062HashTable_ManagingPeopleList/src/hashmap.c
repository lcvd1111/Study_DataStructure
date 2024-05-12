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
	for (int i=0 ; i<this->tableSize ; i++){
		LIST_METHOD_CONSTRUCTOR(this->table + i);
	}

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

	//When the table is empty.
	if (this->currentSize == 0){
		return NULL;
	}

	index = (this->Method->Hash)(this, keyArg);

	if (((this->table)[index].Method->IsEmpty)(&((this->table)[index])) != 0){
		//When the table[h(key)] is empty.
		return NULL;
	}

	//When the table[h(key) is not empty.
	ret = (this->table)[index].begin;
	while (ret != NULL){
		if (strcmp(ret->key, keyArg) == 0){
			//Search Complete!
			break;
		}
		else {
			ret = ret->next;
		}
	}

	//If there is no element in hashtable whose key value is equivalent to keyArg,
	//Then the below statement naturally returns 'NULL'.
	return ret;
}

HASHMAP *HASHMAP_METHOD_Insert(HASHMAP *this, char *keyArg, char *dataArg)
{
	int index = 0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	if ((this->Method->Search)(this, keyArg) != NULL){
		//When there is already an element in the hashtable whose key value is equivalent to keyArg.
		return NULL;
	}

	index = (this->Method->Hash)(this, keyArg);
	((this->table)[index].Method->AddElement)(this->table + index, keyArg, dataArg);
	this->currentSize += 1;

	//Calculating the collision Number.
	if ((this->table)[index].size > 1){
		this->collisionNum += 1;
#ifdef DEBUG_ON
		printf(COLOR_BG_CYAN "[JYJO DEBUG] Collision Occured!"
				"H(%s, %d)=%d, H(%s, %d)=%d" COLOR_BG_WHITE "\n"
				, keyArg, this->tableSize, (this->Method->Hash)(this, keyArg),
				(this->table)[index].begin->key, this->tableSize, (this->Method->Hash)(this, (this->table)[index].begin->key));
#endif
	}

	//Rehashing should be done if table is too full.
	if ((this->currentSize)*3 > (this->tableSize)*2){
		(this->Method->Rehash)(this);
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_Delete(HASHMAP *this, char *keyArg)
{
	int index = 0;
	HASHMAP_NODE *deleteArg = NULL;
	
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the table is empty.
	if (this->currentSize == 0){
		return NULL;
	}

	deleteArg = (this->Method->Search)(this, keyArg);

	//When the element with keyArg doesn't exist.
	if ( deleteArg == NULL){
		return NULL;
	}

	index = (this->Method->Hash)(this, keyArg);
	((this->table)[index].Method->DeleteElement)(this->table + index, deleteArg);
	this->currentSize -= 1;

	//Calculating the collision Number.
	if ((this->table)[index].size > 0){
		this->collisionNum -= 1;
	}

	return this;
}

HASHMAP *HASHMAP_METHOD_Rehash(HASHMAP *this)
{
	int oldTableSize = 0;
	int newTableSize = 0;
#ifdef DEBUG_ON
	int oldCollisionNum = 0;
#endif
	LIST *oldTable = NULL;
	LIST *newTable = NULL;

	LIST *buf_List = NULL;
	LIST_NODE *buf_Node = NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	oldTableSize = this->tableSize;
	newTableSize = 2*oldTableSize;
	oldTable = this->table;
	newTable = (LIST *)malloc(sizeof(LIST) * newTableSize);
	for (int i=0 ; i<newTableSize ; i++){
		LIST_METHOD_CONSTRUCTOR(newTable + i);
	}

#ifdef DEBUG_ON
	oldCollisionNum = this->collisionNum;
#endif

	this->currentSize = 0;
	this->collisionNum = 0;
	this->tableSize = newTableSize;
	this->table = newTable;

	for (int i=0 ; i<oldTableSize ; i++){
		buf_List = oldTable + i;
		if ((buf_List->Method->IsEmpty)(buf_List) == 0){
			buf_Node = buf_List->begin;
			for (int j=0 ; j<buf_List->size ; j++){
				(this->Method->Insert)(this, buf_Node->key, buf_Node->data);
				buf_Node = buf_Node->next;
			}
		}
		else {
			continue;
		}
	}
#ifdef DEBUG_ON
		printf(COLOR_BG_YELLOW "[JYJO DEBUG] Rehashing is Done!"
				"TableSize: %d->%d, CollisionNum: %d->%d" COLOR_BG_WHITE "\n"
				, oldTableSize, this->tableSize,
				oldCollisionNum, this->collisionNum);
#endif

	return this;
}

HASHMAP *HASHMAP_METHOD_MakeEmpty(HASHMAP *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->tableSize ; i++){
		LIST_METHOD_DESTRUCTOR(this->table + i);
	}

	free(this->table);
	this->table = NULL;
	HASHMAP_METHOD_CONSTRUCTOR(this);

	return this;
}

HASHMAP *HASHMAP_METHOD_Print(HASHMAP *this)
{
	HASHMAP_NODE *buf_node = NULL;
	LIST *buf_list = NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the Hashmap is empty.
	if (this->currentSize == 0){
		return this;
	}

	for (int i=0 ; i<this->tableSize ; i++){
		buf_list = (this->table)+i;
		if ((buf_list->Method->IsEmpty)(buf_list) == 1){
			continue;
		}
		else {
			buf_node = buf_list->begin;
			while(buf_node != NULL){
				printf("[key]:%s, [data]:%s, ", buf_node->key, buf_node->data);
				printf("[Hash(%s, %d)]:%d, [Index]:%d\n", buf_node->key, this->tableSize, (this->Method->Hash)(this, buf_node->key), i);
				buf_node = buf_node->next;
			}
		}
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
