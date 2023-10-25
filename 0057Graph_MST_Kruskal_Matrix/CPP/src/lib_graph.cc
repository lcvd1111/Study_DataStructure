#include "lib_graph.hh"
#include "lib_unionfind.hh"

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

int GRAPH::Kruskal(GRAPH &outputStore)
{
	UNION_FIND kruskalUF;
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, HEAP_COMPARATOR> kruskalPQ;
	HEAP_NODE heapBufferNode;
	int **pMatrix = NULL;

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	//Initializing the objects and variables
	kruskalUF.Create(this->size);
	if (outputStore.matrix != NULL){
		outputStore.Destroy();
	}
	outputStore.Create(this->size);
	pMatrix = this->matrix;

	//Kruskal Algorithm Start.

	//Enqueuing every edeges into Prioirty-queue.
	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			if (pMatrix[i][j]==0){
				continue;
			}
			heapBufferNode.node_id = j;
			heapBufferNode.parent_node_id = i;
			heapBufferNode.weight = pMatrix[i][j];
			kruskalPQ.push(heapBufferNode);
		}
	}

	//Dequeueing every edges from Priority-queue and check redundancy using UF.
	while(kruskalPQ.empty() == 0){
		heapBufferNode = kruskalPQ.top();
		kruskalPQ.pop();

		//Check whether the dequeued edge is redundant or not.
		if (kruskalUF.Unite(heapBufferNode.parent_node_id, heapBufferNode.node_id) == NULL){
			//When the dequeued edge is redundant.
			continue;
		}
		//When the dequeued edge is not redundant. Add to MST.
		outputStore.AddEdge(heapBufferNode.parent_node_id, heapBufferNode.node_id, heapBufferNode.weight);
	}

	return 0;
}

bool HEAP_COMPARATOR::operator()(HEAP_NODE &nodeA, HEAP_NODE &nodeB)
{
	if (nodeA.weight >= nodeB.weight)
		return true;

	return false;
}
