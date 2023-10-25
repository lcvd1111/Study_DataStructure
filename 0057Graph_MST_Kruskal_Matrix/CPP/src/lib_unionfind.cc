#include "lib_unionfind.hh"

UNION_FIND::_UNION_FIND(void)
{
	(this->successorVector).clear();
	(this->sizeVector).clear();
	this->collectionSize = -1;

	return ;
}

UNION_FIND::~_UNION_FIND(void)
{
	if (this->collectionSize == -1)
		return ;

	(*this).Destroy();

	return ;
}

UNION_FIND *UNION_FIND::Create(int sizeArg)
{
	if (this->collectionSize != -1){
		DEBUG<<"ERROR: Union-Find is not Empty currently." << std::endl;
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
	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is Empty currently." << std::endl;
		return NULL;
	}

	this->collectionSize = -1;
	(this->successorVector).clear();
	(this->sizeVector).clear();

	return this;
}

UNION_FIND *UNION_FIND::Unite(int indexA, int indexB)
{
	int setA=0, setB=0;
	int sizeA=0, sizeB=0;

	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is Empty currently." << std::endl;
		return NULL;
	}

	if (indexA >= this->collectionSize){
		DEBUG << "ERROR: idnexA >= collectionSize." << std::endl;
		return NULL;
	}

	if (indexB >= this->collectionSize){
		DEBUG << "ERROR: idnexB >= collectionSize." << std::endl;
		return NULL;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB){
		return NULL;
	}

	sizeA = (this->sizeVector)[setA];
	sizeB = (this->sizeVector)[setB];

	if (sizeA >= sizeB){
		(this->successorVector)[setB] = setA;
		(this->sizeVector)[setA] = sizeA + sizeB;
	}
	else {
		(this->successorVector)[setA] = setB;
		(this->sizeVector)[setB] = sizeA + sizeB;
	}

	return this;
}

int UNION_FIND::Find(int indexArg)
{
	int ret = 0;

	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is Empty currently." << std::endl;
		return -1;
	}

	if (indexArg >= this->collectionSize){
		DEBUG << "ERROR: idnexArg >= collectionSize." << std::endl;
		return -2;
	}

	ret = (this->successorVector)[indexArg];

	while((this->successorVector)[ret] != ret){
		ret = (this->successorVector)[ret];
	}

	return ret;
}

int UNION_FIND::Same(int indexA, int indexB)
{
	int setA=0, setB=0;

	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is Empty currently." << std::endl;
		return -1;
	}

	if (indexA >= this->collectionSize){
		DEBUG << "ERROR: idnexA >= collectionSize." << std::endl;
		return -2;
	}

	if (indexB >= this->collectionSize){
		DEBUG << "ERROR: idnexB >= collectionSize." << std::endl;
		return -3;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB)
		return 1;

	return 0;
}

int UNION_FIND::Size(int indexArg)
{
	int ret = 0;

	if (this->collectionSize == -1){
		DEBUG << "ERROR: Union-Find is Empty currently." << std::endl;
		return -1;
	}

	if (indexArg >= this->collectionSize){
		DEBUG << "ERROR: idnexArg >= collectionSize." << std::endl;
		return -2;
	}

	ret = (*this).Find(indexArg);
	ret = (this->sizeVector)[ret];

	return ret;
}
