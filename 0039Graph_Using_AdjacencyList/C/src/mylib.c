#include "mylib.h"

//Function Definitions
GRAPH Constructor_Graph(GRAPH *self, long int sizeArg)
{
	GRAPH ret;
	if (self == NULL) //When the return value is exploited.
	{
		ret.maxSize = sizeArg;
		ret.currentSize = 0;
		ret.currentLastIndex = 0;
		ret.vertexList = (GRAPH_NODE **)malloc(sizeof(GRAPH_NODE *) * sizeArg);
		
		for (int i=0 ; i<sizeArg ; i++){
			ret.vertexList[i] = NULL;
		}
		
		ret.ReturnIndex = *Method_ReturnIndex;
		ret.ReturnDegree = *Method_ReturnDegree; 
		ret.AddVertex = *Method_AddVertex;
		ret.AddEdge = *Method_AddEdge;
		ret.DeleteVertex = *Method_DeleteVertex;
		ret.DeleteEdge = *Method_DeleteEdge;

		return ret;
	}

	//When the side effect is exploited.
	self->maxSize = sizeArg;
	self->currentSize = 0;
	self->currentLastIndex = -1;
	self->vertexList = (GRAPH_NODE **)malloc(sizeof(GRAPH_NODE *) * sizeArg);
	
	for (int i=0 ; i<sizeArg ; i++){
			(self->vertexList)[i] = NULL;
	}

	self->ReturnIndex = *Method_ReturnIndex;
	self->ReturnDegree = *Method_ReturnDegree; 
	self->AddVertex = *Method_AddVertex;
	self->AddEdge = *Method_AddEdge;
	self->DeleteVertex = *Method_DeleteVertex;
	self->DeleteEdge = *Method_DeleteEdge;

	return *self;
}

int Destructor_Graph(GRAPH *self)
{
	return 0;
}

long int Method_ReturnIndex(GRAPH *self, char *dataArg)
{
	int ret=0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->ver is NULL.\n");
		return -1;
	}

	//Simple Linear Search Bruteforce through the vertex list.
	for (int i=0 ; i<=(self->currentLastIndex) ; i++){
		 if ((self->vertexList)[i] == NULL)
			 continue;

		 if (strcmp((self->vertexList)[i]->data, dataArg) == 0){
			 return i;
		 }
	}

	//When there is no element in the current list.
	return -9999;
}	

int Method_ReturnDegree(GRAPH *self, long int indexArg)
{
	return 0;
}

GRAPH *Method_AddVertex(GRAPH *self, char *dataArg)
{
	GRAPH_NODE **tempList = NULL;
	long int error = 0;
	long int index = 0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->vertexList is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	////When the inputted node name already exists in the graph.
	if ((error = (self->ReturnIndex)(self, dataArg)) >= 0){
		return NULL;
	}

	//Exception Handling4
	if (error != -9999){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return NULL;
	}

	//When the graph is full currently.
	if (self->currentSize == self->maxSize){
		return NULL;
	}

	tempList = self->vertexList;

	//Finding the empty index of the list.
	index = self->currentLastIndex+1;
	for (int i=0; i<=(self->currentLastIndex) ; i++){
		if (tempList[i] == NULL){
			index = i;
			break;
		}
	}
	if (index == self->currentLastIndex+1){
		(self->currentLastIndex) += 1;
	} //Finding the empty index comepleted.

	tempList[index] = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	strncpy(tempList[index]->data, dataArg, STRING_LEN);
	tempList[index]->next = NULL;
	tempList[index]->prev = NULL;

	self->currentSize += 1;

	return self;
}

