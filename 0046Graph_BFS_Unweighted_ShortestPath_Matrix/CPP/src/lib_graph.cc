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
	//Excpetion Hnadling.
	if (matrix != NULL){
		DEBUG<<"ERROR: this->matrix is not NULL."<<std::endl;
		return NULL;
	}

	//Exception Handling.
	if (sizeArg <= 1){
		DEBUG<<"ERROR: sizeArg <= 1"<<std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = new char *[sizeArg];

	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = new char [sizeArg];
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Excpetion Hnadling.
	if (matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		delete[] (this->matrix)[i];
	}

	delete[] this->matrix;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Excpetion Hnadling.
	if (matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	//Excetption Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= this->size"<<std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= this->size"<<std::endl;
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Excpetion Hnadling.
	if (matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

int GRAPH::CalcPath
(int nodeA, int nodeB, const std::vector<int> &departureVector, std::vector<int> &outputStore)
{
	int tempNode = nodeB;
	int length = 0;
	std::deque<int> tempStack;
	std::deque<int>::iterator buffer = tempStack.end();

	while(tempNode != nodeA){
		tempStack.push_back(tempNode);
		length++;
		tempNode = departureVector[tempNode];
	}
	tempStack.push_back(tempNode);

	while(tempStack.empty() == 0){
		buffer = tempStack.end();
		buffer--;
		outputStore.push_back(*buffer);
	}

	return length;
}

int GRAPH::ShortestPath(int nodeA, int nodeB, std::vector<int> &outputStore)
{
	std::deque<int> bfs_Queue;
	std::vector<char> visitVector;
	std::vector<int> departureVector;
	int currentNode = 0, tempNode = 0;
	int ret = 0;
	char **pMatrix = NULL;

	//Excpetion Hnadling.
	if (matrix == NULL){
		DEBUG<<"ERROR: this->matrix is NULL."<<std::endl;
		return -1;
	}

	//Excetption Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= this->size"<<std::endl;
		return -2;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= this->size"<<std::endl;
		return -3;
	}

	//Special Case Handling
	if (nodeA == nodeB){
		return 0;
	}

	//Creating auxiliary vectors and Clearing the outputStore
	pMatrix = this->matrix;
	visitVector.assign((this->size), 0);
	departureVector.assign((this->size), 0);
	bfs_Queue.clear();
	outputStore.clear();

	//BFS start
	currentNode = nodeA;
	bfs_Queue.push_back(currentNode);
	visitVector[currentNode] = 1;
	departureVector[currentNode] = -1;
	
	while(1){
		if (bfs_Queue.empty()){
			ret = -1;
			break;
		}

		//Dequeuing and Visit Check.
		currentNode = *(bfs_Queue.begin());
		bfs_Queue.pop_front();
		visitVector[currentNode] = 2;

		//Traversing neighborhoods
		tempNode = 0;
		for ( ; tempNode<this->size ; tempNode++){
			if (pMatrix[currentNode][tempNode] == 0){
				continue;
			}
			if (visitVector[tempNode] != 0){
				continue;
			}
			//Unvisited neighbor node is found! Enqueuing starts.
			bfs_Queue.push_back(tempNode);
			visitVector[tempNode] = 1;
			departureVector[tempNode] = currentNode;

			//When the destination is found
			if (tempNode == nodeB){
				ret = CalcPath(nodeA, nodeB, departureVector, outputStore);
				break;
			}
		}
	}

	return ret;
}
