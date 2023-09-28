#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	char **matrix;
	int size;

	//Methods
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *CreateGraph(int sizeArg);
	GRAPH *DestroyGraph(void);
	GRAPH *AddEdge_Directed(int, int);
	GRAPH *AddEdge(int, int);
	GRAPH *Print(void);
	GRAPH *BFS(std::vector<int> &bfsResult);
};

#endif
