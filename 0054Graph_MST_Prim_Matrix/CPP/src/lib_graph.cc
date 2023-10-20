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
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if (this->matrix != NULL){
		DEBUG << "ERROR: (this->matrix) is not NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg is smaller than 1." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = new int* [sizeArg];

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
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
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
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
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

	(this->matrix)[nodeA][nodeB] = weightArg;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
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
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			std::cout << (this->matrix)[i][j] << " " ;
		}
		std::cout << std::endl;
	}

	return this;
}

int GRAPH::Weight(void) //It can be used only for undirected Graph.
{
	int ret = 0;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
		return -1;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=i ; j<(this->size) ; j++){
			ret += (this->matrix)[i][j];
		}
	}

	return ret;
}

GRAPH GRAPH::Prim(void)
{
	GRAPH ret;
	std::vector<char> mstVector({});
	std::vector<int> distanceVector({});
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, CUSTOM_COMPARATOR> fringeNodePQ;
	int currentNode=0, tempNode=0, parentNode=0;
	int **pMatrix = NULL;
	HEAP_NODE heapBufferNode = {.node_id=0, .parent_node_id=0, .weight=0};
	int loopCtl = 0;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: (this->matrix) is NULL." << std::endl;
		return ret;
	}

	//Initializing the auxiliary variables and objects
	mstVector.assign(this->size, 0);
	distanceVector.assign(this->size, INT_MAX);
	pMatrix = this->matrix;
	ret.Create(this->size);

	//Prim algorithm start.
	parentNode = -1;
	currentNode = 0;

	loopCtl = 1;
	while(loopCtl){
		//MST visit Check
		if (parentNode != -1){ 
			ret.AddEdge(parentNode, currentNode, pMatrix[parentNode][currentNode]);
		}
		mstVector[currentNode] = 1;
		distanceVector[currentNode] = 0;

		//Traversing the neighborhood
		for (tempNode=0 ; tempNode<(this->size) ; tempNode++){
			if (pMatrix[tempNode][currentNode] == 0){
				//When it is not a neighborhood.
				continue;
			}
			if (mstVector[tempNode] != 0){
				//When the neighborhood is already added in the MST.
				continue;
			}
			if (distanceVector[tempNode] < pMatrix[tempNode][currentNode]){
				//When the shorter connection toward the neighborhood already stored in the PQ currently.
				continue;
			}

			//Updating the distance information
			distanceVector[tempNode] = pMatrix[currentNode][tempNode];
			//Enqueueing the node and edge information to priority queue.
			heapBufferNode.node_id = tempNode;
			heapBufferNode.parent_node_id = currentNode;
			heapBufferNode.weight = pMatrix[currentNode][tempNode];
			fringeNodePQ.push(heapBufferNode);
		}

		//When the traversing is complete.
		while(1){
			if (fringeNodePQ.empty() == 1){
				loopCtl = 0;
				break;
			}

			currentNode = fringeNodePQ.top().node_id;
			parentNode = fringeNodePQ.top().parent_node_id;
			fringeNodePQ.pop();

			if (mstVector[currentNode] != 0){
				//Important.
				//When the dequeued node already is in the MST.
				//Then you should dequeue the another node from the priority queue.
				continue;
			}
			else {
				break;
			}
		}
	}

	return ret;
}

bool CUSTOM_COMPARATOR::operator()(HEAP_NODE argX, HEAP_NODE argY)
{
	if (argX.weight > argY.weight){
		return true;
	}
	else {
		return false;
	}
}
