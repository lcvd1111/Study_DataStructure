#include "lib_graph.hh"

GRAPH::_GRAPH(void)
{
	nodeArray = NULL;
	size = -1;
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (nodeArray == NULL){
		return ;
	}

	(*this).Destroy();
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if ((*this).nodeArray != NULL){
		DEBUG << "ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = new std::vector<int> [sizeArg];

	for (int i=0; i<sizeArg ; i++){
		(this->nodeArray)[i].push_back(i);
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if ((*this).nodeArray == NULL){
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
	if ((*this).nodeArray == NULL){
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

	(this->nodeArray)[nodeA].push_back(nodeB);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

int CalcPath(int nodeA, int nodeB, std::vector<int> &pathOutput, const std::vector<int> &departureVector)
{
	int length = 0;
	int tempNode = nodeB;
	std::deque<int> pathStack;

	pathStack.clear();

	while(tempNode != nodeA){
//DEBUG<<"tempNode: "<<tempNode<<std::endl;
		pathStack.push_back(tempNode);
		tempNode = departureVector[tempNode];
		length++;
	}
	pathStack.push_back(tempNode);

	while(pathStack.empty() == 0){
		pathOutput.push_back(*(pathStack.end()-1));
		pathStack.pop_back();
	}
	
	return length;
}
int GRAPH::ShortestPath_BFS(int nodeA, int nodeB, std::vector<int> &outputStorage)
{
	std::vector<int> dummy({});
	std::vector<int>::iterator currentNode = dummy.end();
	std::vector<int>::iterator tempNode = dummy.end();
	std::vector<char> visitVector({});
	std::vector<int> departureVector({});
	std::deque<std::vector<int>::iterator> bfs_Queue;
	int loopCtl = 0;
	int ret;

	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return -1;
	}

	//Exception Handling2
	if (nodeA >= this->size){
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return -2;
	}

	//Exception Handling3
	if (nodeB >= this->size){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
		return -3;
	}

	//Clearing the Output Storage and Creating the visitVector, departureVector.
	outputStorage.clear();
	visitVector.assign((this->size), 0);
	departureVector.assign((this->size), -1);

	//BFS start.
	bfs_Queue.clear();
	currentNode = (this->nodeArray)[nodeA].begin();

	bfs_Queue.push_back(currentNode);
	visitVector[*currentNode] = 1;
	departureVector[*currentNode] = -1;

	loopCtl = 1;
	while(loopCtl){
		if (bfs_Queue.empty()){
			return -1;
		}
		
		//Visit Checking
		currentNode = *(bfs_Queue.begin());
		bfs_Queue.pop_front();
		currentNode = (this->nodeArray)[*currentNode].begin();
		visitVector[*currentNode] = 1;

		//Traversing neighborhoods
		tempNode = currentNode + 1;
		for ( ; tempNode != (this->nodeArray)[*currentNode].end() ; tempNode++){
			if (visitVector[*tempNode] != 0){
				//When the neighborhood is already visited or currently in queue.
				continue;
			}
			if (visitVector[*tempNode] == 0){
				//Unvisited Neighbor found.
//DEBUG<<"Enqueued: "<<*tempNode<<std::endl;
				bfs_Queue.push_back(tempNode);
				visitVector[*tempNode] = 1;
				departureVector[*tempNode] = *currentNode;

				//When the departure is found.
				if (*tempNode == nodeB){
//DEBUG<<"Departure Found: "<<*tempNode<<std::endl;
					ret = CalcPath(nodeA, nodeB, outputStorage, departureVector);
					loopCtl = 0;
					break;
				}
			}
		}

	}

	return ret;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
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
