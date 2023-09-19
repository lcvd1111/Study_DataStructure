#include "mylib.h"

//AddVertex(), DeleteVertex() interface is not implemented

GRAPH Graph_Constructor(GRAPH *this, int sizeArg)
{
	GRAPH ret;

	//Exception Hanlding
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg < 1.\n");
		return ret;
	}

	//When the return value is exploited.
	if (this == NULL){
		ret.size = sizeArg;
		ret.matrix = (char **)malloc(sizeof(char *)*sizeArg);
		for (int i=0 ; i<sizeArg ; i++){
			ret.matrix[i] = (char *)malloc(sizeof(char)*sizeArg);
			for (int j=0; j<sizeArg ; j++){
				(ret.matrix)[i][j] = 0;
			}
		}

		ret.AddEdge = &Method_Graph_AddEdge;
		ret.DeleteEdge = &Method_Graph_DeleteEdge;
		ret.Print = &Method_Graph_Print;

		return ret;
	}
	
	//When the side effect is exploited.
	this->size = sizeArg;
	this->matrix = (char **)malloc(sizeof(char *)*sizeArg);
	for (int i=0; i<sizeArg ; i++){
		((*this).matrix)[i] = (char *)malloc(sizeof(char)*sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			((*this).matrix)[i][j] = 0;
		}
	}

	this->AddEdge = &Method_Graph_AddEdge;
	this->DeleteEdge = &Method_Graph_DeleteEdge;
	this->Print = &Method_Graph_Print;

	return *this;
}

void Graph_Destructor(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return;
	}

	for (int i=0 ; i<(*this).size ; i++){
		free((*this).matrix[i]);
	}

	free((*this).matrix);

	(*this).matrix = NULL;

	return;
}

GRAPH *Method_Graph_AddEdge(GRAPH *this, size_t row, size_t col)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Hanlding2
	if (row >= (*this).size){
		DEBUG("ERROR: row >= size.\n");
		return NULL;
	}

	//Exception Handling3
	if (col >= (*this).size){
		DEBUG("ERROR: col >= size. \n");
		return NULL;
	}

	//When the Edge already exists
	if (((*this).matrix)[row][col] == 1){
		return NULL;
	}

	//When the Edge doesn't exist.
	if (((*this).matrix)[row][col] == 0){
		((*this).matrix)[row][col] = 1;
		((*this).matrix)[col][row] = 1;
		return this;
	}

	//Exception Hanlindg
	DEBUG("ERROR: Unexpected Situation Occured\n");
	return NULL;
}

GRAPH *Method_Graph_DeleteEdge(GRAPH *this, size_t row, size_t col)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (row >= (*this).size){
		DEBUG("ERROR: row >= size\n");
		return NULL;
	}

	//Exception Handling3
	if (col >= (*this).size){
		DEBUG("ERROR: col >= size\n");
		return NULL;
	}

	//When the edge already doesn't exist.
	if (((*this).matrix)[row][col] == 0){
		return NULL;
	}

	//When the edge exists.
	if (((*this).matrix)[row][col] == 1){
		((*this).matrix)[row][col] = 0;
		((*this).matrix)[col][row] = 0;
		return this;
	}

	//Exception Hanlding
	DEBUG("ERROR: Unexpected Situation Occured.\n");
	return NULL;
}

GRAPH *Method_Graph_Print(GRAPH *this)
{
	//Exception Hanlding
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	for (int i=0; i<(*this).size ; i++){
		for (int j=0; j<(*this).size ; j++){
			printf("%d ", ((*this).matrix)[i][j]);
		}
		printf("\n");
	}

	return NULL;
}
