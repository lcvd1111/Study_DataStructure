#include "lib_graph.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	this->matrix = NULL;
	this->size = -1;

	//Binding Method functions
	this->CreateGraph = &GRAPH_METHOD_CreateGraph;
	this->DestroyGraph = &GRAPH_METHOD_DestroyGraph;
	this->AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = &GRAPH_METHOD_AddEdge;
	this->Create_DFS_Buffer = &GRAPH_METHOD_Create_DFS_Buffer;
	this->Release_DFS_Buffer = &GRAPH_METHOD_Release_DFS_Buffer;
	this->DFS = &GRAPH_METHOD_DFS;
	this->Print = &GRAPH_METHOD_Print;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	if (this->matrix == NULL)
		return ;

	(*this).DestroyGraph(this);

	return ;
}

GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix != NULL){
		DEBUG("ERROR: this->matrix is not NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	this->matrix = (int **)malloc(sizeof(int *)*sizeArg);
	this->size = sizeArg;

	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = (int *)malloc(sizeof(int)*sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			(*this).matrix[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{
	int **pMatrix = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	pMatrix = this->matrix;

	for (int i=0 ; i<(this->size) ; i++){
		free(pMatrix[i]);
	}

	free(pMatrix);

	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if(nodeA >= this->size){
		DEBUG("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling4
	if(nodeB >= this->size){
		DEBUG("ERROR: nodeB >= size.\n");
		return NULL;
	}

	(*this).matrix[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
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
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	ret = (int *)malloc(sizeof(int)*(this->size));

	return ret;
}

GRAPH *GRAPH_METHOD_Release_DFS_Buffer(GRAPH *this, int *bufferArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (bufferArg == NULL){
		DEBUG("ERROR: bufferArg is NULL.\n");
		return NULL;
	}

	free(bufferArg);

	return this;
}

int DFS_Recursive(GRAPH *this, int nextNode, char *visitVector, int *bufferArg, int *indexArg)
{
	int currentNode = nextNode;
	int tempNode = 0;
	int **pMatrix = this->matrix;

	//DFS Start
	visitVector[currentNode] = 2;
	bufferArg[*indexArg] = currentNode;
	*indexArg = (*indexArg)+1;

	for (tempNode=0 ; tempNode<(this->size) ; tempNode++){
		if (pMatrix[currentNode][tempNode] == 0){
			continue;
		}
		if (pMatrix[currentNode][tempNode] == 1 && visitVector[tempNode] != 0){
			continue;
		}
		if (pMatrix[currentNode][tempNode] == 1 && visitVector[tempNode] == 0){
			//Current Status is being pushed to call stack.
			if (DFS_Recursive(this, tempNode, visitVector, bufferArg, indexArg)){DEBUG("ERROR\n");}
			//After being Popped from call stack. Backtracking completed.
		}
	}

	/* When there is no more unvisited neighborhood of current node.
	  -> It is a base case.
	  -> The function must terminates here.
	  -> Pop(ProcessFunctionCallStack)
	  -> Backtracking.*/
	if (tempNode != this->size){
		DEBUG("ERROR: Unexpected Situation Occrued.\n");
		return -1;
	}
	return 0;
}

GRAPH *GRAPH_METHOD_DFS(GRAPH *this, int *bufferArg)
{
	char *visitVector = NULL;
	int index = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	visitVector = (char *)calloc(this->size, sizeof(char));

	if(DFS_Recursive(this, 0, visitVector, bufferArg, &index)){DEBUG("ERROR\n");}

	free(visitVector);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			printf("%d ", (*this).matrix[i][j]);
		}
		printf("\n");
	}

	return this;
}
