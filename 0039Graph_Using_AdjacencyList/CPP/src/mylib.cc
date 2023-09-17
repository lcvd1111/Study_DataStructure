#include "mylib.hh"

//Methods Definitinos for GRAPH_USING_VECTOR
V_GRAPH::__GRAPH_USING_VECTOR__(void)
{
	return ;
}

V_GRAPH *V_GRAPH::AddVertex
(const std::string &nameArg)
{
	V_GRAPH_NODE newNode;

	//When the graph is empty.
	if ((this->nodeList).size() == 0){
		newNode.name = nameArg;
		(this->nodeList).push_back(newNode);
		return this;
	}

	//When the graph already has a inputted vertex
	for (std::vector<V_GRAPH_NODE>::iterator i=(this->nodeList).begin() ; i!=(this->nodeList).end() ; i++){
		if (i->name == nameArg){
			return NULL;
		}
	}

	//When the graph doesn't have a inputted vertex
	newNode.name = nameArg;
	(this->nodeList).push_back(newNode);

	return this;
}

V_GRAPH *V_GRAPH::AddEdge
(const std::string &name1, const std::string &name2)
{
	std::vector<V_GRAPH_NODE>::iterator nodeA_Pointer = (this->nodeList).end();
	std::vector<V_GRAPH_NODE>::iterator nodeB_Pointer = (this->nodeList).end();

	//When the graph is empty.
	if ((this->nodeList).size() == 0)
		return NULL;

	//Finding the pointer(iterator) of node with name1.
	for (std::vector<V_GRAPH_NODE>::iterator i=(this->nodeList).begin() ; i!=(this->nodeList).end() ; i++){
		if (i->name == name1){
			nodeA_Pointer = i;
			break;
		}
	}

	//When the node with name 1 doesn't exist in the graph.
	if (nodeA_Pointer == (this->nodeList).end())
		return NULL;

	//Finding the pointer(iterator) of node with name2.
	for (std::vector<V_GRAPH_NODE>::iterator i=(this->nodeList).begin() ; i!=(this->nodeList).end() ; i++){
		if (i->name == name2){
			nodeB_Pointer = i;
			break;
		}
	}

	//When the node with name 2 doesn't exist in the graph.
	if (nodeB_Pointer == (this->nodeList).end())
		return NULL;

	//When the Edge already exists.
	if (std::find((*nodeA_Pointer).edgeList.begin(), (*nodeA_Pointer).edgeList.end(), name2) != (*nodeA_Pointer).edgeList.end()){
		return NULL;
	}

	(nodeA_Pointer->edgeList).push_back(name2);

	//When name1==name2. In this case you don't need to Add second Edge at all.
	if (name1 == name2)
		return this;

	(nodeB_Pointer->edgeList).push_back(name1);

	return this;
}

V_GRAPH *V_GRAPH::DeleteVertex
(const std::string &nameArg)
{
	std::vector<V_GRAPH_NODE>::iterator node_Pointer = (*this).nodeList.end();

	//When the Graph is empty or has only an element.
	if ((*this).nodeList.size() == 0)
		return NULL;

	//Finding the iterator(Pointer) of node with given name.
	for (std::vector<V_GRAPH_NODE>::iterator i=(*this).nodeList.begin() ; i!=(*this).nodeList.end() ; i++){
		if (i->name == nameArg){
			node_Pointer = i;
			break;
		}
	}

	//If there is no vertex with given name.
	if (node_Pointer == (*this).nodeList.end()){
		return NULL;
	}

	//Deleting every edge incident with the vertex with given name.
	for (std::vector<V_GRAPH_NODE>::iterator i=(*this).nodeList.begin() ; i!=(*this).nodeList.end() ; i++){
		(*this).DeleteEdge(i->name, nameArg);
	}

	//Exception Handling
	if ((node_Pointer->edgeList).size() != 0){
		DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;
		return NULL;
	}

	//Deleting the node itself.
	(*this).nodeList.erase(node_Pointer);

	return this;
}

V_GRAPH *V_GRAPH::DeleteEdge
(const std::string &name1, const std::string &name2)
{
	std::vector<V_GRAPH_NODE>::iterator nodeA_Pointer = (this->nodeList).end();
	std::vector<V_GRAPH_NODE>::iterator nodeB_Pointer = (this->nodeList).end();
	std::vector<std::string> dummy;
	std::vector<std::string>::iterator edge1_Pointer = dummy.end();
	std::vector<std::string>::iterator edge2_Pointer = dummy.end();

	//Exception Handling: When the graph is empty.
	if ((this->nodeList).size() == 0)
		return NULL;

	//Finding the iterator(Pointer) of node with name1
	for (std::vector<V_GRAPH_NODE>::iterator i=(*this).nodeList.begin() ; i!=(*this).nodeList.end() ; i++){
		if (i->name == name1){
			nodeA_Pointer = i;
			break;
		}
	}
	//When the node with name1 doesn't exist in the Graph.
	if (nodeA_Pointer == (*this).nodeList.end()){
		return NULL;
	}

	//Finding the iterator(Pointer) of node with name2
	for (std::vector<V_GRAPH_NODE>::iterator i=(*this).nodeList.begin() ; i!=(*this).nodeList.end() ; i++){
		if (i->name == name2){
			nodeB_Pointer = i;
			break;
		}
	}

	//When the node with name2 doesn't exist in the Graph.
	if (nodeB_Pointer == (*this).nodeList.end()){
		return NULL;
	}

	//Finding the edge1 iterator(Pointer).
	edge1_Pointer = std::find((*nodeA_Pointer).edgeList.begin(), (*nodeA_Pointer).edgeList.end(), name2);

	//When the Edge doesn't exist.
	if (edge1_Pointer == (*nodeA_Pointer).edgeList.end()){
		return NULL;
	}

	//Deleting the edge1.
	(*nodeA_Pointer).edgeList.erase(edge1_Pointer);

	//When the name1 == name2. In this case, you don't need to remove 2nd edge.
	if (name1 == name2)
		return this;

	//Finding the edge2 iterator(Pointer).
	edge2_Pointer = std::find((*nodeB_Pointer).edgeList.begin(), (*nodeB_Pointer).edgeList.end(), name1);

	//Deleting the edge2.
	(*nodeB_Pointer).edgeList.erase(edge2_Pointer);

	return this;
}

void V_GRAPH::Print(void)
{
	for (std::vector<V_GRAPH_NODE>::iterator i=(*this).nodeList.begin() ; i!=(*this).nodeList.end() ; i++){
		std::cout << "[Vertex] " << (*i).name << " [Edges] " ;
		for (std::vector<std::string>::iterator j=(*i).edgeList.begin() ; j!=(*i).edgeList.end() ; j++){
			std::cout << *j << " " ;
		}
		std::cout << std::endl;
	}
	return ;
}


//Methods Definitions for GRAPH_USING_SET
S_GRAPH::__GRAPH_USING_SET__(void)
{
	return ;
}

S_GRAPH *S_GRAPH::AddVertex
(std::string nameArg)
{
	
	return this;
}

S_GRAPH *S_GRAPH::AddEdge
(std::string name1, std::string name2)
{
	return this;
}

S_GRAPH *S_GRAPH::DeleteVertex
(std::string nameArg)
{
	return this;
}

S_GRAPH *S_GRAPH::DeleteEdge
(std::string name1, std::string name2)
{
	return this;
}

void S_GRAPH::Print(void)
{
	return ;
}
