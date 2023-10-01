#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	(*this).nodeArray = NULL;
	(*this).size = -1;

	//Binding method functions
	(*this).CreateGraph = GRAPH_METHOD_CreateGraph;
	(*this).DestroyGraph = GRAPH_METHOD_DestroyGraph;
	(*this).AddEdge_Directed = GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = GRAPH_METHOD_AddEdge;
	(*this).Create_DFS_Buffer = GRAPH_METHOD_Create_DFS_Buffer;
	(*this).Release_DFS_Buffer = GRAPH_METHOD_Release_DFS_Buffer;
	(*this).DFS = GRAPH_METHOD_DFS;
	(*this).Print = GRAPH_METHOD_Print;

	return ;
}
void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	//When the graph is empty.
	if (this->nodeArray == NULL)
		return ;

	//When the graph exists(not empty).
	(*this).DestroyGraph(this);

	return ;
}

GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray != NULL){
		DEBUG("ERROR: 'this->nodeArray' is not NULL.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);

	//Filling the first element of each linked list.
	for (int i=0 ; i<sizeArg ; i++){
		(*this).nodeArray[i].node_id = i;
		(*this).nodeArray[i].prev = NULL;
		(*this).nodeArray[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{	
	GRAPH_NODE *tempNode = NULL;
	GRAPH_NODE *tempNextNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Destroying
	for (int i=0 ; i<this->size ; i++){
		tempNode = (*this).nodeArray + i;
		tempNode = tempNode->next;
		while(tempNode != NULL){
			tempNextNode = tempNode->next;
			free(tempNode);
			tempNode = tempNextNode;
		}
	}

	free(this->nodeArray);

	this->nodeArray = NULL;
	this->size = -1;
	
	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (nodeA >= (*this).size){
		DEBUG("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling4
	if (nodeB >= (*this).size){
		DEBUG("ERROR: nodeB >= size.\n");
		return NULL;
	}

	tempNode = (*this).nodeArray + nodeA;
	while (tempNode->next != NULL){
		tempNode = tempNode->next;
	}

	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	tempNode->next->node_id = nodeB;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB);
	(*this).AddEdge_Directed(this, nodeB, nodeA);

	return this;
}

int *GRAPH_METHOD_Create_DFS_Buffer(GRAPH *this)
{
	int *ret = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	ret = (int *)malloc(sizeof(int)*(this->size));
	memset(ret, 0, sizeof(int)*(this->size));

	return ret;
}

GRAPH *GRAPH_METHOD_Release_DFS_Buffer(GRAPH *this, int *bufferArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (bufferArg==NULL){
		DEBUG("ERROR: 'bufferArg' is NULL.\n");
		return NULL;
	}

	free(bufferArg);
	return this;
}

int DFS_SubFunc_Recursive
(GRAPH *this, int currentNode, char *visitVector, int *outputBuffer)
{
	GRAPH_NODE *arrayPointer = this->nodeArray;
	GRAPH_NODE *tempNode = NULL;

	//VisitChecking of the currentNode starts.
	if (visitVector[currentNode] != 0){
		//Exception Handling
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return -1;
	}

	visitVector[currentNode] = 2;
	for (int i=0 ; i<(this->size) ; i++){
		if (outputBuffer[i] != -1){
			continue;
		}

		outputBuffer[i] = currentNode;
		break;
	}
	//VisitChecking ends.
TESTBRANCH:
	//Finding the Univistied neighborhood node of current node.
	tempNode = arrayPointer + currentNode;
	tempNode = tempNode->next;
	while(tempNode!=NULL){
		if (visitVector[tempNode->node_id] != 0){
			//When the neighbor node is already visited before.
			tempNode = tempNode->next;
			continue;
		}

		//When the unvisited neighbor node is found.
		if (visitVector[tempNode->node_id] != 0){
			DEBUG("ERROR: Unexpected Situation occured.\n");
			return -1;
		}
		DFS_SubFunc_Recursive(this, tempNode->node_id, visitVector, outputBuffer);

		//When the procedure is popped from the stack.
goto TESTBRANCH;
		//tempNode = tempNode->next;
	}
	
	//When the tempNode == NULL. 
	//= When there is no any unvisited neighborhood node.
	//= It is a base case. 
	return 0;
}

GRAPH *GRAPH_METHOD_DFS(GRAPH *this, int *bufferArg)
{
	char *visitVector = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (bufferArg == NULL){
		DEBUG("ERROR: bufferArg is NULL.\n");
		return NULL;
	}

	//Clearing the output storage buffer
	for (int i=0 ; i<(*this).size ; i++){
		bufferArg[i] = -1;
	}

	//Creating visitVector
	visitVector = (char *)calloc(this->size, sizeof(char));
	
	DFS_SubFunc_Recursive(this, 0, visitVector, bufferArg);

	free(visitVector);
	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *nodeArray_Pointer = NULL;
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	nodeArray_Pointer = (*this).nodeArray;

	for (int i=0 ; i<(this->size) ; i++){
		printf("[Node]: %d [Edge]: ", nodeArray_Pointer[i].node_id);
		tempNode = nodeArray_Pointer[i].next;
		while (tempNode != NULL){
			printf("%d ", tempNode->node_id);
			tempNode = tempNode->next;
		}
		printf("\n");
	}

	return this;
}
