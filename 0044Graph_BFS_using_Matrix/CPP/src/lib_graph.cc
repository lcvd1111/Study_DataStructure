#include "common.hh"
#include "lib_graph.hh"

GRAPH::_GRAPH(void)
{
	matrix = NULL;
	size = -1;

	return ;
}

GRAPH::~_GRAPH(void)
{
	if (matrix != NULL){
		(*this).DestroyGraph();
	}

	return ;
}

GRAPH *GRAPH::CreateGraph(int sizeArg)
{
	//Exception Handing
	if (this->matrix != NULL){
		DEBUG << "ERROR: 'this->matrix' is not NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg < 1" << std::endl;
		return NULL;
	}

	(*this).size = sizeArg;
	(*this).matrix = new char *[sizeArg];

	
	for (int i=0; i<sizeArg ; i++){
		(*this).matrix[i] = new char [sizeArg];
		for (int j=0; j<sizeArg ; j++){
			(*this).matrix[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH::DestroyGraph(void)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		DEBUG << "ERROR: 'this->matrix' is NULL." << std::endl;
		return this;
	}

	for (int i=0; i<(*this).size ; i++){
		free ((*this).matrix[i]);
	}

	delete[] ((*this).matrix);

	(*this).matrix = NULL;
	(*this).size = -1;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		DEBUG << "ERROR: 'this->matrix' is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (*this).size){
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (*this).size){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(*this).matrix[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	AddEdge_Directed(nodeA, nodeB);
	AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		DEBUG << "ERROR: 'this->matrix' is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(*this).size ; i++){
		for (int j=0; j<(*this).size ; j++){
			std::cout << (int)((*this).matrix[i][j]) << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::BFS(std::vector<int> &bfsResult)
{
	char *visitVector = NULL;
	std::deque<int> bfs_Queue;
	int currentNode = 0;
	int tempNode = 0;

	if ((*this).matrix == NULL){
		DEBUG << "ERROR: (*this).matrix is NULL." << std::endl;
		return NULL;
	}

	//making visit vector
	visitVector = new char [(*this).size];
	memset(visitVector, 0, sizeof(char)*(*this).size);

	//BFS start
	currentNode = 0;
	
	bfs_Queue.push_back(currentNode);
	visitVector[currentNode] = 1;

	while(1) {
		//When the queue is empty.
		if (bfs_Queue.empty()){
			break;
		}
		
		//Visit Check.
		currentNode = *(bfs_Queue.begin());
		bfs_Queue.pop_front();
		visitVector[currentNode] = 2;
		bfsResult.push_back(currentNode);

		for (tempNode = 0 ; tempNode<(*this).size ; tempNode++){
			if (visitVector[tempNode]==0 && (*this).matrix[currentNode][tempNode]!=0){
				bfs_Queue.push_back(tempNode);
				visitVector[tempNode] = 1;
			}
		}
	}

	//deleting visit vector
	delete[] visitVector;

	return this;
}
