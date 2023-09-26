#include "common.hh"
#include "lib_graph.hh"

#define VERSION1
//#define VERSION2

GRAPH::_GRAPH(void){
	(*this).nodeArray = NULL;
	(*this).size = -1;
	return ;
}

GRAPH::~_GRAPH(void){
	if ((*this).nodeArray==NULL){
		return ;
	}

	(*this).DestroyGraph();

	return ;
}


GRAPH *GRAPH::CreateGraph(int sizeArg)
{
	//Exception Handling
	if ((*this).nodeArray != NULL){
		DEBUG<<"ERROR: Graph already exists. Destroy it first."<<std::endl;
		return NULL;
	}

	//Exception Handling2
	if (sizeArg<1){
		DEBUG<<"ERROR: sizeArg<1. sizeArg must be at least 1."<<std::endl;
		return NULL;
	}

	//Creating Graph
	(*this).size = sizeArg;
	(*this).nodeArray = new std::vector<int> [sizeArg];

	//Filling the first element of nodeArray
	for (int i=0 ; i<sizeArg ; i++){
		nodeArray[i].push_back(i);
	}

	return this;
}

GRAPH *GRAPH::DestroyGraph(void)
{
	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG<<"ERROR: Graph already doesn't exist."<<std::endl;
		return NULL;
	}

	delete[] (*this).nodeArray;
	(*this).size = -1;
	(*this).nodeArray = NULL;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG<<"ERROR: Graph doesn't exist. Create the graph first."<<std::endl;
		return NULL;
	}

	//Exception Handing2
	if (nodeA >= (*this).size){
		DEBUG<<"ERROR: nodeA >= graphSize"<<std::endl;
		return NULL;
	}

	//Exception Handling3
	if (nodeB >= (*this).size){
		DEBUG<<"ERROR: nodeB >= graphSize"<<std::endl;
	}

	(*this).nodeArray[nodeA].push_back(nodeB);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	if ((*this).AddEdge_Directed(nodeA, nodeB) == NULL){
		DEBUG<<"ERROR: Edge ("<<nodeA<<"->("<<nodeB<<" creation failed."<<std::endl;
		return NULL;
	}

	if ((*this).AddEdge_Directed(nodeB, nodeA) == NULL){
		DEBUG<<"ERROR: Edge ("<<nodeB<<"->("<<nodeA<<" creation failed."<<std::endl;
		return NULL;
	}

	return this;
}

GRAPH *GRAPH::BFS(std::vector<int> &BFSresult)
{
#ifdef VERSION1
	std::deque<std::vector<int>::iterator> BFS_Queue;
	std::vector<int> dummy;
	std::vector<int>::iterator currentNode = dummy.end();
	std::vector<int>::iterator tempNode = dummy.end();
	std::vector<char> visitVector((*this).size, 0);

	//Exception Handling.
	if (this->nodeArray == NULL){
		DEBUG<<"ERROR: 'this->nodeArray' is NULL. Create the graph first."<<std::endl;
		return NULL;
	}

	//Output Storage Clear
	BFSresult.clear();

	//BFS Start.
	currentNode = (*this).nodeArray[0].begin();
	BFS_Queue.push_back(currentNode);
	visitVector[*currentNode] = 1;

	while(1){
		if (BFS_Queue.empty() == 1)
			break;

		//Dequeueing.
		currentNode = *(BFS_Queue.begin());
		currentNode = ((*this).nodeArray[*currentNode]).begin();//This must be done.
		BFS_Queue.pop_front();

		//Visit Check.
		visitVector[*currentNode] = 2;
		BFSresult.push_back(*currentNode);

		tempNode = currentNode;
		tempNode++;
		for( ; tempNode != (*this).nodeArray[*currentNode].end() ; tempNode++ ){
			if (visitVector[*tempNode] != 0)
				continue;

			//Enqueueing.
			BFS_Queue.push_back(tempNode);
			visitVector[*tempNode] = 1;
		}
	}

	return this;
#endif

#ifdef VERSION2
	std::deque<int> BFS_Queue;
	std::vector<int> visitVector((*this).size, 0);
	std::vector<int> *currentNode = NULL;
	std::vector<int> dummy;
	std::vector<int>::iterator tempNode = dummy.end();

	BFSresult.clear();

	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG<<"ERROR: nodeArray is NULL. Create the graph first." << std::endl;
		return NULL;
	}

	//BFS Start
	currentNode = (*this).nodeArray + 0;
	BFS_Queue.push_back(*(*currentNode).begin());
	visitVector[*(*currentNode).begin()] = 1;

	while(1){
		if (BFS_Queue.empty() == 1) //When the queue is empty.
			break;

		currentNode = (*this).nodeArray + (*(BFS_Queue.begin()));
		BFS_Queue.pop_front();
		visitVector[(*currentNode)[0]] = 2;
		BFSresult.push_back(*(currentNode->begin()));

		for (std::vector<int>::iterator i=((currentNode->begin()) + 1) ; i!=currentNode->end() ; i++){
			if (visitVector[*i] != 0){ //When the node is already visited or stored in the queue currently.
				continue;
			}

			BFS_Queue.push_back(*i);
			visitVector[*i] = 1;
		}
	}

	return this;
#endif
}

GRAPH *GRAPH::Print(void)
{
	std::vector<int> dummy;
	std::vector<int>::iterator edgePointer = dummy.end();

	//Exception Handling
	if ((*this).nodeArray == NULL){
		DEBUG<<"ERROR: Graph is not Created yet. Creat eh graph first."<<std::endl;
		return NULL;
	}

	for (int i=0 ; i<(*this).size ; i++){
		std::cout << "[Node]: " << (*this).nodeArray[i][0] << " [Edge]: " ;
		edgePointer = nodeArray[i].begin();
		edgePointer++; //Because the first element of each vector is a node, but noe an edge.
		for( ; edgePointer!=nodeArray[i].end() ; edgePointer++){
			std::cout << *edgePointer << " ";
		}
		std::cout << std::endl;
	}

	return this;
}
