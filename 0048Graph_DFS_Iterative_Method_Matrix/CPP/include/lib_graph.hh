#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type definitions and declarations
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
	GRAPH *AddEdge_Directed(int, int);
	GRAPH *AddEdge(int, int);
	GRAPH *Print(void);
	GRAPH *DFS_1(std::vector<int> &);
	GRAPH *DFS_2(std::vector<int> &);
};

#endif
