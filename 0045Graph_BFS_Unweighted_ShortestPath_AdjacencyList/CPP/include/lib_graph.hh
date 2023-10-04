#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type definitions and declarations
typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	std::vector<int> *nodeArray;
	int size;

	//Methods
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int);
	GRAPH *AddEdge(int, int);
	int ShortestPath_BFS(int, int, std::vector<int> &);
	GRAPH *Print(void);
};

#endif
