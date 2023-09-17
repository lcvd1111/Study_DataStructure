#include "mylib.hh"

GRAPH *GRAPH::AddVertex(const std::string &nameArg)
{
	std::set<std::string> newEdgeSet;
	newEdgeSet.clear();

	//If there already exists a vertex whose name is 'nameArg'.
	if ((*this).nodeSet.find(nameArg) != (*this).nodeSet.end())
		return NULL;

	(*this).nodeSet.insert(std::pair<std::string, std::set<std::string>> (nameArg, newEdgeSet));

	return this;
}

GRAPH *GRAPH::AddEdge(const std::string &nameA, const std::string &nameB)
{
	std::map<std::string, std::set<std::string>>::iterator nodeA_Pointer = (*this).nodeSet.end();
	std::map<std::string, std::set<std::string>>::iterator nodeB_Pointer = (*this).nodeSet.end();

	//Exception Handling: When the graph is empty currently.
	if ((*this).nodeSet.size() == 0)
		return NULL;

	nodeA_Pointer = (*this).nodeSet.find(nameA);
	//When the node with nameA doesn't exist in the graph
	if (nodeA_Pointer == (*this).nodeSet.end())
		return NULL;

	nodeB_Pointer = (*this).nodeSet.find(nameB);
	//When the node with nameB doesn't exist in the graph
	if (nodeB_Pointer == (*this).nodeSet.end())
		return NULL;

	//When the nodeB exists in the edgeSet of nodeA.
	if ((*nodeA_Pointer).second.find(nameB) != (*nodeA_Pointer).second.end())
		return NULL;

	//When the nodeA exists in the edgeSet of nodeB.
	if ((*nodeB_Pointer).second.find(nameB) != (*nodeB_Pointer).second.end())
		return NULL;

	(*nodeA_Pointer).second.insert(nameB);

	//When nameA == nameB
	if (nameA == nameB)
		return this;

	//When nameA != nameB
	(*nodeB_Pointer).second.insert(nameA);
	
	return this;
}

void GRAPH::Print(void)
{
	for (std::map<std::string, std::set<std::string>>::iterator i=(*this).nodeSet.begin() ; i!=(*this).nodeSet.end() ; i++){
		std::cout << "[Vertex]: " << (*i).first << " [Edges]: ";
		for (std::set<std::string>::iterator j=(*i).second.begin() ; j!= (*i).second.end() ; j++){
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}
}
