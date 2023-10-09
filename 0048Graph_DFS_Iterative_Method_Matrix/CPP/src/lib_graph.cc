#include "lib_graph.hh"

GRAPH::_GRAPH(void)
{
	this->matrix = NULL;
	this->size = -1;
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (matrix == NULL){
		return ;
	}

	(this->Destroy)();
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Exception Handling
	if (this->matrix != NULL){
		DEBUG << "ERROR: matrix is not NULL." << std::endl;
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
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		delete[] (this->matrix)[i];
	}

	delete[] (this->matrix);
	
	this->size = -1;
	this->matrix = NULL;

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (nodeA>=this->size){
		DEBUG << "ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (nodeB>=this->size){
		DEBUG << "ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			std::cout << (this->matrix)[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::DFS_1(std::vector<int> &outputStore)
{
	int currentNode=0, tempNode=0;
	std::vector<char> visitVector;
	std::deque<int> dfs_Stack;
	int **pMatrix = NULL;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	//Initializing the auxiliary objects
	outputStore.clear();
	visitVector.assign(this->size, 0);
	dfs_Stack.clear();
	pMatrix = this->matrix;

	//DFS starts.
	currentNode = 0;
	visitVector[currentNode] = 1;
	dfs_Stack.push_back(currentNode);

	while(1){
		if (dfs_Stack.empty() == 1){
			break;
		}

		//Popping the stack and visit check.
		currentNode = *(dfs_Stack.end()-1);
		dfs_Stack.pop_back();
		visitVector[currentNode] = 2;
		outputStore.push_back(currentNode);

		//Pushing every unvisited neighbors.
		for (tempNode=0 ; tempNode<this->size ; tempNode++){
			if (pMatrix[currentNode][tempNode] == 0){
				continue;
			}
			if (visitVector[tempNode] != 0){
				//When the neighbor is already visited or currently in stack.
				continue;
			}
			//Unvistied neighbor is found.
			dfs_Stack.push_back(tempNode);
			visitVector[tempNode] = 1;
		}
	}
	return this;
}

GRAPH *GRAPH::DFS_2(std::vector<int> &outputStore)
{
	int currentNode=0, tempNode=0;
	int **pMatrix = NULL;
	std::vector<char> visitVector;
	std::deque<int> dfs_Stack;
	int loopCtl1=0, loopCtl2=0;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: matrix is NULL." << std::endl;
		return NULL;
	}

	//Initializing the auxiliary objects
	outputStore.clear();
	pMatrix = this->matrix;
	visitVector.assign(this->size, 0);
	dfs_Stack.clear();

	//DFS starts.
	currentNode = 0;

	loopCtl1 = 1;
	while(loopCtl1){
		//Visit Check.
		visitVector[currentNode] = 2;
		outputStore.push_back(currentNode);

		loopCtl2 = 1;
		while(loopCtl2){
			//Finding Unvisited Neighbor
			for (tempNode=0 ; tempNode<(this->size) ; tempNode++){
				if (pMatrix[currentNode][tempNode] == 0){
					continue;
				}
				if (visitVector[tempNode] != 0){
					continue;
				}
				//Unvisited neighbor is found.
				dfs_Stack.push_back(currentNode); //Storing the current status for back-tracking in later time.
				currentNode = tempNode;
				loopCtl2 = 0;
				break;
			}

			if (tempNode == (this->size)){
				//When there is no more unvisited node.
				if (dfs_Stack.empty()==1){
					loopCtl2 = 0;
					loopCtl1 = 0;
					break;
				}
				//Back-tracking.
				currentNode = *(dfs_Stack.end()-1);
				dfs_Stack.pop_back();
				continue;
			}
		}
	}

	return this;
}
