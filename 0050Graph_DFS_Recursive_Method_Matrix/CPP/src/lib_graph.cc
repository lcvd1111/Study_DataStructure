#include "lib_graph.hh"

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
	if (matrix != NULL){
		DEBUG << "ERROR: this->matrix is not NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (sizeArg <= 1){
		DEBUG << "ERROR: sizeArg <= 1" << std::endl;
		return NULL;
	}

	size = sizeArg;
	matrix = new int *[sizeArg];
	for (int i=0 ; i<sizeArg ; i++){
		matrix[i] = new int [sizeArg];
		for (int j=0 ; j<sizeArg ; j++){
			matrix[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (matrix == NULL){
		DEBUG << "ERROR: this->matrix is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		delete[] (this->matrix)[i];
	}
	delete[] this->matrix;
	this->matrix = NULL;
	this->size = -1;
	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Exception Handling
	if (matrix == NULL){
		DEBUG << "ERROR: this->matrix is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if (matrix == NULL){
		DEBUG << "ERROR: this->matrix is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (matrix == NULL){
		DEBUG << "ERROR: this->matrix is NULL." << std::endl;
		return NULL;
	}
	
	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::RecursiveDFS
(int nextNode, std::vector<char> &visitVector, std::vector<int> &outputVector)
{
	int currentNode, tempNode;
	currentNode = nextNode;

	//Visit Checking
	visitVector[currentNode] = 2;
	outputVector.push_back(currentNode);

	//Traversing the neighbors
	for (tempNode = 0 ; tempNode<this->size ; tempNode++){
		if ((this->matrix)[currentNode][tempNode]==0){
			continue;
		}
		if (visitVector[tempNode] != 0){
			//When the neigbor was already visited before.
			continue;
		}
		//Univisited neighbor found.
		RecursiveDFS(tempNode, visitVector, outputVector);
	}
	return this;
}

GRAPH *GRAPH::DFS(std::vector<int> &output)
{
	std::vector<char> visitVector({});
	std::vector<char> &pVisitVector = visitVector;

	//Exception Handling
	if (matrix == NULL){
		DEBUG << "ERROR: this->matrix is NULL." << std::endl;
		return NULL;
	}

	//Clearing outputVector and making visitVector.
	visitVector.assign(this->size, 0);
	output.clear();

	(*this).RecursiveDFS(0, pVisitVector, output);

	return this;
}
