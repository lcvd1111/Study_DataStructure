#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH_NODE GRAPH_NODE;
typedef class _GRAPH GRAPH;
typedef class _HEAP_NODE HEAP_NODE;

class _GRAPH_NODE {
public:
	int node_id;
	int weight;
};

class _GRAPH {
private:
	std::vector<std::vector<GRAPH_NODE>> nodeVector;
	int size;

public:
	//Method Functions
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int, int);
	GRAPH *AddEdge(int, int, int);
	int Weight(void);
	GRAPH *Print(void);
	int Dijkstra(int);
};

//Below class and struct are used in priority queue for Kruskal Algorithm
class _HEAP_NODE {
public:
	int node_id;
	int parent_node_id;
	int distance_from_departure;
};

struct CUSTOM_COMPARATOR {
	bool operator()(HEAP_NODE &, HEAP_NODE &);
};

#endif
