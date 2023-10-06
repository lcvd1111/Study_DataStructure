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
	if (this->nodeArray == NULL)
		return ;

	(*this).Destroy();

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if (this->nodeArray != NULL){
		DEBUG << "ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg is smaller than 1." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = new std::vector<int> [sizeArg];
	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeArray)[i].clear();
		(this->nodeArray)[i].push_back(i);
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
	std::vector<int> *pNodeArray = NULL;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling1
	if (nodeA >= this->size){
		DEBUG << "ERROR: nodeA >= size" << std::endl;
		return NULL;
	}

	//Exception Handling1
	if (nodeB >= this->size){
		DEBUG << "ERROR: nodeB >= size" << std::endl;
		return NULL;
	}

	pNodeArray = this->nodeArray;

	pNodeArray[nodeA].push_back(nodeB);


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

int GRAPH::RecursiveDFS
(int nextNode, std::vector<char> &visitVector, std::vector<int> &outputStore)
{
	int ret = 0;
	std::vector<int>::iterator currentNode, tempNode;
	std::vector<int> *pNodeArray = this->nodeArray;

	//Current Node visitCheck.
	currentNode = pNodeArray[nextNode].begin();
	visitVector[*currentNode] = 2;
	outputStore.insert(outputStore.end(), *currentNode);

	//Traversing neighbors.
	tempNode = pNodeArray[*currentNode].begin();
	tempNode++;
	for ( ; tempNode != pNodeArray[*currentNode].end() ; tempNode++){
		if (visitVector[*tempNode] != 0){
			//When the neighbor is already visited.
			continue;
		}
		//When the unvisited neighbor is found.
		RecursiveDFS(*tempNode, visitVector, outputStore);
	}

	//When the traversing neighbors is compelted. = Base Case.

	return ret;
}

GRAPH *GRAPH::DFS(std::vector<int> &outputStorage)
{
	std::vector<char> visitVector({});
	std::vector<char> &pVisitVector = visitVector;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Clearing outputStorage and making visitVector
	outputStorage.clear();
	visitVector.assign(this->size, 0);

	//DFS start
	RecursiveDFS(0, pVisitVector, outputStorage);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	std::vector<int> *pNodeArray = NULL;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	pNodeArray = this->nodeArray;

	for (int i=0 ; i<this->size ; i++){
		std::cout << "[Node]: " << pNodeArray[i][0] << " [Edge]: ";
		for (std::vector<int>::iterator j=((pNodeArray[i]).begin()+1) ; j!=(pNodeArray[i]).end() ; j++){
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}

	return this;
}
