#include "lib_unionfind.h"

void UNION_FIND_CONSTRUCTOR(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->predecessorArray = NULL;
	this->sizeArray = NULL;
	this->collectionSize = -1;

	this->Create = &UNION_FIND_METHOD_Create;
	this->Destroy = &UNION_FIND_METHOD_Destroy;
	this->Unite = &UNION_FIND_METHOD_Unite;
	this->Find = &UNION_FIND_METHOD_Find;
	this->Size = &UNION_FIND_METHOD_Size;
	this->Same = &UNION_FIND_METHOD_Same;
	this->EntireSize = &UNION_FIND_METHOD_EntireSize;

	return ;
}

void UNION_FIND_DESTRUCTOR(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->collectionSize == -1){
		return ;
	}

	(this->Destroy)(this);
	return ;
}

UNION_FIND *UNION_FIND_METHOD_Create(UNION_FIND *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->collectionSize != -1){
		DEBUG("ERROR: Union-Find is not empty currently.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg is smaller than 1.\n");
		return NULL;
	}

	this->collectionSize = sizeArg;
	this->predecessorArray = (int *)malloc(sizeof(int)*sizeArg);
	this->sizeArray = (int *)malloc(sizeof(int)*sizeArg);

	for (int i=0; i<sizeArg ; i++){
		(this->predecessorArray)[i] = i;
		(this->sizeArray)[i] = 1;
	}

	return this;
}

UNION_FIND *UNION_FIND_METHOD_Destroy(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return NULL;
	}

	this->collectionSize = -1;
	this->predecessorArray = NULL;
	this->sizeArray = NULL;

	return this;
}

UNION_FIND *UNION_FIND_METHOD_Unite(UNION_FIND *this, int indexA, int indexB)
{
	int *pSuccessorArray=NULL, *pSizeArray=NULL;
	int setA=0, setB=0, sizeA=0, sizeB=0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return NULL;
	}

	//Exception Handling
	if (indexA >= this->collectionSize){
		DEBUG("ERROR: indexA >= collectionSize.\n");
		return NULL;
	}

	//Exception Handling
	if (indexB >= this->collectionSize){
		DEBUG("ERROR: indexB >= collectionSize.\n");
		return NULL;
	}

	pSuccessorArray = this->predecessorArray;
	pSizeArray = this->sizeArray;

	setA = (*this).Find(this, indexA);
	setB = (*this).Find(this, indexB);

	if (setA == setB){
		//When the indexA and indexB is already in the same set.
		return NULL;
	}
	
	sizeA = (*this).Size(this, setA);
	sizeB = (*this).Size(this, setB);

	if (sizeA >= sizeB){
		pSuccessorArray[setB] = setA;
		pSizeArray[setA] = pSizeArray[setA] + pSizeArray[setB];
	}
	else {
		pSuccessorArray[setA] = setB;
		pSizeArray[setB] = pSizeArray[setA] + pSizeArray[setB];
	}

	return this;
}

int UNION_FIND_METHOD_Find(UNION_FIND *this, int indexArg)
{
	int ret = 0;
	int *pSuccessorArray = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (indexArg >= this->collectionSize){
		DEBUG("ERROR: indexArg >= collectionSize.\n");
		return -3;
	}

	pSuccessorArray = this->predecessorArray;

#if !defined(USE_RECURSION)
	ret = indexArg;

	while(pSuccessorArray[ret] != ret){
		ret = pSuccessorArray[ret];
	}

	return ret;
#else
	ret = pSuccessorArray[indexArg];
	if (ret != indexArg){
		return ((*this).Find(this, ret));
	}
	else if (ret == indexArg){
		return ret;
	}
#endif
}

int UNION_FIND_METHOD_Size(UNION_FIND *this, int indexArg)
{
	int ret = 0;
	int *pSizeArray = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (indexArg >= this->collectionSize){
		DEBUG("ERROR: indexArg >= collectionSize.\n");
		return -3;
	}

	pSizeArray = this->sizeArray;
	ret = (*this).Find(this, indexArg);
	ret = pSizeArray[ret];

	return ret;
}

int UNION_FIND_METHOD_Same(UNION_FIND *this, int indexA, int indexB)
{
	int ret = 0;
	int setA=0, setB=0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (indexA >= this->collectionSize){
		DEBUG("ERROR: indexA >= collectionSize.\n");
		return -3;
	}

	//Exception Handling
	if (indexB >= this->collectionSize){
		DEBUG("ERROR: indexB >= collectionSize.\n");
		return -4;
	}

	setA = (*this).Find(this, indexA);
	setB = (*this).Find(this, indexB);

	ret = (setA==setB)?1:0;

	return ret;
}

int UNION_FIND_METHOD_EntireSize(UNION_FIND *this)
{
	int ret = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG("ERROR: Union-Find is empty currently.\n");
		return -2;
	}

	ret = this->collectionSize;

	return ret;
}
