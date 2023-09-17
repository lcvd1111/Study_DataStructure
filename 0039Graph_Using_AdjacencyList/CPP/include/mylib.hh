#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define DEBUG std::cout<<"["<<__func__<<","<<__LINE__<<"] "

typedef class __GRAPH_USING_VECTOR__NODE__ V_GRAPH_NODE;
typedef class __GRAPH_USING_VECTOR__ V_GRAPH;
typedef class __GRAPH_USING_SET__NODE__ S_GRAPH_NODE;
typedef class __GRAPH_USING_SET__ S_GRAPH;

class __GRAPH_USING_VECTOR__NODE__ {
public:
	std::string name;
	std::vector<std::string> edgeList;
};

class __GRAPH_USING_VECTOR__ {
public:
	std::vector<V_GRAPH_NODE> nodeList;

	//Methods Declarations
	__GRAPH_USING_VECTOR__(void);
	V_GRAPH *AddVertex(const std::string &);
	V_GRAPH *AddEdge(const std::string &, const std::string &);
	V_GRAPH *DeleteVertex(const std::string &);
	V_GRAPH *DeleteEdge(const std::string &,const std::string &);
	void Print(void);
};

class __GRAPH_USING_SET__NODE__ {
public:
	std::string name;
	std::set<std::string> edgeList;
};

class __GRAPH_USING_SET__ {
public:
	std::map<std::string, S_GRAPH_NODE> nodeList;

	//Methods Declarations
	__GRAPH_USING_SET__(void);
	S_GRAPH *AddVertex(std::string);
	S_GRAPH *AddEdge(std::string, std::string);
	S_GRAPH *DeleteVertex(std::string);
	S_GRAPH *DeleteEdge(std::string, std::string);
	void Print(void);
};

#endif
