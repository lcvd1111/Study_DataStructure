#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	matrix = NULL;
	size = -1;
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (matrix == NULL){
		return ;
	}

	(*this).Destroy();
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if (this->matrix != NULL){
		DEBUG<<"ERROR: Graph is not empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG<<"ERROR: sizeArg is smaller than 1." << std::endl;
		return NULL;
	}

	this->matrix = new int *[sizeArg];
	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = new int [sizeArg];
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}
	this->size = sizeArg;

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		delete[] ((this->matrix)[i]);
	}

	delete[] (this->matrix);

	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->size)){
		DEBUG << "nodeA >= size" << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		DEBUG << "nodeB >= size" << std::endl;
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = weightArg;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->size)){
		DEBUG << "nodeA >= size" << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		DEBUG << "nodeB >= size" << std::endl;
		return NULL;
	}

	(this->AddEdge_Directed)(nodeA, nodeB, weightArg);
	(this->AddEdge_Directed)(nodeB, nodeA, weightArg);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			std::cout << (this->matrix)[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

int GRAPH::FloydWarshall(GRAPH &outputStore)
{

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	return 0;
}
