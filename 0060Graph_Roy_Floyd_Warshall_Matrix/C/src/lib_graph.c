#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->matrix = NULL;
	this->size = 0;

	//Binding Method Functions
	this->Create = &GRAPH_METHOD_Create;
	this->Destroy = &GRAPH_METHOD_Destroy;
	this->AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = &GRAPH_METHOD_AddEdge;
	this->Print = &GRAPH_METHOD_Print;
	this->FloydWarshall = &GRAPH_METHOD_FloydWarshall;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->matrix == NULL){
		return ;
	}

	(*this).Destroy(this);

	return ;
}

GRAPH *GRAPH_METHOD_Create(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix != NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is already not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("ERROR: 'sizeArg' < 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = (int **)malloc(sizeof(int *)*sizeArg);
	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = (int *)calloc(sizeArg, sizeof(int));
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is already NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		free((this->matrix)[i]);
	}
	free(this->matrix);
	this->matrix = NULL;
	this->size = 0;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weight)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->size)){
		PRINTF_ERROR("ERROR: nodeA >= size\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		PRINTF_ERROR("ERROR: nodeB >= size\n");
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = weight;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weight)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}
	(*this).AddEdge_Directed(this, nodeA, nodeB, weight);
	(*this).AddEdge_Directed(this, nodeB, nodeA, weight);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			printf(COLOR_MAGENTA "%d ", (this->matrix)[i][j]);
		}
		printf("\n");
	}
	printf(COLOR_BLACK);

	return this;
}

GRAPH *GRAPH_METHOD_FloydWarshall(GRAPH *this)
{
	GRAPH distanceGraph;
	GRAPH successorGraph;
	GRAPH_CONSTRUCTOR(&distanceGraph);
	GRAPH_CONSTRUCTOR(&successorGraph);
	int **pMatrix = NULL; //Pointer to Matrix
	int **pDmatrix = NULL; //Pointeor to Distance Matrix.
	int **pPmatrix = NULL; //Pointer to Path Matrix.

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}


	//Initialzing the auxiliary variables and objects.
	pMatrix = this->matrix;
	distanceGraph.Create(&distanceGraph, this->size);
	successorGraph.Create(&successorGraph, this->size);

	for (int i=0; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			if (pMatrix[i][j] != 0 || (i==j)){
				distanceGraph.AddEdge_Directed(&distanceGraph, i, j, pMatrix[i][j]);
				successorGraph.AddEdge_Directed(&successorGraph, i, j, j);
			}
			else {
				distanceGraph.AddEdge_Directed(&distanceGraph, i, j, INT_MAX/4);
				successorGraph.AddEdge_Directed(&successorGraph, i, j, -1);
			}
		}
	}
	
	//Floyd Warshall Algorithm Starts.
	pDmatrix = distanceGraph.matrix;
	pPmatrix = successorGraph.matrix;

	for (int j=0 ; j<(this->size) ; j++){
		for (int i=0 ; i<(this->size) ; i++){
			for (int k=0 ; k<(this->size) ; k++){
				if (pDmatrix[i][k] > pDmatrix[i][j] + pDmatrix[j][k]){
					pDmatrix[i][k] = pDmatrix[i][j] + pDmatrix[j][k];
					pPmatrix[i][k] = pPmatrix[i][j];
				}
			}
		}
	}

	//Printing out the result.
	printf(COLOR_BLACK "<The original Given Graph>\n");
	(*this).Print(this);

	printf(COLOR_BLACK "\n<Shortest Path Distance Graph>\n");
	distanceGraph.Print(&distanceGraph);
	
	printf(COLOR_BLACK "\n<Path Graph>\n");
	successorGraph.Print(&successorGraph);

	//Destroying the auxiliary objects and variables
	distanceGraph.Destroy(&distanceGraph);
	successorGraph.Destroy(&successorGraph);
	GRAPH_DESTRUCTOR(&distanceGraph);
	GRAPH_DESTRUCTOR(&successorGraph);

	return this;
}
