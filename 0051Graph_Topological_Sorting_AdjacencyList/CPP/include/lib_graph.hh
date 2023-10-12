#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
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
	GRAPH *Print(void);
	GRAPH *TopologicalSorting(std::vector<int> &);
private:
	GRAPH *CalcInitialIndegree(std::vector<int> &);
};

#endif
