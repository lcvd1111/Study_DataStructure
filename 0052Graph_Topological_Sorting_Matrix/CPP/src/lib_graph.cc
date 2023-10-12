#include "lib_graph.hh"

GRAPH::_GRAPH(void)
{
	this->matrix = NULL;
	this->size = -1;

	return;
}

GRAPH::~_GRAPH(void)
{
	if (this->matrix == NULL){
		return ;
	}

	(*this).Destroy();

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	if (this->matrix != NULL){
		DEBUG<<"ERROR: this->matrix is not NULL." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = new int*[sizeArg];
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
	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		delete[] (this->matrix)[i];
	}
	delete[] (this->matrix);
	
	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
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

GRAPH *GRAPH::TopologicalSorting(std::vector<int> &outputStore)
{
	std::vector<int> indegreeVector;
	std::vector<int> &pIndegreeVector = indegreeVector;
	std::deque<int> zeroIndegreeQueue;
	int currentNode=0, tempNode=0;
	int **pMatrix = NULL;

	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	//Initializing the auxiliary variables.
	(*this).CalcInitialIndegree(pIndegreeVector);
	outputStore.clear();
	zeroIndegreeQueue.clear();
	pMatrix = this->matrix;

	//Topological Sorting Start
	for (std::vector<int>::iterator i=indegreeVector.begin() ; i!=indegreeVector.end() ; i++){
		if (*i == 0){
			zeroIndegreeQueue.push_back((int)(i-indegreeVector.begin()));
		}
	}

	while(zeroIndegreeQueue.empty() == 0){
		//Dequeuing and visitcheck
		currentNode = *(zeroIndegreeQueue.begin());
		outputStore.push_back(currentNode);
		zeroIndegreeQueue.pop_front();

		//Decrementing the indegree value of successors and Enqueueing
		for ( tempNode=0 ; tempNode<this->size ; tempNode++){
			if (pMatrix[currentNode][tempNode] == 1){
				indegreeVector[tempNode] -= 1;
				if (indegreeVector[tempNode] == 0){
					zeroIndegreeQueue.push_back(tempNode);
				}
			}
		}
	}

	return this;
}

GRAPH *GRAPH::CalcInitialIndegree(std::vector<int> &indegreeVector)
{
	if (this->matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	indegreeVector.assign(this->size, 0);

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			if ((this->matrix)[i][j] == 1){
				indegreeVector[j] += 1;
			}
		}
	}

	return this;
}
