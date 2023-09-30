#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	(*this).size = -1;
	(*this).nodeArray = NULL;

	//Method Functions binding
	(*this).CreateGraph = GRAPH_METHOD_CreateGraph;
	(*this).DestroyGraph = GRAPH_METHOD_DestroyGraph;
	(*this).AddEdge_Directed = GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = GRAPH_METHOD_AddEdge;
	(*this).Create_DFS_Buffer = GRAPH_METHOD_Create_DFS_Buffer;
	(*this).Release_DFS_Buffer = GRAPH_METHOD_Release_DFS_Buffer;
	(*this).DFS_1 = GRAPH_METHOD_DFS_1;
	(*this).DFS_2 = GRAPH_METHOD_DFS_2;
	(*this).Print = GRAPH_METHOD_Print;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	//When the graph is empty.
	if (this->nodeArray == NULL){
		return ;
	}

	//When the graph is not empty.
	(*this).DestroyGraph(this);

	return ;
}

GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray != NULL){
		DEBUG("ERROR: 'this->nodeArray' is not Null. Destroy the graph first.\n");
		return NULL;
	}

	(*this).size = sizeArg;
	(*this).nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);

	//Filling the first element of each linked list.
	for (int i=0; i<sizeArg; i++){
		(*this).nodeArray[i].node_id = i;
		(*this).nodeArray[i].prev = NULL;
		(*this).nodeArray[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{
	GRAPH_NODE *tempNode = NULL;
	GRAPH_NODE *tempNextNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	for (int i=0; i<(*this).size ; i++){
		tempNode = (*this).nodeArray + i;
		//First node of the each linked list must not be freed here.
		tempNode = tempNode->next;

		while(tempNode != NULL){
			tempNextNode = tempNode->next;
			free(tempNode);
			tempNode = tempNextNode;
		}
	}

	free ((*this).nodeArray);

	(*this).size = -1;
	(*this).nodeArray = NULL;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling4
	if (nodeB >= this->size){
		DEBUG("ERROR: nodeB >= size.\n");
		return NULL;
	}

	tempNode = (*this).nodeArray + nodeA;
	
	while(tempNode->next != NULL){
		tempNode = tempNode->next;
	}

	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->node_id = nodeB;
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	(*this).AddEdge_Directed(this, nodeA, nodeB);
	(*this).AddEdge_Directed(this, nodeB, nodeA);

	return this;
}

int *GRAPH_METHOD_Create_DFS_Buffer(GRAPH *this)
{
	int *ret = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	ret = (int *)malloc(sizeof(int)*(this->size));
	return ret;
}

GRAPH *GRAPH_METHOD_Release_DFS_Buffer(GRAPH *this, int *bufferArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (bufferArg == NULL){
		DEBUG("ERROR: 'bufferArg' is NULL.\n");
		return NULL;
	}

	free(bufferArg);

	return this;
}

//DFS1 = DFS using the way of pushing 'Next Nodes'.
GRAPH *GRAPH_METHOD_DFS_1(GRAPH *this, int *bufferArg)
{
	char *visitVector = NULL;
	GRAPH_NODE *currentNode = NULL;
	GRAPH_NODE *tempNode = NULL;
	STACK dfs_Stack;
	STACK_CONSTRUCTOR(&dfs_Stack);
	int index = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (bufferArg == NULL){
		DEBUG("ERROR: 'bufferArg' is NULL.\n");
		return NULL;
	}

	//Creating visitVector
	visitVector = (char *)malloc(sizeof(char)*(this->size));
	memset(visitVector, 0, sizeof(char)*(this->size)); //This must be done.
	//위 statement로 visitvector 내부를 0으로 초기화 해주지 않으면, 어쩔 때는 에러가 나고 어쩔 때는 에러가 안나서 곤란해진다.

	//Clearing the outputStorage buffer
	memset(bufferArg, 0, sizeof(int)*(this->size));

	//DFS start.
	currentNode = (*this).nodeArray + 0;
	dfs_Stack.Push(&dfs_Stack, (void *)currentNode);
	visitVector[currentNode->node_id] = 1;

	while(1){
		if (dfs_Stack.Empty(&dfs_Stack) == 1){
			break;
		}

		//Dequeueing and visit check
		dfs_Stack.Pop(&dfs_Stack, (void *)(&currentNode));
		currentNode = (*this).nodeArray + (currentNode->node_id);
		visitVector[currentNode->node_id] = 2;
		bufferArg[index] = currentNode->node_id;
		index++;

		//Pushing the unvisited neighborhood nodes
		tempNode = currentNode;
		while(tempNode->next != NULL){
			tempNode = tempNode->next;
			if (visitVector[tempNode->node_id] == 0){
				dfs_Stack.Push(&dfs_Stack, (void *)tempNode);
				visitVector[tempNode->node_id] = 1;
			}
		}
	}

	//Removing visitVector
	free(visitVector);

	STACK_DESTRUCTOR(&dfs_Stack);
	return this;
}

//DFS2 = DFS using the way of pushing the 'Current(visited) Node'.
GRAPH *GRAPH_METHOD_DFS_2(GRAPH *this, int *bufferArg)
{
	char *visitVector = NULL;
	GRAPH_NODE *currentNode = NULL;
	GRAPH_NODE *tempNode = NULL;
	STACK dfs_Stack;
	STACK_CONSTRUCTOR(&dfs_Stack);
	int index = 0;
	int loopCtl_1 = 1, loopCtl_2 = 1;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (bufferArg == NULL){
		DEBUG("ERROR: 'bufferArg' is NULL.\n");
		return NULL;
	}

	//Creating visitVector
	visitVector = calloc(this->size, sizeof(char));

	//Clearing output storage buffer
	memset(bufferArg, 0, sizeof(int)*(this->size));

	//DFS start
	currentNode = this->nodeArray + 0;

	loopCtl_1 = 1;
	while (loopCtl_1){
		//Visit Check of the current Node.
		visitVector[currentNode->node_id] = 2;
		bufferArg[index] = currentNode->node_id;
		index++;

		//Trying moving to unvisited neighbor node.
		loopCtl_2 = 1;
		while(loopCtl_2){
			tempNode = currentNode->next;

			while(1){
				//When there is no unvisited neighbor node.
				if (tempNode == NULL){
					if (dfs_Stack.Empty(&dfs_Stack) == 1){
						loopCtl_1 = 0;
						loopCtl_2 = 0;
						break;
					}

					//Backtracking to already visited node.
					dfs_Stack.Pop(&dfs_Stack, (void *)&currentNode);
					break;
				}

				//When the neighborhood is already visited.
				if (visitVector[tempNode->node_id] != 0){
					tempNode = tempNode->next;
					continue;
				}

				//When the neighborhood is not visited yet.
				dfs_Stack.Push(&dfs_Stack, (void *)currentNode); //Storing the current state for backtracking in later time.
				currentNode = (*this).nodeArray + (tempNode->node_id); //Moving to new, unvisited node.
				loopCtl_2 = 0;
				break;
			}
		}
	}

	//Removing the visit vector
	free(visitVector);
	STACK_DESTRUCTOR(&dfs_Stack);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	for (int i=0; i<(*this).size ; i++){
		printf("[Node]: %d [Edge]: ", (*this).nodeArray[i].node_id);

		tempNode = (*this).nodeArray+i;
		tempNode = tempNode->next;
		while(tempNode != NULL){
			printf("%d ", tempNode->node_id);
			tempNode = tempNode->next;
		}
		printf("\n");
	}

	return this;
}
