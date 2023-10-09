#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	this->nodeArray = NULL;
	this->size = -1;

	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->nodeArray == NULL){
		return ;
	}

	(*this).Destroy();
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Excetion Handling
	if (this->nodeArray != NULL){
		DEBUG << "ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	//Excetion Handling2
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg < 1." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = new std::vector<int>[sizeArg];
	for (int i=0 ; i<sizeArg ; i++){
		(*this).nodeArray[i].push_back(i);
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	delete[] (this->nodeArray);

	this->nodeArray = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (nodeA >= this->size){
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling3
	if (nodeB >= this->size){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(*this).nodeArray[nodeA].push_back(nodeB);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	std::vector<int>::iterator tempNode;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		std::cout << "[Node]: " << (*this).nodeArray[i][0] << " [Edge]: ";
		tempNode = (*this).nodeArray[i].begin();
		tempNode++;
		while(tempNode != (*this).nodeArray[i].end()){
			std::cout << *tempNode << " ";
			tempNode ++;
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::DFS_1(std::vector<int> &outputStore)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	return this;
}

GRAPH *GRAPH::DFS_2(std::vector<int> &outputStore)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	return this;
}
