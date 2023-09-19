#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//AddVertex(), DeleteVertex() interface is not implemented

//Type Definitions and Declarations
typedef struct _GRAPH GRAPH;

struct _GRAPH {
	char **matrix;
	int size;

	//Methods Declarations
	GRAPH *(*AddEdge)(GRAPH *this, size_t, size_t);
	GRAPH *(*DeleteEdge)(GRAPH *this, size_t, size_t);
	GRAPH *(*Print)(GRAPH *this);
};

//Functions for Methods Declarations
GRAPH Graph_Constructor(GRAPH *this, int);
void Graph_Destructor(GRAPH *this);
GRAPH *Method_Graph_AddEdge(GRAPH *this, size_t, size_t);
GRAPH *Method_Graph_DeleteEdge(GRAPH *this, size_t, size_t);
GRAPH *Method_Graph_Print(GRAPH *this);
#endif
