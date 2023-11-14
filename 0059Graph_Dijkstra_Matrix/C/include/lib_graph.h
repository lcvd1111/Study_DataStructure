#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _GRAPH GRAPH;

struct _GRAPH {
	int **matrix;
	int size;

	//Method Functions
	GRAPH *(*Create)(GRAPH *, int);
	GRAPH *(*Destroy)(GRAPH *);
	GRAPH *(*AddEdge_Directed)(GRAPH *, int, int, int);
	GRAPH *(*AddEdge)(GRAPH *, int, int, int);
	GRAPH *(*Print)(GRAPH *);
	GRAPH *(*Dijkstra)(GRAPH *);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int, int, int);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int, int, int);
GRAPH *GRAPH_METHOD_Print(GRAPH *);
GRAPH *GRAPH_METHOD_Dijkstra(GRAPH *);

#endif
