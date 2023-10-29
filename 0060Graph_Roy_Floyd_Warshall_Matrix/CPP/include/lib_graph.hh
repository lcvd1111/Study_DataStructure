#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	int **matrix;
	int size;

	//Methods
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int, int);
	GRAPH *AddEdge(int, int, int);
	GRAPH *Print(void);
	int FloydWarshall(GRAPH &);
};

#endif
