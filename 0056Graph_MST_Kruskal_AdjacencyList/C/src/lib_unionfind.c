#include "lib_unionfind.h"

void UNION_FIND_CONSTRUCTOR(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: First Argument(='this') is NULL.\n");
		return ;
	}

	this->predecessorVector = NULL;
	this->sizeVector = NULL;
	this->entireSize = 0;

	//Binding Method Functions
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
		PRINTF_ERROR("ERROR: First Argument(='this') is NULL.\n");
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
		PRINTF_ERROR("ERROR: First Argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize != 0 ||
		this->predecessorVector != NULL ||
		this->sizeVector != NULL)
	{
		PRINTF_ERROR("ERROR: UnionFind is not empty currently.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	this->predecessorVector = (int *)malloc(sizeof(sizeArg));
	this->sizeVector = (int *)malloc(sizeof(sizeArg));
	this->entireSize = sizeArg;

	for (int i=0 ; i<(this->entireSize) ; i++){
		(this->predecessorVector)[i] = i;
		(this->sizeVector)[i] = 1;
	}

	return this;
}

UNION_FIND *UNION_FIND_METHOD_Destroy(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: First Argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize == 0 || 
		this->predecessorVector == NULL ||
		this->sizeVector == NULL)
	{
		PRINTF_ERROR("ERROR: \n");
	}

	free(this->predecessorVector);
	this->predecessorVector = NULL;
	free(this->sizeVector);
	this->sizeVector = NULL;
	this->entireSize = 0;
	
	return NULL;
}

UNION_FIND *UNION_FIND_METHOD_Unite(UNION_FIND *this, int argX, int argY)
{
	int setX=0, setY=0, sizeX=0, sizeY=0;

	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->entireSize == 0 ||
		this->predecessorVector == NULL ||
		this->sizeVector == NULL)
	{
		PRINTF_ERROR("ERROR: The UnionFind is empty currently.\n");
		return NULL;
	}

	//Exception Handling
	if (argX >= this->entireSize){
		PRINTF_ERROR("ERROR: argX >= entireSize\n");
		return NULL;
	}

	//Exception Handling
	if (argY >= this->entireSize){
		PRINTF_ERROR("ERROR: argY >= entireSize\n");
		return NULL;
	}

	setX = (*this).Find(this, argX);
	setY = (*this).Find(this, argY);

	//When the argX and argY belongs to the equivalent set.
	if (setX == setY){
		return NULL;
	}

	//When they don't belong to same set.
	sizeX = (*this).Size(this, setX);
	sizeY = (*this).Size(this, setY);

	if (sizeX > sizeY){
		(*this).predecessorVector[setY] = setX;
		(*this).sizeVector[setX] = (*this).sizeVector[setX] + (*this).sizeVector[setY];
		(*this).sizeVector[setY] = 0;
		return this;
	}

	(*this).predecessorVector[setX] = setY;
	(*this).sizeVector[setY] = (*this).sizeVector[setX] + (*this).sizeVector[setY];
	(*this).sizeVector[setX] = 0;
	return this;
}

int UNION_FIND_METHOD_Find(UNION_FIND *this, int arg)
{
	int ret = -1;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0 ||
		this->predecessorVector == NULL ||
		this->sizeVector == NULL)
	{
		PRINTF_ERROR("ERROR: The UnionFind is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (arg>=(this->entireSize)){
		PRINTF_ERROR("ERROR: arg >= entireSize\n");
		return -3;
	}

	ret = arg;

	while(ret != (*this).predecessorVector[ret]){
		ret = (*this).predecessorVector[ret];
	}

	if (ret != (*this).predecessorVector[ret]){
		PRINTF_ERROR("ERROR: Unexpected situation occured.\n");
		return -4;
	}

	return ret;
}

int UNION_FIND_METHOD_Size(UNION_FIND *this, int arg)
{
	int set = 0;
	int ret = 0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0 ||
		this->predecessorVector == NULL ||
		this->sizeVector == NULL)
	{
		PRINTF_ERROR("ERROR: The UnionFind is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (arg >= (this->entireSize)){
		PRINTF_ERROR("ERROR: arg >= entireSize\n");
		return -3;
	}

	set = (*this).Find(this, arg);
	ret = (*this).sizeVector[set];

	return ret;
}

int UNION_FIND_METHOD_Same(UNION_FIND *this, int argX, int argY)
{
	int setX=0, setY=0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->entireSize == 0 ||
		this->predecessorVector == NULL ||
		this->sizeVector == NULL)
	{
		PRINTF_ERROR("ERROR: The UnionFind is empty currently.\n");
		return -2;
	}

	//Exception Handling
	if (argX >= (this->entireSize)){
		PRINTF_ERROR("ERROR: argX >= entireSize\n");
		return -3;
	}

	//Exception Handling
	if (argY >= (this->entireSize)){
		PRINTF_ERROR("ERROR: argY >= entireSize\n");
		return -4;
	}
	setX = (*this).Find(this, argX);
	setY = (*this).Find(this, argY);

	return (int)(setX == setY);
}

int UNION_FIND_METHOD_EntireSize(UNION_FIND *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: The first argument(='this') is NULL.\n");
		return -1;
	}

	return (*this).entireSize;
}
