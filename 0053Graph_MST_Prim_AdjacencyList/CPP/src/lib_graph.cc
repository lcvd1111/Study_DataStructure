#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	nodeArray = NULL;
	size = -1;
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->nodeArray == NULL){
		return ;
	}

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	NODE buffer = {.node_id=0, .weight=0};
	//Exception Handling
	if (this->nodeArray != NULL){
		DEBUG<<"ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG<<"ERROR: sizeArg is smaller than 1." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = new std::vector<NODE> [sizeArg];
	for (int i=0  ; i<sizeArg ; i++){
		buffer.node_id = i;
		buffer.weight = 0;
		(this->nodeArray)[i].push_back(buffer);
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

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB, int weightArg)
{
	NODE buffer = {.node_id=0, .weight=0};

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG << "ERROR: nodeA >= size" << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG << "ERROR: nodeB >= size" << std::endl;
		return NULL;
	}

	buffer.node_id = nodeB;
	buffer.weight = weightArg;
	(this->nodeArray)[nodeA].push_back(buffer);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB, int weightArg)
{
	(*this).AddEdge_Directed(nodeA, nodeB, weightArg);
	(*this).AddEdge_Directed(nodeB, nodeA, weightArg);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	std::vector<NODE> dummy;
	std::vector<NODE>::iterator tempNode = dummy.end();
	
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		std::cout << "[Node]: " << (this->nodeArray)[i][0].node_id << " [Edge, Weight]: ";
		for (tempNode = (this->nodeArray)[i].begin() + 1 ; tempNode != (this->nodeArray)[i].end() ; tempNode++){
			std::cout << "(" << tempNode->node_id << "," << tempNode->weight << ") " ;
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH GRAPH::Prim(void)
{
	GRAPH ret;
	std::vector<char> mstVector({});
	std::vector<int> distanceVector({});
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, CUSTOM_COMPARE> primPQ;
	NODE currentNode, tempNode;
	int parent_id = 0;
	HEAP_NODE heapBuffer;
	char loopCtl = 0;
	std::vector<NODE> *pNodeArray = NULL;

	//Exception Handling.
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return ret;
	}

	//Initializing the auxiliary variables and objects.
	mstVector.assign(this->size, 0);
	distanceVector.assign(this->size, INT_MAX);
	ret.Create(this->size);

	//Prim Algorithm Start.
	pNodeArray = this->nodeArray;
	currentNode = *(pNodeArray[0].begin());
	parent_id = -1;

	loopCtl = 1;
	while (loopCtl){
		////Visit Check to MST.
		mstVector[currentNode.node_id] = 1;
		distanceVector[currentNode.node_id] = 0;

		if (parent_id != -1){
			ret.AddEdge(parent_id, currentNode.node_id, currentNode.weight);
		}

		////Traversing the neighbors of the current node.
		for (std::vector<NODE>::iterator i = pNodeArray[currentNode.node_id].begin() + 1
				; i != pNodeArray[currentNode.node_id].end() ; i++){
			tempNode = *i;
			if (mstVector[tempNode.node_id] != 0){
				//When the neighbor is already added in the MST.
				continue;
			}
			if (distanceVector[tempNode.node_id] < tempNode.weight){
				//When the shorter edge toward this neighbor is already stored in priority queue.
				continue;
			}
			//Updating the distance information.
			distanceVector[tempNode.node_id] = tempNode.weight;

			//Enqueueing the node to priority queue.
			heapBuffer.parent_node_id = currentNode.node_id;
			heapBuffer.node_id = tempNode.node_id;
			heapBuffer.weight = tempNode.weight;
			primPQ.push(heapBuffer);
		}

		////When the traversing the neighbor is finished.
		while (1){
			//Dequeueing the graph node from the priority queue.
			if (primPQ.empty() == 1){
				loopCtl = 0;
				break;
			}

			heapBuffer = primPQ.top();
			primPQ.pop();
			if (mstVector[heapBuffer.node_id] == 1){
				continue;
			}
			currentNode.node_id = heapBuffer.node_id;
			currentNode.weight = heapBuffer.weight;
			parent_id = heapBuffer.parent_node_id;
			break;
		}
	}

	return ret;
}

int GRAPH::Weight(void)
{
	//Caution: It can be used only for Undirected Graph!
	int ret = 0;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: this->nodeArray is NULL." << std::endl;
		return -1;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (std::vector<NODE>::iterator j=(this->nodeArray)[i].begin() ; j!=(this->nodeArray)[i].end() ; j++){
			ret += j->weight;
		}
	}

	ret = ret / 2;

	return ret;
}

bool CUSTOM_COMPARE::operator()(HEAP_NODE argx, HEAP_NODE argy)
{
	if (argx.weight > argy.weight){
		return true;
	}
	else {
		return false;
	}
}
