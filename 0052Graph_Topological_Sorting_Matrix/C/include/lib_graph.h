#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"
#include "lib_queue.h"

//Type Definitions and Declarations.
typedef struct _GRAPH GRAPH;
struct _GRAPH {
	int **matrix;
	int size;

	//Methods
	GRAPH *(*Create)(GRAPH *, int sizeArg);
	GRAPH *(*Destroy)(GRAPH *);
	GRAPH *(*AddEdge_Directed)(GRAPH *, int nodeA, int nodeB);
	GRAPH *(*AddEdge)(GRAPH *, int nodeA, int nodeB);
	GRAPH *(*Print)(GRAPH *);
	GRAPH *(*TopologicalSorting)(GRAPH *, int *outputStore);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int sizeArg);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int nodeA, int nodeB);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int nodeA, int nodeB);
GRAPH *GRAPH_METHOD_Print(GRAPH *);
GRAPH *GRAPH_METHOD_TopologicalSorting(GRAPH *, int *outputStore);
int CalcIndegree(GRAPH *graphArg, int *indegreeStore);
#endif