GRAPH *Method_AddEdge(GRAPH *self, long int originIndex, long int destIndex)
{
	GRAPH_NODE **tempList = NULL;
	char dataA[STRING_LEN] = {0,};
	char dataB[STRING_LEN] = {0,};
	GRAPH_NODE *tempNode = NULL;
	//Exception Handling
	if (self == NULL){
		DEBUG("self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("self->bertexList is NULL.\n");
		return NULL;
	}

	tempList = self->vertexList;

	//Exception Handling3
	if (tempList[originIndex] == NULL){
		DEBUG("tempList[originIndex] is NULL.\n");
		return NULL;
	}
	
	//Exception Handling4
	if (tempList[destIndex] == NULL){
		DEBUG("tempList[destIndex] is NULL.\n");
		return NULL;
	}

	strncpy(dataA, tempList[originIndex]->data, STRING_LEN);
	strncpy(dataB, tempList[destIndex]->data, STRING_LEN);

	//Checking whether edge already exists or not, and Creating an edge at the same time.
	tempNode = tempList[originIndex];
	while(1){
		if (strcmp(tempNode->data, dataB)==0){
			//When there already exsists an edge.
			if (tempNode != tempList[originIndex]){
				return NULL;
			}
		}
		if (tempNode->next == NULL){
			break;
		}
		tempNode = tempNode->next;
	}

	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	strncpy(tempNode->next->data, dataB, STRING_LEN);

	tempNode = tempList[destIndex];
	while(1){
		if (tempNode->next == NULL){
			break;
		}
		tempNode = tempNode->next;
	}
	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	strncpy(tempNode->next->data, dataA, STRING_LEN);

	return self;
}

GRAPH *Method_DeleteVertex(GRAPH *self, char *dataArg)
{
	long int vertexIndex = 0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->vertexList is NULL.\n");
		return NULL;
	}

	//When the Graph is empty currently.
	if (self->currentSize == 0){
		return NULL;
	}

	//Finding the index number;
	vertexIndex = (self->ReturnIndex)(self, dataArg);

	//When the vertex doesn't exist in the graph.
	if (vertexIndex == -9999){
		return NULL;
	}

	//Exception Handling
	if (vertexIndex < 0){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return NULL;
	}

	//Deleteing every edge which includes the dataArg
	for (int i=0 ; i<=self->currentLastIndex ; i++){
		if ((self->vertexList)[i] == NULL){
			continue;
		}
		self->DeleteEdge(self, i, vertexIndex);
	}

	//Exception Handling afting deleting every edge.
	if ((self->vertexList)[vertexIndex]->next != NULL){
		DEBUG("ERROR: Unexpected Situatoin Occured.\n");
		return NULL;
	}

	free((self->vertexList)[vertexIndex]);
	(self->vertexList)[vertexIndex] = NULL;
	
	//Changing the parameter properly.
	self->currentSize -= 1;
	if (vertexIndex == self->currentLastIndex){
		for (long int i=vertexIndex ; i>=-1 ; i--){
			if ((self->vertexList)[i] == NULL){
				continue;
			}
			else{
				self->currentLastIndex = i;
				break;
			}
		}
	}

	if (self->currentLastIndex == -1){
		//Exception Handling.
		//In this sitaution, Graph must be completely empty.
		if (self->currentSize != 0){
			DEBUG("ERROR: Unexpected Sitaution Occured.\n");
			return NULL;
		}
	}

	return self;
}

GRAPH *Method_DeleteEdge(GRAPH *self, long int originIndex, long int destIndex)
{
	GRAPH_NODE **tempArray = NULL;
	GRAPH_NODE *tempNode = NULL;
	char nameA[STRING_LEN] = {0,};
	char nameB[STRING_LEN] = {0,};

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->vertexList is NULL.\n");
		return NULL;
	}

	tempArray = self->vertexList;

	//Exception Handling3
	if (tempArray[originIndex] == NULL){
		DEBUG("ERROR: tempArray[originIndex] is NULL.\n");
		return NULL;
	}

	//Exception Handling4
	if (tempArray[destIndex] == NULL){
		DEBUG("ERROR: tempArray[destindex] is NULL.\n");
		return NULL;
	}

	strncpy(nameA, tempArray[originIndex]->data, STRING_LEN);
	strncpy(nameB, tempArray[destIndex]->data, STRING_LEN);

	//Finding the edge and Deleting it at the same time.
	tempNode = tempArray[originIndex];
	while(tempNode != NULL){
		if (strcmp(tempNode->data, nameB) == 0){
			if (tempNode != tempArray[originIndex]){
				break;
			}
		}
		tempNode = tempNode->next;
	}
	if (tempNode == NULL){
		//When the Edge doesn't exist.
		return NULL;
	}

	tempNode->prev->next = tempNode->next;
	if (tempNode->next != NULL){
		tempNode->next->prev = tempNode->prev;
	}
	else {
		;
	}
	free(tempNode);

	tempNode = tempArray[destIndex];
	while(tempNode != NULL){
		if (strcmp(tempNode->data, nameA) == 0)
		{
			if (tempNode != tempArray[destIndex]){
				break;
			}
		}
		tempNode = tempNode->next;
	}
	if (tempNode == NULL){
		DEBUG("ERROR: Unexpected Sitaution Occured.\n");
		return NULL;
	}

	tempNode->prev->next = tempNode->next;
	if (tempNode->next != NULL){
		tempNode->next->prev = tempNode->prev;
	}
	else {
		;
	}
	free(tempNode);

	return self;
}
