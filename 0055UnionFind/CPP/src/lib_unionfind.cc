#include "lib_unionfind.hh"

UNION_FIND::_UNION_FIND(void)
{
	this->size = -1;

	predecessorArray.clear();
	setSizeArray.clear();

	return ;
}

UNION_FIND::~_UNION_FIND(void)
{
	return ;
}

UNION_FIND *UNION_FIND::Create(int sizeArg)
{
	if (this->size != -1){
		DEBUG<<"ERROR: UnionFind is not Empty currently."<<std::endl;
		return NULL;
	}

	this->size = sizeArg;
	for (int i=0 ; i<this->size ; i++){
		(this->predecessorArray).push_back(i);
		(this->setSizeArray).push_back(1);
	}
	return this;
}

UNION_FIND *UNION_FIND::Destroy(void)
{
	if (this->size == -1){
		return this;
	}

	this->size = -1;
	predecessorArray.clear();
	setSizeArray.clear();

	return this;
}

int UNION_FIND::Find(int indexArg)
{
	int ret = 0;
	std::vector<int> &pSuccessorArray = this->predecessorArray;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: UnionFind is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (this->size <= indexArg){
		DEBUG << "ERROR: indexArg >= UnionFindSize" << std::endl;
		return -2;
	}

	ret = pSuccessorArray[indexArg];
	while(ret != pSuccessorArray[ret]){
		ret = pSuccessorArray[ret];
	}

	return ret;
}

UNION_FIND *UNION_FIND::Unite(int indexA, int indexB)
{
	int setA=0, setB=0;
	int sizeA=0, sizeB=0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: UnionFind is empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (this->size <= indexA){
		DEBUG << "ERROR: indexA >= UnionFindSize" << std::endl;
		return NULL;
	}

	//Exception Handling
	if (this->size <= indexB){
		DEBUG << "ERROR: indexB >= UnionFindSize" << std::endl;
		return NULL;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB){
		return NULL;
	}

	sizeA = (*this).SetSize(setA);
	sizeB = (*this).SetSize(setB);

	if (sizeA >= sizeB){
		(*this).predecessorArray[setB] = setA;
		(*this).setSizeArray[setA] = (*this).setSizeArray[setA] + (*this).setSizeArray[setB];
	}
	else {
		(*this).predecessorArray[setA] = setB;
		(*this).setSizeArray[setB] = (*this).setSizeArray[setA] + (*this).setSizeArray[setA];
	}

	return this;
}

int UNION_FIND::Same(int indexA, int indexB)
{
	int setA=0, setB=0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: UnionFind is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (this->size <= indexA){
		DEBUG << "ERROR: indexA >= UnionFindSize" << std::endl;
		return -2;
	}

	//Exception Handling
	if (this->size <= indexB){
		DEBUG << "ERROR: indexB >= UnionFindSize" << std::endl;
		return -3;
	}

	setA = (*this).Find(indexA);
	setB = (*this).Find(indexB);

	if (setA == setB){
		return 1;
	}

	return 0;
}

int UNION_FIND::CollectionSize(void)
{
	int ret = 0;
	ret = this->size;
	return ret;
}

int UNION_FIND::SetSize(int indexArg)
{
	int ret = 0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: UnionFind is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (this->size <= indexArg){
		DEBUG << "ERROR: indexArg >= UnionFindSize" << std::endl;
		return -2;
	}

	ret = (*this).Find(indexArg);
	ret = (this->setSizeArray)[ret];

	return ret;
}
