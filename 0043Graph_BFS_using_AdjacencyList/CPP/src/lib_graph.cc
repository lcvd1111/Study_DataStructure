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
	std::deque<std::vector<int>::iterator> bfs_Queue;
	std::vector<char> visitVector;
	std::vector<int> dummy;
	std::vector<int>::iterator currentNode = dummy.end();
	std::vector<int>::iterator tempNode = dummy.end();

	//Exeption Handling
	if ((*this).nodeArray == NULL){
		DEBUG<<"ERROR: nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Create VisitVector
	for (int i=0; i<(*this).size ; i++){
		visitVector.push_back(0);
	}

	//Clearing the outputStorage
	BFSresult.clear();

	//BFS start
	currentNode = (*this).nodeArray[0].begin();
	bfs_Queue.push_back(currentNode);
	visitVector[*currentNode] = 1;

	while (1){
		if (bfs_Queue.empty() == 1){
			break;
		}

		//Dequeuing and Visit Check
		currentNode = *(bfs_Queue.begin());
		bfs_Queue.pop_front();
		currentNode = (*this).nodeArray[*currentNode].begin();
		visitVector[*currentNode] = 2;
		BFSresult.push_back(*currentNode);

		//Traversing the connected nodes of recently visitied node.
		tempNode = currentNode;
		tempNode++;
		for ( ; tempNode != (*this).nodeArray[*currentNode].end() ; tempNode++){
			if (visitVector[*tempNode] == 0){
				bfs_Queue.push_back(tempNode);
				visitVector[*tempNode] = 1;
			}
		}
	}

	return this;
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
