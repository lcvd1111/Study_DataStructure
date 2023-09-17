#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

#define DEBUG std::cout<<"["<<__func__<<","<<__LINE__<<"]"

typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	std::map<std::string, std::set<std::string>> nodeSet;

	//Methods
	GRAPH *AddVertex(const std::string &);
	GRAPH *AddEdge(const std::string &, const std::string &);
	void Print(void);
};

#endif
