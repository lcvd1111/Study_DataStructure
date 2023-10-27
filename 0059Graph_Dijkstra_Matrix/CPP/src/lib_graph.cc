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
	std::vector<char> visitVector;
	std::vector<int> distanceVector, successorVector;
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, HEAP_COMPARATOR> dijkstraPQ;
	HEAP_NODE heapBuffer;
	int currentNode=0, parentNode=0;
	int **pMatrix = NULL;
	int loopCtl = 0;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	//Exception Handling
	if (departureArg >= (this->size)){
		DEBUG << "ERROR: departureArg >= size." << std::endl;
		return -2;
	}

	//Initializing the auxiliary variables and objects
	visitVector.assign((this->size), 0);
	distanceVector.assign((this->size), INT_MAX);
	successorVector.assign((this->size), -1);
	pMatrix = this->matrix;

	//Dijkstra Algorithm start
	currentNode = departureArg;
	parentNode = -1;
	distanceVector[currentNode] = 0;

	loopCtl = 1;
	while(loopCtl){
		visitVector[currentNode] = 1;
		successorVector[currentNode] = parentNode;

		//Traversing the neighborhoods of currentNode
		for (int tempNode=0 ; tempNode<(this->size) ; tempNode++){
			if (pMatrix[currentNode][tempNode] == 0){
				//When it is not a neighborhood
				continue;
			}
			if (visitVector[tempNode] == 1){
				//When the neighborhood is already visited before.
				continue;
			}
			if (distanceVector[tempNode] < (distanceVector[currentNode] + pMatrix[currentNode][tempNode]))
			{
				//When the better(shorter) path toward this neighborhood is already stored in PriorityQueue.
				continue;
			}
			//New proper fringe node is found. Enqueueing and Distance info updating.
			heapBuffer.node_id = tempNode;
			heapBuffer.parent_node_id = currentNode;
			heapBuffer.distance_from_departure = distanceVector[currentNode]+pMatrix[tempNode][currentNode];
			dijkstraPQ.push(heapBuffer);
			distanceVector[tempNode] = heapBuffer.distance_from_departure;
		}

		//Dequeueing form PriorityQueue.
		while(1){
			if (dijkstraPQ.empty() == 1){
				loopCtl = 0;
				break;
			}

			heapBuffer = dijkstraPQ.top();
			dijkstraPQ.pop();
			if (visitVector[heapBuffer.node_id] == 1){
				//When the dequeued node is already visited before.
				continue;
			}

			currentNode = heapBuffer.node_id;
			parentNode = heapBuffer.parent_node_id;
			break;
		}
	}

	for (int i=0 ; i<this->size ; i++){
		std::cout << "[" << departureArg << "->" << i << "] "
					<< "Distance: " << distanceVector[i]
					<< " Path: ";
		int temp = i;
		if (temp == departureArg){
			std::cout << std::endl;
			continue;
		}
		while (1){
			std::cout << temp << " ";
			if (temp == departureArg){
				break;
			}
			temp = successorVector[temp];
		}
		std::cout << std::endl;
	}

	return 0;
}

bool HEAP_COMPARATOR::operator()(HEAP_NODE &nodeA, HEAP_NODE &nodeB)
{
	if (nodeA.distance_from_departure >= nodeB.distance_from_departure)
		return true;

	return false;
}
