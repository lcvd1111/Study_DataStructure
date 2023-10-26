#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	this->size = -1;
	(this->nodeVector).clear();
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->size == -1){
		return ;
	}

	(*this).Destroy();

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	std::vector<GRAPH_NODE> temp;
	GRAPH_NODE temp2;

	//Exception Handling
	if (this->size != -1){
		DEBUG<<"ERROR: Graph is not empty currently."<<std::endl;
		return NULL;
	}

	this->size = sizeArg;
	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeVector).push_back(temp);
		(this->nodeVector)[i].push_back(temp2);
		(this->nodeVector)[i][0].node_id = i;
		(this->nodeVector)[i][0].weight = 0;
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		(this->nodeVector)[i].clear();
	}
	(this->nodeVector).clear();

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB, int weightArg)
{
	GRAPH_NODE tempNode;

	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	tempNode.node_id = nodeB;
	tempNode.weight= weightArg;
	(this->nodeVector)[nodeA].push_back(tempNode);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(this->AddEdge_Directed)(nodeA, nodeB, weightArg);
	(this->AddEdge_Directed)(nodeB, nodeA, weightArg);

	return this;
}

int GRAPH::Weight(void)
{
	int ret = 0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	for (std::vector<std::vector<GRAPH_NODE>>::iterator i=(this->nodeVector).begin() ;
		i!=(this->nodeVector).end()	; i++)
	{
		for (std::vector<GRAPH_NODE>::iterator j=(i->begin)() ; j!=(i->end)() ; j++){
			ret += j->weight;
		}
	}

	return ret/2;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	for (std::vector<std::vector<GRAPH_NODE>>::iterator i = (this->nodeVector).begin()
			; i!=(this->nodeVector).end() ; i++)
	{
		std::cout << "[Node]: " << (*i)[0].node_id << " [Edge, Weight]: ";
		for (std::vector<GRAPH_NODE>::iterator j = (i->begin)() + 1 ; j!=(i->end)() ; j++){
			std::cout << "(" << j->node_id << "," << j->weight << ") ";
		}
		std::cout << std::endl;
	}

	return this;
}

int GRAPH::Dijkstra(int departureArg)
{
	std::vector<char> visitVector;
	std::vector<int> distanceVector, successorVector;
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, CUSTOM_COMPARATOR> dijkstraPQ;
	HEAP_NODE heapBuffer;
	std::vector<GRAPH_NODE>::iterator currentNode, parentNode;
	int loopCtl = 0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	//Initializing the auxiliary objects and variables.
	visitVector.assign(this->size, 0);
	distanceVector.assign(this->size, INT_MAX/2);
	successorVector.assign(this->size, -1);

	//Start Dijkstra Algorithm
	currentNode = (this->nodeVector)[departureArg].begin();

	loopCtl = 1;
	while(loopCtl){
		visitVector[currentNode->node_id] = 1;
		if (currentNode->node_id == departureArg){
			distanceVector[currentNode->node_id] = 0;
			successorVector[currentNode->node_id] = -1;
		}

		//Traversing every Neighborhood.
		for (std::vector<GRAPH_NODE>::iterator i=(this->nodeVector)[currentNode->node_id].begin() + 1
			; i!=(this->nodeVector)[currentNode->node_id].end()
			; i++)
		{
			if (visitVector[i->node_id] == 1){
				//When the neighbor is already visited before.
				continue;
			}

			if (distanceVector[i->node_id] < (distanceVector[currentNode->node_id] + (i->weight))){
				//When the better(shorter) path toward this neighbor node is already stored in priority queue.
				continue;
			}

			//Proper new fringe node is found. Not visited yet + The shortest path toward this neighbor is from the currentNode so far.
			//Enqueueing to PriorityQueue and Updating the distanceVector information.
			distanceVector[i->node_id] = distanceVector[currentNode->node_id] + (i->weight);
			successorVector[i->node_id] = currentNode->node_id;
			heapBuffer.node_id = i->node_id;
			heapBuffer.parent_node_id = currentNode->node_id;
			heapBuffer.distance_from_departure = distanceVector[i->node_id];
			dijkstraPQ.push(heapBuffer);
		}

		//Dequeuing from Priority queue.
		while(1){
			if (dijkstraPQ.empty() == 1){
				loopCtl = 0;
				break;
			}
			heapBuffer = dijkstraPQ.top();
			dijkstraPQ.pop();

			//When the dequeued node is already visited
			if (visitVector[heapBuffer.node_id] == 1){
				//You must dequeue again.
				continue;
			}

			currentNode = (this->nodeVector)[heapBuffer.node_id].begin();
			parentNode = (this->nodeVector)[heapBuffer.parent_node_id].begin();
			successorVector[currentNode->node_id] = parentNode->node_id;
			distanceVector[currentNode->node_id] = heapBuffer.distance_from_departure;
			break;
		}
	}

	for (int i=0; i<this->size ; i++){
		std::cout << departureArg << "->" << i 
			<< " Distance: " << distanceVector[i]
			<< ", Path: ";
		int temp = i;
		while(1){
			if (i==departureArg){
				break;
			}
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

bool CUSTOM_COMPARATOR::operator()(HEAP_NODE &argX, HEAP_NODE &argY)
{
	if (argX.distance_from_departure >= argY.distance_from_departure)
		return true;

	return false;
}
