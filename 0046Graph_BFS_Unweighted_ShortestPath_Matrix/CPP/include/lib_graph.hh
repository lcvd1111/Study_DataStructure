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
	GRAPH *Create(int sizeArg);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int);
	GRAPH *AddEdge(int, int);
	int ShortestPath(int, int, std::vector<int> &outputStore);
private:
	int CalcPath(int , int, const std::vector<int> &, std::vector<int> &);
};

#endif
