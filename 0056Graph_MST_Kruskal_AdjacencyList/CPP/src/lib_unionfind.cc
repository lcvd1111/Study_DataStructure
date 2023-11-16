#include "lib_unionfind.hh"

//Function Definitions
UNION_FIND::_UNION_FIND(void)
{
	this->collectionSize = -1;
	(this->successorVector).clear();
	(this->sizeVector).clear();

	return ;
}

UNION_FIND::~_UNION_FIND(void)
{
	if (this->collectionSize == -1){
		return ;
	}

	(this->Destroy)();

	return ;
}

UNION_FIND *UNION_FIND::Create(int sizeArg)
{
	//Exception Handling
	if (this->collectionSize != -1){
		DEBUG << "ERROR: Union-Find is not empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg < 1" << std::endl;
		return NULL;
	}

	this->collectionSize = sizeArg;
	for (int i=0 ; i<sizeArg ; i++){
		(this->successorVector).push_back(i);
		(this->sizeVector).push_back(1);
	}

	return this;
}

UNION_FIND *UNION_FIND::Destroy(void)
{
	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is empty currently." << std::endl;
		return NULL;
	}

	(this->successorVector).clear();
	(this->sizeVector).clear();
	this->collectionSize = -1;

	return this;
}

UNION_FIND *UNION_FIND::Unite(int indexA, int indexB)
{
	int setA=0, setB=0;
	int sizeA=0, sizeB=0;

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (indexA >= this->collectionSize){
		DEBUG << "ERROR: indexA >= collectionSize." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (indexB >= this->collectionSize){
		DEBUG << "ERROR: indexB >= collectionSize." << std::endl;
		return NULL;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB){
		return NULL;
	}

	sizeA = (*this).Size(indexA);
	sizeB = (*this).Size(indexB);

	if (sizeA >= sizeB){
		(*this).successorVector[setB] = setA;
		(*this).sizeVector[setA] = sizeA + sizeB;
	}
	else {
		(*this).successorVector[setA] = setB;
		(*this).sizeVector[setB]  = sizeA + sizeB;
	}

	return this;
}

int UNION_FIND::Find(int indexArg)
{
	int ret = 0;

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is empty currently." << std::endl;
		return -1;
	}

	ret = (*this).successorVector[indexArg];

	while((*this).successorVector[ret] != ret){
		ret = (*this).successorVector[ret];
	}

	return ret;
}

int UNION_FIND::Size(int indexArg)
{
	int ret = 0;

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (indexArg >= this->collectionSize){
		DEBUG << "ERROR: indexArg >= collectionSize." << std::endl;
		return -2;
	}

	ret = (*this).sizeVector[(*this).Find(indexArg)];

	return ret;
}

int UNION_FIND::Same(int indexA, int indexB)
{
	int setA=0, setB=0;

	//Exception Handling
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (indexA >= this->collectionSize){
		DEBUG << "ERROR: indexA >= collectionSize." << std::endl;
		return -2;
	}

	//Exception Handling
	if (indexB >= this->collectionSize){
		DEBUG << "ERROR: indexB >= collectionSize." << std::endl;
		return -3;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB)
		return 1;

	return 0;
}
