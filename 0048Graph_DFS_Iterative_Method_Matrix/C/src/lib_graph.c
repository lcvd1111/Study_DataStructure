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
	this->DFS_1 = &GRAPH_METHOD_DFS_1;
	this->DFS_2 = &GRAPH_METHOD_DFS_2;
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

GRAPH *GRAPH_METHOD_DFS_1(GRAPH *this, int *bufferArg)
{
	char *visitVector = NULL;
	int currentNode = 0;
	int tempNode = 0;
	STACK dfs_Stack;
	STACK_CONSTRUCTOR(&dfs_Stack);
	int **pMatrix = NULL;
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

	//Exception Handling3
	if (bufferArg == NULL){
		DEBUG("ERROR: bufferArg is NULL.\n");
		return NULL;
	}

	pMatrix = this->matrix;

	//Creating visitVector
	visitVector = (char *)malloc(sizeof(char)*(this->size));
	memset(visitVector, 0, sizeof(char)*(this->size));

	//Clearing the output buffer
	for (int i=0; i<this->size ; i++){
		bufferArg[i] = -1;
	}

	//DFS start.
	currentNode = 0;

	dfs_Stack.Push(&dfs_Stack, currentNode);
	visitVector[currentNode] = 1;

	while(1){
		if (dfs_Stack.Empty(&dfs_Stack)){
			break;
		}

		//Dequeueing and visit check.
		dfs_Stack.Pop(&dfs_Stack, &currentNode);
		visitVector[currentNode] = 2;
		bufferArg[index++] = currentNode;

		//Traversing neighborhoods.
		tempNode = 0;
		for ( ; tempNode < this->size ; tempNode ++){
			if (pMatrix[currentNode][tempNode] == 0){
				continue;
			}

			if (pMatrix[currentNode][tempNode] == 1 && visitVector[tempNode] != 0){
				//When the neighborhood is already visited or stored in stack currently.
				continue;
			}

			if (pMatrix[currentNode][tempNode] == 1 && visitVector[tempNode] == 0){
				//Pushing the unvisited neighborhood.
				dfs_Stack.Push(&dfs_Stack, tempNode);
				visitVector[tempNode] = 1;
			}
		}
	}

	//Destroying visitVector, dfs_Stack.
	free(visitVector);
	STACK_DESTRUCTOR(&dfs_Stack);

	return this;
}

GRAPH *GRAPH_METHOD_DFS_2(GRAPH *this, int *bufferArg)
{
	int **pMatrix = NULL;
	char *visitVector = NULL;
	int currentNode = 0;
	int tempNode = 0;
	STACK dfs_Stack;
	STACK_CONSTRUCTOR(&dfs_Stack);
	int index = 0;
	int loopCtl1=0, loopCtl2=0;

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

	//Creating visitVector and Clearing the output buffer
	visitVector = (char *)malloc(sizeof(char)*(this->size));
	memset(visitVector, 0, sizeof(char)*(this->size));
	for (int i=0; i<this->size ; i++){
		bufferArg[i] = -1;
	}

	//DFS start
	currentNode = 0;

	loopCtl1 = 1;
	while(loopCtl1){
		//Visit Check.
		visitVector[currentNode] = 2;
		bufferArg[index++] = currentNode;

		loopCtl2 = 1;
		while(loopCtl2){
			//Neighbor Traversing starts.
			for (tempNode=0 ; tempNode<(this->size) ; tempNode++){
				if (pMatrix[currentNode][tempNode] == 0){
					continue;
				}
				if (pMatrix[currentNode][tempNode]==1 && visitVector[tempNode] != 0){
					//When the neighbor is already visited before.
					continue;
				}
				if (pMatrix[currentNode][tempNode]==1 && visitVector[tempNode] == 0){ 
					//Unvisited neighbor is found.
					dfs_Stack.Push(&dfs_Stack, currentNode); //Pushing current status in stack for back-trakcing in later.
					currentNode = tempNode; //Moving to unvisited neighbor node.
					loopCtl2 = 0;
					break; //It must goes to the first statement of the first while loop.
				}
			}

			//When there is no more unvisitied neighbor from the current node.
			if (tempNode == this->size){
				if (dfs_Stack.Empty(&dfs_Stack)){
					loopCtl1 = 0;
					break;
				}
				dfs_Stack.Pop(&dfs_Stack, &currentNode);//Back-tracking
			}
		}
	}

	//Destroying the visitVector, dfs_Stack
	free(visitVector);
	STACK_DESTRUCTOR(&dfs_Stack);

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
