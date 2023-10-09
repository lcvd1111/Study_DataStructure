#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	this->nodeArray = NULL;
	this->size = -1;

	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->nodeArray == NULL){
		return ;
	}

	(*this).Destroy();
	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	//Excetion Handling
	if (this->nodeArray != NULL){
		DEBUG << "ERROR: this->nodeArray is not NULL." << std::endl;
		return NULL;
	}

	//Excetion Handling2
	if (sizeArg < 1){
		DEBUG << "ERROR: sizeArg < 1." << std::endl;
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = new std::vector<int>[sizeArg];
	for (int i=0 ; i<sizeArg ; i++){
		(*this).nodeArray[i].push_back(i);
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->nodeArray == NULL){
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
	if (this->nodeArray == NULL){
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

	(*this).nodeArray[nodeA].push_back(nodeB);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB)
{
	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	(*this).AddEdge_Directed(nodeA, nodeB);
	(*this).AddEdge_Directed(nodeB, nodeA);

	return this;
}

GRAPH *GRAPH::Print(void)
{
	std::vector<int>::iterator tempNode;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		std::cout << "[Node]: " << (*this).nodeArray[i][0] << " [Edge]: ";
		tempNode = (*this).nodeArray[i].begin();
		tempNode++;
		while(tempNode != (*this).nodeArray[i].end()){
			std::cout << *tempNode << " ";
			tempNode ++;
		}
		std::cout << std::endl;
	}

	return this;
}

GRAPH *GRAPH::DFS_1(std::vector<int> &outputStore)
{
	std::deque<std::vector<int>::iterator> DFS_stack;
	std::vector<char> visitVector;
	std::vector<int>::iterator currentNode, tempNode;
	std::vector<int> *pNodeArray = NULL;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Clearing the outputStore vector and creating the visitVector
	outputStore.clear();
	visitVector.assign(this->size, 0);
	pNodeArray = this->nodeArray;

	//DFS start
	currentNode = pNodeArray[0].begin();

	DFS_stack.push_back(currentNode);
	visitVector[*currentNode] = 1;

	while(1){
		if (DFS_stack.empty() == 1){
			break;
		}

		//Popping the stack and visitCheck.
		currentNode = *(DFS_stack.end()-1);
		currentNode = pNodeArray[*currentNode].begin();
		DFS_stack.pop_back();
		visitVector[*currentNode] = 2;
		outputStore.push_back(*currentNode);

		//Pushing the every unvisited neighbors.
		tempNode = currentNode + 1;
		while(tempNode != pNodeArray[*currentNode].end()){
			if (visitVector[*tempNode] == 0){
				DFS_stack.push_back(tempNode);
				visitVector[*tempNode] = 1;
			}
			tempNode++;
		}
	}

	return this;
}

GRAPH *GRAPH::DFS_2(std::vector<int> &outputStore)
{
	std::vector<int>::iterator currentNode, tempNode;
	std::vector<char> visitVector;
	std::deque<std::vector<int>::iterator> dfs_Stack;
	std::vector<int> *pNodeArray = NULL;
	int loopCtl1=0, loopCtl2=0;

	//Exception Handling
	if (this->nodeArray == NULL){
		DEBUG << "ERROR: this->nodeArray is NULL." << std::endl;
		return NULL;
	}

	//Clearing and Creating auxiliary objects.
	outputStore.clear();
	visitVector.assign(this->size, 0);
	dfs_Stack.clear();
	pNodeArray = this->nodeArray;

	//DFS start.
	currentNode = pNodeArray[0].begin();

	loopCtl1 = 1;
	while(loopCtl1){
		//Visit Checking.
		visitVector[*currentNode] = 2;
		outputStore.push_back(*currentNode);

		//Finding unvisited neighbor.
		loopCtl2 = 1;
		while(loopCtl2){
			tempNode = pNodeArray[*currentNode].begin();
			tempNode++;
			while(tempNode != pNodeArray[*currentNode].end()){
				if (visitVector[*tempNode] != 0){
					//When the neighbor is already visited.
					tempNode++;
					continue;
				}
				//When the unvisited neighbor node is found.
				dfs_Stack.push_back(currentNode);
				currentNode = pNodeArray[*tempNode].begin();
				loopCtl2 = 0;
				break;
			}
			//When there is no more unvisited neighbor node.
			if (tempNode == pNodeArray[*currentNode].end()){
				if (dfs_Stack.empty() == 1){
					loopCtl2 = 0;
					loopCtl1 = 0;
					break;
				}
				currentNode = *(dfs_Stack.end() - 1);
				currentNode = pNodeArray[*currentNode].begin();
				dfs_Stack.pop_back();
				continue;
			}
		}
	}

	return this;
}
