#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	this->matrix = NULL;
	this->size = -1;
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->size == -1)
		return ;

	(*this).Destroy();

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if (this->matrix != NULL){
		DEBUG << "ERROR: Graph is not empty currently." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg<1" << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = new int *[sizeArg];

	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = new int [sizeArg];
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		delete[] (this->matrix)[i];
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
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
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

	(*this).AddEdge_Directed(nodeA, nodeB, weightArg);
	(*this).AddEdge_Directed(nodeB, nodeA, weightArg);

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

int GRAPH::Weight(void)
{
	int ret = 0;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=i ; j<(this->size) ; j++){
			ret += (this->matrix)[i][j];
		}
	}

	return ret;
}

int GRAPH::Dijkstra(int departureArg)
{
	return 0;
}

bool HEAP_COMPARATOR::operator()(HEAP_NODE &nodeA, HEAP_NODE &nodeB)
{
	if (nodeA.distance_from_departure >= nodeB.distance_from_departure)
		return true;

	return false;
}
