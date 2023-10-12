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
	//Exception Handling
	if (this->nodeArray != NULL){
		DEBUG<<"ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (sizeArg < 1){
		DEBUG<<"ERROR: sizeArg<1" << std::endl;
		return NULL;
	}

	(*this).nodeArray = new std::vector<int> [sizeArg];
	this->size = sizeArg;

	for (int i=0 ; i<sizeArg ; i++){
		(*this).nodeArray[i].push_back(i);
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
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
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (this->size <= nodeA){
		DEBUG<<"ERROR: size<=nodeA."<<std::endl;
		return NULL;
	}

	//Exception Handling3
	if (this->size <= nodeA){
		DEBUG<<"ERROR: size<=nodeB."<<std::endl;
		return NULL;
	}

	(this->nodeArray)[nodeA].push_back(nodeB);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		std::cout << "[Node]: " << (*this).nodeArray[i][0] << " [Edge]: ";
		for (std::vector<int>::iterator j=(*this).nodeArray[i].begin()+1 ; j!=(*this).nodeArray[i].end() ; j++){
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::CalcInitialIndegree(std::vector<int> &IndegreeArray)
{
	std::vector<int>::iterator currentNode, tempNode;

	for (int i=0 ; i<this->size ; i++){
		currentNode = (*this).nodeArray[i].begin();

		for (tempNode = (*this).nodeArray[*currentNode].begin()+1 ;
				tempNode != (*this).nodeArray[*currentNode].end() ;
				tempNode++)
		{
			IndegreeArray[*tempNode] += 1;
		}
	}

	return this;
}

GRAPH *GRAPH::TopologicalSorting(std::vector<int> &outputStore)
{
	std::vector<int> indegreeVector;
	std::vector<int> &pIndegreeVector = indegreeVector;
	std::vector<int>::iterator currentNode, tempNode;
	std::deque<int> zeroIndegree_Queue;
	std::vector<int> *pNodeArray = NULL;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	pNodeArray = this->nodeArray;

	//Initializing the auxiliary variables.
	indegreeVector.assign(this->size, 0);
	outputStore.clear();
	zeroIndegree_Queue.clear();

	//Making initial indegreevector.
	(*this).CalcInitialIndegree(pIndegreeVector);

	//Topological Sorting start.
	for (int i=0 ; i<indegreeVector.size() ; i++){
		if (indegreeVector[i] == 0){
			zeroIndegree_Queue.push_back(i);
			continue;
		}
	}

	while(zeroIndegree_Queue.empty() == 0){
		//visit check
		currentNode = (this->nodeArray)[*(zeroIndegree_Queue.begin())].begin();
		zeroIndegree_Queue.pop_front();
		outputStore.push_back(*currentNode);

		//Decreasing the indegree of successors and enqueuing to zero-indgree-queue.
		for (tempNode = pNodeArray[*currentNode].begin()+1 ; tempNode != pNodeArray[*currentNode].end() ; tempNode++){
			indegreeVector[*tempNode] -= 1;
			if (indegreeVector[*tempNode] == 0){
				zeroIndegree_Queue.push_back(*tempNode);
			}
		}
	}

	return this;
}
