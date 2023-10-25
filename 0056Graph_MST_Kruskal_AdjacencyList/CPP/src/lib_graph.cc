#include "lib_graph.hh"

//Function Definitions
GRAPH::_GRAPH(void)
{
	this->size = -1;
	(this->nodeVector).clear();
	return ;
}

GRAPH::~_GRAPH(void)
{
	if (this->size == -1){
		return ;
	}

	(*this).Destroy();

	return ;
}

GRAPH *GRAPH::Create(int sizeArg)
{
	std::vector<GRAPH_NODE> temp;
	GRAPH_NODE temp2;

	//Exception Handling
	if (this->size != -1){
		DEBUG<<"ERROR: Graph is not empty currently."<<std::endl;
		return NULL;
	}

	this->size = sizeArg;
	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeVector).push_back(temp);
		(this->nodeVector)[i].push_back(temp2);
		(this->nodeVector)[i][0].node_id = i;
		(this->nodeVector)[i][0].weight = 0;
	}

	return this;
}

GRAPH *GRAPH::Destroy(void)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		(this->nodeVector)[i].clear();
	}
	(this->nodeVector).clear();

	return this;
}

GRAPH *GRAPH::AddEdge_Directed(int nodeA, int nodeB, int weightArg)
{
	GRAPH_NODE tempNode;

	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	tempNode.node_id = nodeB;
	tempNode.weight= weightArg;
	(this->nodeVector)[nodeA].push_back(tempNode);

	return this;
}

GRAPH *GRAPH::AddEdge(int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG<<"ERROR: Graph is already empty." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		DEBUG<<"ERROR: nodeA >= size." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		DEBUG<<"ERROR: nodeB >= size." << std::endl;
		return NULL;
	}

	(this->AddEdge_Directed)(nodeA, nodeB, weightArg);
	(this->AddEdge_Directed)(nodeB, nodeA, weightArg);

	return this;
}

int GRAPH::Weight(void)
{
	int ret = 0;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	for (std::vector<std::vector<GRAPH_NODE>>::iterator i=(this->nodeVector).begin() ;
		i!=(this->nodeVector).end()	; i++)
	{
		for (std::vector<GRAPH_NODE>::iterator j=(i->begin)() ; j!=(i->end)() ; j++){
			ret += j->weight;
		}
	}

	return ret/2;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return NULL;
	}

	for (std::vector<std::vector<GRAPH_NODE>>::iterator i = (this->nodeVector).begin()
			; i!=(this->nodeVector).end() ; i++)
	{
		std::cout << "[Node]: " << (*i)[0].node_id << " [Edge, Weight]: ";
		for (std::vector<GRAPH_NODE>::iterator j = (i->begin)() + 1 ; j!=(i->end)() ; j++){
			std::cout << "(" << j->node_id << "," << j->weight << ") ";
		}
		std::cout << std::endl;
	}

	return this;
}

int GRAPH::Kruskal(GRAPH &outputStore)
{
	std::priority_queue<HEAP_NODE, std::vector<HEAP_NODE>, CUSTOM_COMPARATOR> kruskalPQ;
	HEAP_NODE bufferNode;
	UNION_FIND kruskalUF;

	//Exception Handling
	if (this->size == -1){
		DEBUG << "ERROR: Graph is empty currently." << std::endl;
		return -1;
	}

	//Clearing the outputStore
	if (outputStore.size != -1){
		outputStore.Destroy();
	}

	//Initializing the auxiliary variables and objects
	kruskalUF.Create(this->size);
	outputStore.Create(this->size);

	//Start Kruskal Algorithm
	for (std::vector<std::vector<GRAPH_NODE>>::iterator i=(*this).nodeVector.begin()
		; i!=(*this).nodeVector.end() ; i++)
	{
		for (std::vector<GRAPH_NODE>::iterator j=(i->begin)()
			; j!=(i->end)() ; j++)
		{
			if (j->node_id < ((i->begin)()->node_id)){
				continue;
			}
			bufferNode.parent_node_id = ((i->begin)())->node_id;
			bufferNode.node_id = j->node_id;
			bufferNode.weight = j->weight;
			kruskalPQ.push(bufferNode);
		}
	}

	while(kruskalPQ.empty() != 1){
		bufferNode = kruskalPQ.top();
		kruskalPQ.pop();

		if (kruskalUF.Unite(bufferNode.parent_node_id, bufferNode.node_id) == NULL){
			continue;
		}

		outputStore.AddEdge(bufferNode.parent_node_id, bufferNode.node_id, bufferNode.weight);
	}

	return 0;
}

bool CUSTOM_COMPARATOR::operator()(HEAP_NODE &argX, HEAP_NODE &argY)
{
	if (argX.weight >= argY.weight)
		return true;

	return false;
}
