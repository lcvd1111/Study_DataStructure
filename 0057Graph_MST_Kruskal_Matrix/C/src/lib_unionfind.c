#include "lib_unionfind.h"

//Function Definitions
void UNION_FIND_CONSTRUCTOR(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->successorVector = NULL;
	this->sizeVector = NULL;
	this->entireSize = 0;

	//Binding Method Functions
	this->Create = &UNION_FIND_METHOD_Create;
	this->Destroy = &UNION_FIND_METHOD_Destroy;
	this->Unite = &UNION_FIND_METHOD_Unite;
	this->Find = &UNION_FIND_METHOD_Find;
	this->Size = &UNION_FIND_METHOD_Size;
	this->EntireSize = &UNION_FIND_METHOD_EntireSize;
	this->Same = &UNION_FIND_METHOD_Same;

	return ;
}

void UNION_FIND_DESTRUCTOR(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->entireSize != 0){
		(*this).Destroy(this);
	}

	return ;
}

UNION_FIND *UNION_FIND_METHOD_Create(UNION_FIND *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize != 0){
		PRINTF_ERROR("ERROR: The UnionFind already exists currently.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	this->entireSize = sizeArg;
	this->successorVector = (int *)malloc(sizeof(int)*sizeArg);
	this->sizeVector = (int *)malloc(sizeof(int)*sizeArg);


	for (int i=0 ; i<sizeArg ; i++){
		(this->successorVector)[i] = i;
		(this->sizeVector)[i] = 1;
	}

	return this;
}

UNION_FIND *UNION_FIND_METHOD_Destroy(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize == 0){
		PRINTF_ERROR("ERROR: The UnionFind already doesn't exist currently.\n");
		return NULL;
	}

	this->entireSize = 0;
	free(this->successorVector);
	free(this->sizeVector);
	this->successorVector = NULL;
	this->sizeVector = NULL;

	return this;
}

UNION_FIND *UNION_FIND_METHOD_Unite(UNION_FIND *this, int nodeA, int nodeB)
{
	int setA=0, setB=0;
	int sizeA=0, sizeB = 0;
	int *pPredecessorVector = NULL;
	int *pSizeVector = NULL;

	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize == 0){
		PRINTF_ERROR("ERROR: UnionFind doesn't exist currently.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeA > entireSize.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeB > entireSize.\n");
		return NULL;
	}

	if ((*this).Same(this, nodeA, nodeB)){
		return NULL;
	}

	pPredecessorVector = this->successorVector;
	pSizeVector = this->sizeVector;

	setA = (*this).Find(this, nodeA);
	setB = (*this).Find(this, nodeB);
	sizeA = (*this).Size(this, nodeA);
	sizeB = (*this).Size(this, nodeB);

	if (sizeA >= sizeB){
		pPredecessorVector[setB] = setA;
		pSizeVector[setA] = pSizeVector[setA] + pSizeVector[setB];
		pSizeVector[setB] = 0;
		return this;
	}

	pPredecessorVector[setA] = setB;
	pSizeVector[setB] = pSizeVector[setA] + pSizeVector[setB];
	pSizeVector[setA] = 0;
	return this;
}

int UNION_FIND_METHOD_Find(UNION_FIND *this, int nodeArg)
{
	int ret = 0;
	int *pPredecessorVector = NULL;

	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0){
		PRINTF_ERROR("ERROR: UnionFind doesn't exist currently.\n");
		return -2;
	}

	//Exception Handling
	if (nodeArg >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeArg > entireSize.\n");
		return -3;
	}

	pPredecessorVector = this->successorVector;
	ret = nodeArg;
	while(ret != pPredecessorVector[ret]){
		ret = pPredecessorVector[ret];
	}

	return ret;
}

int UNION_FIND_METHOD_Size(UNION_FIND *this, int nodeArg)
{
	int ret = 0;
	int *pSizeVector = NULL;

	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0){
		PRINTF_ERROR("ERROR: UnionFind doesn't exist currently.\n");
		return -2;
	}

	//Exception Handling
	if (nodeArg >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeArg > entireSize.\n");
		return -3;
	}

	pSizeVector = this->sizeVector;
	ret = (*this).Find(this, nodeArg);
	ret = pSizeVector[ret];

	return ret;
}

int UNION_FIND_METHOD_EntireSize(UNION_FIND *this)
{
	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return (this->entireSize);
}

int UNION_FIND_METHOD_Same(UNION_FIND *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0){
		PRINTF_ERROR("ERROR: UnionFind doesn't exist currently.\n");
		return -2;
	}

	//Exception Handling
	if (nodeA >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeA > entireSize.\n");
		return -3;
	}

	//Exception Handling
	if (nodeB >= (this->entireSize)){
		PRINTF_ERROR("ERROR: nodeB > entireSize.\n");
		return -4;
	}

	return (int)( ((*this).Find(this, nodeA))
				  == ((*this).Find(this, nodeB)) );
}
